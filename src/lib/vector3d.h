#ifndef SRC_CORE_MATH_VECTOR_3D_H
#define SRC_CORE_MATH_VECTOR_3D_H
#include <array>

namespace geometry {

/**
 * @note Из условия задачи (см. task_2segments.doc) следует, что у Vector3D
 * поля x, y, z - приватные. Однако для получения данных о векторе нам удобно
 * иметь структуру также с параметрами x, y, z. В принципе можно заменить
 * x, y, z в Vector3D на эту структуру, но это противоречит условиям задания.
 */
struct Vec3 {
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
};

class Vector3D {
 public:
  constexpr Vector3D() = default;
  constexpr explicit Vector3D(double value) : x(value), y(value), z(value) {}
  constexpr Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
  constexpr Vector3D(const Vector3D &vec) : x(vec.x), y(vec.y), z(vec.z) {}
  ~Vector3D() = default;

  void Set(double x_, double y_, double z_);
  void Set(const Vector3D &vec);
  double Length() const;
  Vec3 Get() const;
  void Normalize();

  Vector3D operator*(double number) const;
  friend Vector3D operator*(double number, const Vector3D &vec);
  Vector3D &operator*=(double number);
  Vector3D operator-(const Vector3D &vec) const;
  Vector3D &operator-=(const Vector3D &vec);
  Vector3D operator+(const Vector3D &vec) const;
  Vector3D &operator+=(const Vector3D &vec);
  Vector3D &operator=(const Vector3D &vec);
  bool operator==(const Vector3D &vec) const;
  bool operator!=(const Vector3D &vec) const;

  /**
   * @brief Dot product (Скалярное произведение).
   */
  double operator*(const Vector3D &vec) const;
  /**
   * @brief Cross product (Векторное произведение).
   */
  Vector3D operator^(const Vector3D &vec) const;

 private:
  double x = 0.0f;
  double y = 0.0f;
  double z = 0.0f;
};

/**
 * @brief Mix product (Смешанное произведение).
 * @note a * (b x c)
 */
double MixProduct(const Vector3D &a, const Vector3D &b, const Vector3D &c);

}  // namespace geometry

#endif  // SRC_CORE_MATH_VECTOR_3D_H