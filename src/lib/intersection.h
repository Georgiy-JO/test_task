
#ifndef SRC_CORE_MATH_INTERSECTION_H
#define SRC_CORE_MATH_INTERSECTION_H

#include "segment3d.h"
#include <exception>
#include <string>
#include <tuple>


namespace geometry{
    constexpr double kEpsilon = 1e-6;


    enum class IntersectionType{
        kIntersect=0,
        kOverlap=1,
        kNoIntersect=4
    };

    class OverlapError : public std::exception {
    public:
        OverlapError(const char* error = "Segments overlap.") : msg(error) {}
        OverlapError(const OverlapError& other) : msg(other.msg) {}
        const char* what() const noexcept override { return msg.c_str(); }
    private:
        std::string msg;
    };
    class ParallelError : public std::exception {
    public:
        ParallelError(const char* error = "Segments are parallel, but not collinear.") : msg(error) {}
        ParallelError(const ParallelError& other) : msg(other.msg) {}
        const char* what() const noexcept override { return msg.c_str(); }
    private:
        std::string msg;
    };
    class SkewError : public std::exception {
    public:
        SkewError(const char* error = "Segments are skew (not parallel and lie).") : msg(error) {}
        SkewError(const SkewError& other) : msg(other.msg) {}
        const char* what() const noexcept override { return msg.c_str(); }
    private:
        std::string msg;
    };
    class NoIntersectError : public std::exception {
    public:
        NoIntersectError(const char* error = "Segments do not intersect.") : msg(error) {}
        NoIntersectError(const NoIntersectError& other) : msg(other.msg) {}
        const char* what() const noexcept override { return msg.c_str(); }
    private:
        std::string msg;
    };


    Vector3D Intersect(const Segment3D& segment_1, const Segment3D& segment_2);
    std::tuple<double, double, double> IntersectValue(const Segment3D& segment_1, const Segment3D& segment_2);
    IntersectionType IntersectWrapper(const Segment3D& segment_1, const Segment3D& segment_2, Vector3D& intersection_point);


} //namespace geometry
#endif  // SRC_CORE_MATH_INTERSECTION_H