#include <gtest/gtest.h>

#include "lib/intersection.h"

TEST(Vector, Vector3D_1) {
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

  e -= {1, 1, 1};
  EXPECT_DOUBLE_EQ(e.Get().x, 24);
  EXPECT_DOUBLE_EQ(e.Get().y, 24);
  EXPECT_DOUBLE_EQ(e.Get().z, 24);

  e -= {1, 1, 1};
  d = e;
  EXPECT_DOUBLE_EQ(e.Get().x, 23);
  EXPECT_DOUBLE_EQ(e.Get().y, 23);
  EXPECT_DOUBLE_EQ(e.Get().z, 23);
  EXPECT_DOUBLE_EQ(d.Get().x, 23);
  EXPECT_DOUBLE_EQ(d.Get().y, 23);
  EXPECT_DOUBLE_EQ(d.Get().z, 23);

  e -= {1, 1, 1};
  EXPECT_DOUBLE_EQ(e.Get().x, 22);
  EXPECT_DOUBLE_EQ(e.Get().y, 22);
  EXPECT_DOUBLE_EQ(e.Get().z, 22);
  d = e;
  e -= {1, 1, 1};
  EXPECT_DOUBLE_EQ(e.Get().x, 21);
  EXPECT_DOUBLE_EQ(e.Get().y, 21);
  EXPECT_DOUBLE_EQ(e.Get().z, 21);
  EXPECT_DOUBLE_EQ(d.Get().x, 22);
  EXPECT_DOUBLE_EQ(d.Get().y, 22);
  EXPECT_DOUBLE_EQ(d.Get().z, 22);
}

TEST(Vector, Vector3D_2) {
  using Vector3D = geometry::Vector3D;
  Vector3D a;

  a.Set(1, 2, 2);
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 1.0 / 3.0);
  EXPECT_DOUBLE_EQ(a.Get().y, 2.0 / 3.0);
  EXPECT_DOUBLE_EQ(a.Get().z, 2.0 / 3.0);

  a.Set(0, 0, 5);
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 0);
  EXPECT_DOUBLE_EQ(a.Get().y, 0);
  EXPECT_DOUBLE_EQ(a.Get().z, 1);

  a.Set(6, 8, 0);
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 0.6);
  EXPECT_DOUBLE_EQ(a.Get().y, 0.8);
  EXPECT_DOUBLE_EQ(a.Get().z, 0);

  a.Set(0, 0, 0);
  a.Normalize();
  EXPECT_DOUBLE_EQ(a.Get().x, 0);
  EXPECT_DOUBLE_EQ(a.Get().y, 0);
  EXPECT_DOUBLE_EQ(a.Get().z, 0);
}

TEST(Vector, Vector3D_3) {
  using Vector3D = geometry::Vector3D;
  Vector3D a{1, 2, 3};
  Vector3D b;

  b.Set(a);
  EXPECT_DOUBLE_EQ(a.Get().x, b.Get().x);
  EXPECT_DOUBLE_EQ(a.Get().y, b.Get().y);
  EXPECT_DOUBLE_EQ(a.Get().z, b.Get().z);

  Vector3D c = a ^ b;

  EXPECT_DOUBLE_EQ(c.Get().x, 0);
  EXPECT_DOUBLE_EQ(c.Get().y, 0);
  EXPECT_DOUBLE_EQ(c.Get().z, 0);

  c.Set(1, 1, 1);

  b = a ^ c;
  EXPECT_DOUBLE_EQ(b.Get().x, -1);
  EXPECT_DOUBLE_EQ(b.Get().y, 2);
  EXPECT_DOUBLE_EQ(b.Get().z, -1);

  double res = a * b;
  EXPECT_DOUBLE_EQ(res, 0);

  res = a * c;
  EXPECT_DOUBLE_EQ(res, 6);

  res = geometry::MixProduct(a, b, c);
  EXPECT_DOUBLE_EQ(res, -6);
}

