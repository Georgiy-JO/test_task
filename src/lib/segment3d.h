#ifndef SRC_CORE_MATH_SEGMENT_3D_H
#define SRC_CORE_MATH_SEGMENT_3D_H

#include "vector3d.h"

namespace geometry{
class Segment3D
{
    public:
        constexpr Segment3D() = default;
        constexpr Segment3D(const Vector3D& first, const Vector3D& second) : start(first), end(second) {}
        constexpr Segment3D(const Segment3D &segment_) : start(segment_.start), end(segment_.end) {}
        ~Segment3D() = default;

        void Set(const Vector3D& first, const Vector3D& second);
        void Set(const Segment3D &segment_);
        void SetStart(const Vector3D& first);
        void SetEnd(const Vector3D& second);
        std::pair<Vector3D, Vector3D> Get() const;
        Vector3D GetStart() const;
        Vector3D GetEnd() const;
    
    private:
        Vector3D start;
        Vector3D end;
};

Vector3D Intersect(const Segment3D& segment_1, const Segment3D& segment_2);
std::tuple<double, double, double> IntersectValue(const Segment3D& segment_1, const Segment3D& segment_2);


}   //namespace geometry

#endif  // SRC_CORE_MATH_SEGMENT_3D_H