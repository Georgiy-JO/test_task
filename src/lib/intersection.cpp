
#include "intersection.h"


namespace geometry{
    Vector3D Intersect(const Segment3D& segment_1, const Segment3D& segment_2){
        
    }

    std::tuple<double, double, double> IntersectValue(const Segment3D& segment_1, const Segment3D& segment_2){
        return Intersect(segment_1, segment_2).Get();
    }

    IntersectionType IntersectWrapper(const Segment3D& segment_1, const Segment3D& segment_2, Vector3D& intersection_point){
        try{
            intersection_point= Intersect(segment_1, segment_2);
        }
        catch(const OverlapError& e){
            return IntersectionType::kOverlap;
        }
        catch(const ParallelError& e){
            return IntersectionType::kParallel;
        }
        catch(const SkewError& e){
            return IntersectionType::kSkew;
        }
        catch(const NoIntersectError& e){
            return IntersectionType::kNoIntersect;
        }
        return IntersectionType::kIntersect;
    }


} //namespace geometry