TEST(Segment, Segment3D_1) {
  using Segment3D = geometry::Segment3D;
  using Vector3D = geometry::Vector3D;
  Vector3D a{1, 1, 1}, b{1, 2, 3};
  Segment3D seg(a, b);
  EXPECT_DOUBLE_EQ(seg.GetStart().Get().x, a.Get().x);
  EXPECT_DOUBLE_EQ(seg.GetStart().Get().y, a.Get().y);
  EXPECT_DOUBLE_EQ(seg.GetStart().Get().z, a.Get().z);
  EXPECT_DOUBLE_EQ(seg.GetEnd().Get().x, b.Get().x);
  EXPECT_DOUBLE_EQ(seg.GetEnd().Get().y, b.Get().y);
  EXPECT_DOUBLE_EQ(seg.GetEnd().Get().z, b.Get().z);

  Segment3D seg2(seg);
  EXPECT_DOUBLE_EQ(seg2.GetStart().Get().x, a.Get().x);
  EXPECT_DOUBLE_EQ(seg2.GetStart().Get().y, a.Get().y);
  EXPECT_DOUBLE_EQ(seg2.GetStart().Get().z, a.Get().z);
  EXPECT_DOUBLE_EQ(seg2.GetEnd().Get().x, b.Get().x);
  EXPECT_DOUBLE_EQ(seg2.GetEnd().Get().y, b.Get().y);
  EXPECT_DOUBLE_EQ(seg2.GetEnd().Get().z, b.Get().z);

  seg2.SetStart({-1, -1, -1});
  seg2.SetEnd({-2, -2, -2});

  EXPECT_DOUBLE_EQ(seg2.GetStart().Get().x, -1);
  EXPECT_DOUBLE_EQ(seg2.GetStart().Get().y, -1);
  EXPECT_DOUBLE_EQ(seg2.GetStart().Get().z, -1);
  EXPECT_DOUBLE_EQ(seg2.GetEnd().Get().x, -2);
  EXPECT_DOUBLE_EQ(seg2.GetEnd().Get().y, -2);
  EXPECT_DOUBLE_EQ(seg2.GetEnd().Get().z, -2);

  seg.Set(seg2);
  EXPECT_DOUBLE_EQ(seg.GetStart().Get().x, -1);
  EXPECT_DOUBLE_EQ(seg.GetStart().Get().y, -1);
  EXPECT_DOUBLE_EQ(seg.GetStart().Get().z, -1);
  EXPECT_DOUBLE_EQ(seg.GetEnd().Get().x, -2);
  EXPECT_DOUBLE_EQ(seg.GetEnd().Get().y, -2);
  EXPECT_DOUBLE_EQ(seg.GetEnd().Get().z, -2);

  seg.Set({5, 4, 3}, {2, 1, 0});
  std::pair<Vector3D, Vector3D> res = seg.Get();
  EXPECT_DOUBLE_EQ(res.first.Get().x, 5);
  EXPECT_DOUBLE_EQ(res.first.Get().y, 4);
  EXPECT_DOUBLE_EQ(res.first.Get().z, 3);
  EXPECT_DOUBLE_EQ(res.second.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.second.Get().y, 1);
  EXPECT_DOUBLE_EQ(res.second.Get().z, 0);

  Segment3D seg3;
  EXPECT_DOUBLE_EQ(seg3.GetStart().Get().x, 0);
  EXPECT_DOUBLE_EQ(seg3.GetStart().Get().y, 0);
  EXPECT_DOUBLE_EQ(seg3.GetStart().Get().z, 0);
  EXPECT_DOUBLE_EQ(seg3.GetEnd().Get().x, 0);
  EXPECT_DOUBLE_EQ(seg3.GetEnd().Get().y, 0);
  EXPECT_DOUBLE_EQ(seg3.GetEnd().Get().z, 0);
}

