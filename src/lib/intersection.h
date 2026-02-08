
#ifndef SRC_CORE_MATH_INTERSECTION_H
#define SRC_CORE_MATH_INTERSECTION_H

#include "segment3d.h"
#include <exception>
#include <string>


namespace geometry{
    constexpr double kEpsilon = 1e-8;

    /**
     * @note Основные 3 случая касательно пересечения отрезков ("типы пересечения").
     */
    enum class IntersectionType{
        kIntersect=0,
        kOverlap=1,
        kNoIntersect=2
    };

    /**
     * @note OverlapError, ParallelError, SkewError, NoIntersectError (дочерние классы IntersectError) - 
     * особые классы ошибок для функции пересечения отрезков (мы считаем пересечение как норму, 
     * остальное - ошибка).
     */
    class IntersectError : public std::exception {
        public:
            IntersectError(const std::string error="Unknown Intersection Error.") : msg(error) {}
            IntersectError(const IntersectError& other) : msg(other.msg) {}
            const char* what() const noexcept override { return msg.c_str(); }
        protected:
            std::string msg;
    };
    /**
     * @note OverlapError в отличии от ParallelError, SkewError, NoIntersectError возвращает
     * не только текст ошибки, но также и значения зоны пересечения.
     */
    class OverlapError : public IntersectError {
    public:
        OverlapError(const Vector3D& begin, const Vector3D& end, std::string error = "Segments overlap.") : IntersectError(error), overlap_begin(begin), overlap_end(end){}
        OverlapError(const OverlapError& other) : IntersectError(other.msg), overlap_begin(other.overlap_begin), overlap_end(other.overlap_end) {}
        const std::pair<Vector3D, Vector3D> GetOverlap() const { return {overlap_begin, overlap_end}; }
    private:
        Vector3D overlap_begin;
        Vector3D overlap_end; 
    };
    class ParallelError : public IntersectError {
    public:
        ParallelError(const std::string error = "Segments are parallel, but not collinear.") : IntersectError(error) {}
        ParallelError(const ParallelError& other) : IntersectError(other.msg) {}
    };
    class SkewError : public IntersectError {
    public:
        SkewError(const std::string error = "Segments are skew (not parallel and lie in different planes).") : IntersectError(error) {}
        SkewError(const SkewError& other) : IntersectError(other.msg) {}
    };
    class NoIntersectError : public IntersectError {
    public:
        NoIntersectError(const std::string error = "Segments do not intersect.") : IntersectError(error) {}
        NoIntersectError(const NoIntersectError& other) : IntersectError(other.msg) {}
    };

    /**
     * @note Получает на ход 2 отрезка (сегмента), возвращает точку пересечения в формате Vector3D.
     * @exception Возвращает ошибки в случае наложения или отсутствия пересечения.
     */
    Vector3D Intersect(const Segment3D& segment_1, const Segment3D& segment_2);
    /**
     * @note Получает на ход 2 отрезка (сегмента), возвращает точку пересечения в формате Vec3 (упрощенный формат для 3D точки).
     * @exception Возвращает ошибки в случае наложения или отсутствия пересечения.
     */
    Vec3 IntersectVec3(const Segment3D& segment_1, const Segment3D& segment_2);
    /**
     * @note Получает на ход 2 отрезка (сегмента) и Vector3D в который будет записана точка пересечения,
     * возвращает "тип пересечения" в формате IntersectionType.
     * @note В случае наложения в intersection_point запишется начало наложения.
     */
    IntersectionType IntersectWrapper(const Segment3D& segment_1, const Segment3D& segment_2, Vector3D& intersection_point);

} //namespace geometry
#endif  // SRC_CORE_MATH_INTERSECTION_H