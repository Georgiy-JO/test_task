#include "vector3d.h"

#include <cmath>

namespace geometry {
Vector3D Vector3D::operator*(double number) const {
  return Vector3D(x * number, y * number, z * number);
}

Vector3D operator*(double number, const Vector3D &vec) {
  return Vector3D(vec.x * number, vec.y * number, vec.z * number);
}

Vector3D &Vector3D::operator*=(double number) {
  x *= number;
  y *= number;
  z *= number;
  return *this;
}

Vector3D Vector3D::operator-(const Vector3D &vec) const {
  return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D &Vector3D::operator-=(const Vector3D &vec) {
  x -= vec.x;
  y -= vec.y;
  z -= vec.z;
  return *this;
}

Vector3D Vector3D::operator+(const Vector3D &vec) const {
  return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec) {
  x += vec.x;
  y += vec.y;
  z += vec.z;
  return *this;
}

Vector3D &Vector3D::operator=(const Vector3D &vec) {
  x = vec.x;
  y = vec.y;
  z = vec.z;
  return *this;
}

bool Vector3D::operator==(const Vector3D &vec) const {
  return (x == vec.x && y == vec.y && z == vec.z);
}

bool Vector3D::operator!=(const Vector3D &vec) const { return !(*this == vec); }

void Vector3D::Normalize() {
  double length = Length();
  if (length != 0) {
    x /= length;
    y /= length;
    z /= length;
  }
}

void Vector3D::Set(double x_, double y_, double z_){
  x = x_;
  y = y_;
  z = z_;
}

void Vector3D::Set(const Vector3D &vec){
  x = vec.x;
  y = vec.y;
  z = vec.z;
}

double Vector3D::Length() const{
  return std::sqrt(x * x + y * y + z * z);
}

std::tuple<double, double, double> Vector3D::Get() const{
  return {x, y, z};
}


}  // namespace geometry