TEST(Intersection, Intersection) {
  using Vector3D = geometry::Vector3D;
  using Segment3D = geometry::Segment3D;

  Segment3D seg_a, seg_b;

  seg_a.Set({0, 0, 0}, {2, 2, 0});
  seg_b.Set({2, 0, 0}, {0, 2, 0});

  Vector3D res = geometry::Intersect(seg_a, seg_b);
  EXPECT_DOUBLE_EQ(res.Get().x, 1);
  EXPECT_DOUBLE_EQ(res.Get().y, 1);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {0, 0, 0});
  res = geometry::Intersect(seg_a, seg_b);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {5, 1, 5});
  res = geometry::Intersect(seg_a, seg_b);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {5, 1, 5});
  res = geometry::Intersect(seg_a, seg_b);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({0, 0, 0}, {2, 2, 2});
  EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::SkewError);
  try {
    res = geometry::Intersect(seg_a, seg_b);
  } catch (const geometry::SkewError& e) {
    EXPECT_STREQ(e.what(), "Segments are skew (not parallel and lie in different planes).");
  }

  seg_a.Set({2, 0, 5}, {0, 2, 5});
  EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::ParallelError);
  try {
    res = geometry::Intersect(seg_a, seg_b);
  } catch (const geometry::ParallelError& e) {
    EXPECT_STREQ(e.what(), "Segments are parallel, but not collinear.");
  }

  seg_a.Set({3, -1, 0}, {5, -3, 0});
  EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::NoIntersectError);
  try {
    res = geometry::Intersect(seg_a, seg_b);
  } catch (const geometry::NoIntersectError& e) {
    EXPECT_STREQ(e.what(), "Segments do not intersect.");
  }

  seg_a.Set({-1, 3, 0}, {-1, 3, 0});
  EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::NoIntersectError);

  seg_a.Set({3, -1, 0}, {0, 2, 0});
  EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::OverlapError);
  try {
    res = geometry::Intersect(seg_a, seg_b);
  } catch (const geometry::OverlapError& e) {
    EXPECT_DOUBLE_EQ(e.GetOverlap().first.Get().x, 2);
    EXPECT_DOUBLE_EQ(e.GetOverlap().first.Get().y, 0);
    EXPECT_DOUBLE_EQ(e.GetOverlap().first.Get().z, 0);
    EXPECT_STREQ(e.what(), "Segments overlap.");
  }

  seg_a.Set({2, 0, 0}, {2, 0, 0});
  res = geometry::Intersect(seg_a, seg_b);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {4, -2, 0});
  res = geometry::Intersect(seg_a, seg_b);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({3, -1, 0}, {3, -1, 4});
  EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::NoIntersectError);
}

TEST(Intersection, IntersectVec3) {
  using Segment3D = geometry::Segment3D;

  Segment3D seg_a, seg_b;

  seg_a.Set({0, 0, 0}, {2, 2, 0});
  seg_b.Set({2, 0, 0}, {0, 2, 0});

  geometry::Vec3 res_vec = geometry::IntersectVec3(seg_a, seg_b);
  EXPECT_DOUBLE_EQ(res_vec.x, 1);
  EXPECT_DOUBLE_EQ(res_vec.y, 1);
  EXPECT_DOUBLE_EQ(res_vec.z, 0);
}

