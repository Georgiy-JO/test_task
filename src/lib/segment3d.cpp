#include "segment3d.h"

namespace geometry{

    void Segment3D::Set(const Vector3D& first, const Vector3D& second){
        start = first;
        end = second;
    }

    void Segment3D::Set(const Segment3D &segment_){
        start = segment_.start;
        end = segment_.end;
    }

    void Segment3D::SetStart(const Vector3D& first){
        start = first;
    }

    void Segment3D::SetEnd(const Vector3D& second){
        end = second;
    }

    std::pair<Vector3D, Vector3D> Segment3D::Get() const{
        return {start, end};
    }

    Vector3D Segment3D::GetStart() const{
        return start;
    }

    Vector3D Segment3D::GetEnd() const{
        return end;
    }
    Vector3D Segment3D::GetDirection() const{
        return end - start;
    }



}   //namespace geometry