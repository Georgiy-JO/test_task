#include <gtest/gtest.h>

#include "lib/intersection.h"

TEST(Core_Vectors, Vector3D_1) {
  using Vector3D = geometry::Vector3D;
  Vector3D a;
  Vector3D b(0, 0, 0);
  EXPECT_DOUBLE_EQ(a.Get().x, b.Get().x);
  EXPECT_DOUBLE_EQ(a.Get().y, b.Get().y);
  EXPECT_DOUBLE_EQ(a.Get().z, b.Get().z);

  Vector3D c{1, 2, 3};
  Vector3D d(c);
  Vector3D e(5);
  EXPECT_DOUBLE_EQ(c.Get().x, 1);
  EXPECT_DOUBLE_EQ(c.Get().y, 2);
  EXPECT_DOUBLE_EQ(c.Get().z, 3);
  EXPECT_DOUBLE_EQ(d.Get().x, 1);
  EXPECT_DOUBLE_EQ(d.Get().y, 2);
  EXPECT_DOUBLE_EQ(d.Get().z, 3);
  EXPECT_DOUBLE_EQ(e.Get().x, 5);
  EXPECT_DOUBLE_EQ(e.Get().y, 5);
  EXPECT_DOUBLE_EQ(e.Get().z, 5);

  a = c * 5;
  b = 5 * d;
  EXPECT_DOUBLE_EQ(a.Get().x, 5);
  EXPECT_DOUBLE_EQ(a.Get().y, 10);
  EXPECT_DOUBLE_EQ(a.Get().z, 15);
  EXPECT_DOUBLE_EQ(b.Get().x, 5);
  EXPECT_DOUBLE_EQ(b.Get().y, 10);
  EXPECT_DOUBLE_EQ(b.Get().z, 15);

  e *= 5;
  EXPECT_DOUBLE_EQ(e.Get().x, 25);
  EXPECT_DOUBLE_EQ(e.Get().y, 25);
  EXPECT_DOUBLE_EQ(e.Get().z, 25);

  b = e - a;
  EXPECT_DOUBLE_EQ(b.Get().x, 20);
  EXPECT_DOUBLE_EQ(b.Get().y, 15);
  EXPECT_DOUBLE_EQ(b.Get().z, 10);

  b -= a;
  EXPECT_DOUBLE_EQ(b.Get().x, 15);
  EXPECT_DOUBLE_EQ(b.Get().y, 5);
  EXPECT_DOUBLE_EQ(b.Get().z, -5);

  b = b + b;
  EXPECT_DOUBLE_EQ(b.Get().x, 30);
  EXPECT_DOUBLE_EQ(b.Get().y, 10);
  EXPECT_DOUBLE_EQ(b.Get().z, -10);

  a += b;
  EXPECT_DOUBLE_EQ(a.Get().x, 35);
  EXPECT_DOUBLE_EQ(a.Get().y, 20);
  EXPECT_DOUBLE_EQ(a.Get().z, 5);

  a = b;
  EXPECT_DOUBLE_EQ(a.Get().x, 30);
  EXPECT_DOUBLE_EQ(a.Get().y, 10);
  EXPECT_DOUBLE_EQ(a.Get().z, -10);

  EXPECT_EQ(a, b);
  EXPECT_DOUBLE_EQ(a == b, true);
  EXPECT_DOUBLE_EQ(a == c, false);
  EXPECT_DOUBLE_EQ(a == b, 1);

  EXPECT_NE(a, c);
  EXPECT_DOUBLE_EQ(a != b, false);
  EXPECT_DOUBLE_EQ(a != c, true);
  EXPECT_DOUBLE_EQ(a != c, 1);

  e-={1,1,1};
  EXPECT_DOUBLE_EQ(e.Get().x, 24);
  EXPECT_DOUBLE_EQ(e.Get().y, 24);
  EXPECT_DOUBLE_EQ(e.Get().z, 24);

  e-={1,1,1};
  d = e;
  EXPECT_DOUBLE_EQ(e.Get().x, 23);
  EXPECT_DOUBLE_EQ(e.Get().y, 23);
  EXPECT_DOUBLE_EQ(e.Get().z, 23);
  EXPECT_DOUBLE_EQ(d.Get().x, 23);
  EXPECT_DOUBLE_EQ(d.Get().y, 23);
  EXPECT_DOUBLE_EQ(d.Get().z, 23);

  e-={1,1,1};
  EXPECT_DOUBLE_EQ(e.Get().x, 22);
  EXPECT_DOUBLE_EQ(e.Get().y, 22);
  EXPECT_DOUBLE_EQ(e.Get().z, 22);
  d=e;
  e-={1,1,1};
  EXPECT_DOUBLE_EQ(e.Get().x, 21);
  EXPECT_DOUBLE_EQ(e.Get().y, 21);
  EXPECT_DOUBLE_EQ(e.Get().z, 21);
  EXPECT_DOUBLE_EQ(d.Get().x, 22);
  EXPECT_DOUBLE_EQ(d.Get().y, 22);
  EXPECT_DOUBLE_EQ(d.Get().z, 22);

}

TEST(Core_Vectors, Vector3D_2) {
  using Vector3D = geometry::Vector3D;
  Vector3D a;

  a.Set(1,2,2); 
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 1.0 / 3.0);
  EXPECT_DOUBLE_EQ(a.Get().y, 2.0 / 3.0);
  EXPECT_DOUBLE_EQ(a.Get().z, 2.0 / 3.0);

  a.Set(0,0,5); 
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 0);
  EXPECT_DOUBLE_EQ(a.Get().y, 0);
  EXPECT_DOUBLE_EQ(a.Get().z, 1);

  a.Set(6,8,0); 
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 0.6);
  EXPECT_DOUBLE_EQ(a.Get().y, 0.8);
  EXPECT_DOUBLE_EQ(a.Get().z, 0);

  a.Set(0,0,0); 
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 0);
  EXPECT_DOUBLE_EQ(a.Get().y, 0);
  EXPECT_DOUBLE_EQ(a.Get().z, 0);
}