TEST(Intersection, IntersectWrapper_1) {
  using Vector3D = geometry::Vector3D;
  using Segment3D = geometry::Segment3D;

  Segment3D seg_a, seg_b;

  seg_a.Set({0, 0, 0}, {2, 2, 0});
  seg_b.Set({2, 0, 0}, {0, 2, 0});

  Vector3D res;
  geometry::IntersectionType type;

  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1);
  EXPECT_DOUBLE_EQ(res.Get().y, 1);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {0, 0, 0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {5, 1, 5});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {5, 1, 5});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({0, 0, 0}, {2, 2, 2});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({2, 0, 5}, {0, 2, 5});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3, -1, 0}, {5, -3, 0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-1, 3, 0}, {-1, 3, 0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3, -1, 0}, {0, 2, 0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kOverlap);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {2, 0, 0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({2, 0, 0}, {4, -2, 0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 2);
  EXPECT_DOUBLE_EQ(res.Get().y, 0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0);

  seg_a.Set({3, -1, 0}, {3, -1, 4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);
}

TEST(Intersection, IntersectWrapper_2) {
  using Vector3D = geometry::Vector3D;
  using Segment3D = geometry::Segment3D;

  Segment3D seg_a, seg_b;
  Vector3D res;
  geometry::IntersectionType type;

  seg_a.Set({6.4, 2.3, 2.9}, {6.4, 2.3, 2.9});
  seg_b.Set({-9.5, 8.6, 6.6}, {-8.5, 8.6, 6.6});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-4.7, -6.4, 4.1}, {-4.7, -6.4, 4.1});
  seg_b.Set({-3.8, -3.2, -9.9}, {-2.8, -3.2, -9.9});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({7.4, 1.3, -2.0}, {7.4, 1.3, -2.0});
  seg_b.Set({-7.2, 2.7, -9.4}, {-6.2, 2.7, -9.4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({4.9, -5.7, -1.6}, {4.9, -5.7, -1.6});
  seg_b.Set({-3.2, -2.6, 4.4}, {-2.2, -2.6, 4.4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({5.5, 1.4, -8.3}, {5.5, 1.4, -8.3});
  seg_b.Set({-8.9, -6.9, 2.4}, {-7.9, -6.9, 2.4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3.5, -4.6, 3.2}, {3.5, -4.6, 3.2});
  seg_b.Set({-0.3, -1.2, -4.5}, {0.7, -1.2, -4.5});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({5.1, -7.7, -1.4}, {5.1, -7.7, -1.4});
  seg_b.Set({-4.3, 3.6, -0.3}, {-3.3, 3.6, -0.3});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3.3, -9.1, -2.1}, {3.3, -9.1, -2.1});
  seg_b.Set({2.0, -9.8, -4.0}, {3.0, -9.8, -4.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-5.8, -7.3, -4.9}, {-5.8, -7.3, -4.9});
  seg_b.Set({-3.4, -9.8, 4.9}, {-2.4, -9.8, 4.9});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-6.5, -2.4, 4.1}, {-6.5, -2.4, 4.1});
  seg_b.Set({0.0, 6.7, 6.1}, {1.0, 6.7, 6.1});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-8.6, 2.6, 8.4}, {-7.6, 2.6, 8.4});
  seg_b.Set({9.9, 4.9, -1.3}, {9.9, 5.9, -1.3});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-8.0, 2.7, 7.5}, {-7.0, 2.7, 7.5});
  seg_b.Set({-1.1, 3.9, 8.1}, {-1.1, 4.9, 8.1});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-9.1, 5.9, -4.1}, {-8.1, 5.9, -4.1});
  seg_b.Set({-2.5, -7.1, 0.6}, {-2.5, -6.1, 0.6});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({1.3, 5.9, -6.6}, {2.3, 5.9, -6.6});
  seg_b.Set({-8.4, 7.4, 2.4}, {-8.4, 8.4, 2.4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-5.2, 8.3, -7.1}, {-4.2, 8.3, -7.1});
  seg_b.Set({-0.8, -4.9, -4.9}, {-0.8, -3.9, -4.9});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-9.8, 6.1, 8.0}, {-8.8, 6.1, 8.0});
  seg_b.Set({3.6, -6.8, -1.2}, {3.6, -5.8, -1.2});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-3.1, 1.8, 2.8}, {-2.1, 1.8, 2.8});
  seg_b.Set({-1.5, -5.0, 6.9}, {-1.5, -4.0, 6.9});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-6.0, -2.3, -0.3}, {-5.0, -2.3, -0.3});
  seg_b.Set({-5.3, 1.4, 1.5}, {-5.3, 2.4, 1.5});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({9.9, -4.1, 9.6}, {10.9, -4.1, 9.6});
  seg_b.Set({3.2, -4.5, 1.3}, {3.2, -3.5, 1.3});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3.7, 4.9, -9.0}, {4.7, 4.9, -9.0});
  seg_b.Set({2.1, -0.1, 8.1}, {2.1, 0.9, 8.1});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-4.3, 6.0, 2.1}, {-3.3, 6.0, 2.1});
  seg_b.Set({-3.0, 2.7, 2.4}, {-3.0, 3.7, 2.4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3.6, 4.4, 3.2}, {4.6, 4.4, 3.2});
  seg_b.Set({6.8, 2.6, 8.1}, {6.8, 3.6, 8.1});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({2.9, -3.8, -1.2}, {3.9, -3.8, -1.2});
  seg_b.Set({1.6, 4.6, -8.2}, {1.6, 5.6, -8.2});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-4.1, 4.9, -6.5}, {-3.1, 4.9, -6.5});
  seg_b.Set({-7.4, 0.8, 9.4}, {-7.4, 1.8, 9.4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({0.6, 8.3, 6.6}, {1.6, 8.3, 6.6});
  seg_b.Set({-4.9, 6.5, -0.4}, {-4.9, 7.5, -0.4});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({6.1, 4.9, -3.2}, {7.1, 4.9, -3.2});
  seg_b.Set({-7.7, 9.3, -7.2}, {-7.7, 10.3, -7.2});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({9.3, 7.2, 4.5}, {10.3, 7.2, 4.5});
  seg_b.Set({9.6, 9.3, 6.1}, {9.6, 10.3, 6.1});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-2.7, 5.8, -9.7}, {-1.7, 5.8, -9.7});
  seg_b.Set({0.7, -0.9, 3.5}, {0.7, 0.1, 3.5});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3.4, 1.7, 6.4}, {4.4, 1.7, 6.4});
  seg_b.Set({8.8, -7.8, -5.3}, {8.8, -6.8, -5.3});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-9.5, 7.7, 1.2}, {-8.5, 7.7, 1.2});
  seg_b.Set({8.3, -5.6, -8.7}, {8.3, -4.6, -8.7});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({6.5, 8.2, -4.0}, {7.5, 8.2, -4.0});
  seg_b.Set({-1.8, -7.2, 8.9}, {-1.8, -6.2, 8.9});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-3.9, -0.1, -8.1}, {-2.9, -0.1, -8.1});
  seg_b.Set({7.7, -7.3, -0.9}, {7.7, -6.3, -0.9});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({3.4, 4.9, 8.9}, {4.4, 4.9, 8.9});
  seg_b.Set({-1.6, 4.8, -6.9}, {-1.6, 5.8, -6.9});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-1.7, -8.0, -0.2}, {-0.7, -8.0, -0.2});
  seg_b.Set({-1.8, 9.0, -9.3}, {-1.8, 10.0, -9.3});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({-2.6, -1.1, 9.0}, {-1.6, -1.1, 9.0});
  seg_b.Set({7.1, -8.0, 3.7}, {7.1, -7.0, 3.7});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

  seg_a.Set({0.0, 0.0, 0.0}, {2.0, 2.0, 0.0});
  seg_b.Set({2.0, 0.0, 0.0}, {0.0, 2.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 0.0, 1.0}, {2.0, 2.0, 1.0});
  seg_b.Set({2.0, 0.0, 1.0}, {0.0, 2.0, 1.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 1.0);

  seg_a.Set({0.0, 0.0, 2.0}, {2.0, 2.0, 2.0});
  seg_b.Set({2.0, 0.0, 2.0}, {0.0, 2.0, 2.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 2.0);

  seg_a.Set({0.0, 0.0, 3.0}, {2.0, 2.0, 3.0});
  seg_b.Set({2.0, 0.0, 3.0}, {0.0, 2.0, 3.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 3.0);

  seg_a.Set({0.0, 0.0, 4.0}, {2.0, 2.0, 4.0});
  seg_b.Set({2.0, 0.0, 4.0}, {0.0, 2.0, 4.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 4.0);

  seg_a.Set({0.0, 0.0, 5.0}, {2.0, 2.0, 5.0});
  seg_b.Set({2.0, 0.0, 5.0}, {0.0, 2.0, 5.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 5.0);

  seg_a.Set({0.0, 0.0, 6.0}, {2.0, 2.0, 6.0});
  seg_b.Set({2.0, 0.0, 6.0}, {0.0, 2.0, 6.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 6.0);

  seg_a.Set({0.0, 0.0, 7.0}, {2.0, 2.0, 7.0});
  seg_b.Set({2.0, 0.0, 7.0}, {0.0, 2.0, 7.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 7.0);
  seg_a.Set({0.0, 0.0, 8.0}, {2.0, 2.0, 8.0});
  seg_b.Set({2.0, 0.0, 8.0}, {0.0, 2.0, 8.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 8.0);

  seg_a.Set({0.0, 0.0, 9.0}, {2.0, 2.0, 9.0});
  seg_b.Set({2.0, 0.0, 9.0}, {0.0, 2.0, 9.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 9.0);

  seg_a.Set({0.0, 1.0, 0.0}, {2.0, 3.0, 0.0});
  seg_b.Set({2.0, 1.0, 0.0}, {0.0, 3.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 2.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 2.0, 0.0}, {2.0, 4.0, 0.0});
  seg_b.Set({2.0, 2.0, 0.0}, {0.0, 4.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 3.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 3.0, 0.0}, {2.0, 5.0, 0.0});
  seg_b.Set({2.0, 3.0, 0.0}, {0.0, 5.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 4.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 4.0, 0.0}, {2.0, 6.0, 0.0});
  seg_b.Set({2.0, 4.0, 0.0}, {0.0, 6.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 5.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 5.0, 0.0}, {2.0, 7.0, 0.0});
  seg_b.Set({2.0, 5.0, 0.0}, {0.0, 7.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 6.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 6.0, 0.0}, {2.0, 8.0, 0.0});
  seg_b.Set({2.0, 6.0, 0.0}, {0.0, 8.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 7.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 7.0, 0.0}, {2.0, 9.0, 0.0});
  seg_b.Set({2.0, 7.0, 0.0}, {0.0, 9.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 8.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 8.0, 0.0}, {2.0, 10.0, 0.0});
  seg_b.Set({2.0, 8.0, 0.0}, {0.0, 10.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 9.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);

  seg_a.Set({0.0, 9.0, 0.0}, {2.0, 11.0, 0.0});
  seg_b.Set({2.0, 9.0, 0.0}, {0.0, 11.0, 0.0});
  type = geometry::IntersectWrapper(seg_a, seg_b, res);
  EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
  EXPECT_DOUBLE_EQ(res.Get().x, 1.0);
  EXPECT_DOUBLE_EQ(res.Get().y, 10.0);
  EXPECT_DOUBLE_EQ(res.Get().z, 0.0);
}