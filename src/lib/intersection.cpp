
#include "intersection.h"
#include <algorithm>
#include <cmath>


namespace geometry{
    Vector3D Intersect(const Segment3D& segment_1, const Segment3D& segment_2){
        Vector3D dir_1 = segment_1.GetEnd() - segment_1.GetStart();
        Vector3D dir_2 = segment_2.GetEnd() - segment_2.GetStart();
        Vector3D diff = segment_2.GetStart() - segment_1.GetStart();
        Vector3D cross_prod= dir_1 ^ dir_2;
        double cross_prod_norm_sq= cross_prod*cross_prod;    
        
        if(cross_prod_norm_sq < kEpsilon*kEpsilon){                             // parallel

            if((diff^dir_1).Length() >= kEpsilon)                   // not collinear
                throw ParallelError();
                                                                    // collinear
            double dir_1_norm_sq = dir_1*dir_1;
            double dir_2_norm_sq = dir_2*dir_2;

            if(dir_1_norm_sq<kEpsilon){
                double tmp =(dir_2_norm_sq<kEpsilon&&segment_1.GetStart()!=segment_2.GetStart())?-1:((segment_1.GetStart()-segment_2.GetStart())*dir_2)/dir_2_norm_sq;
                if(tmp<0 || tmp>1)
                    throw NoIntersectError();
                return segment_1.GetStart(); 
            }
            else{
                double seg_2_start_proj =diff*dir_1/dir_1_norm_sq;
                double seg_2_end_proj = (segment_2.GetEnd()-segment_1.GetStart())*dir_1/dir_1_norm_sq;
                double overlap_start = std::max(0.0,std::min(seg_2_start_proj, seg_2_end_proj));
                double overlap_end = std::min(1.0,std::max(seg_2_start_proj, seg_2_end_proj));
                if(overlap_start>overlap_end)
                    throw NoIntersectError();
                else if (overlap_start<overlap_end)
                    throw OverlapError(segment_1.GetStart()+dir_1*overlap_start, segment_1.GetStart()+dir_1*overlap_end);
                return segment_1.GetStart()+dir_1*overlap_start;  
            }
        }
        else{                                                       // not parallel
            if(std::abs(diff*cross_prod)>=kEpsilon*std::sqrt(cross_prod_norm_sq)) // not coplanar
                throw SkewError();
            // segment_1.GetStart() + t dir_1 = segment_2.GetStart() + s dir_2
            double t = (diff^dir_2)*cross_prod/cross_prod_norm_sq;
            Vector3D point = segment_1.GetStart() + dir_1*t;
            double s = (point-segment_2.GetStart())*dir_2/(dir_2*dir_2);
            if(s<0 || s>1 || t<0 || t>1)
                throw NoIntersectError();
            return point;
        }
    }

    Vec3 IntersectVec3(const Segment3D& segment_1, const Segment3D& segment_2){
        return Intersect(segment_1, segment_2).Get();
    }

    IntersectionType IntersectWrapper(const Segment3D& segment_1, const Segment3D& segment_2, Vector3D& intersection_point){
        try{
            intersection_point= Intersect(segment_1, segment_2);
        }
        catch(const OverlapError& e){
            intersection_point = e.GetOverlap().first;
            return IntersectionType::kOverlap;
        }
        catch(const std::exception& e){
            return IntersectionType::kNoIntersect;
        }
        return IntersectionType::kIntersect;
    }


} //namespace geometry