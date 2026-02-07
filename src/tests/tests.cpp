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

TEST(Vector, Vector3D_2) {
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

TEST(Vector, Vector3D_3) {
  using Vector3D = geometry::Vector3D;
  Vector3D a{1,2,3};
  Vector3D b;

  b.Set(a);
  EXPECT_DOUBLE_EQ(a.Get().x, b.Get().x);
  EXPECT_DOUBLE_EQ(a.Get().y, b.Get().y);
  EXPECT_DOUBLE_EQ(a.Get().z, b.Get().z);

  Vector3D c=a^b;

  EXPECT_DOUBLE_EQ(c.Get().x, 0);
  EXPECT_DOUBLE_EQ(c.Get().y, 0);
  EXPECT_DOUBLE_EQ(c.Get().z, 0);

  c.Set(1,1,1);

  b=a^c;
  EXPECT_DOUBLE_EQ(b.Get().x, -1);
  EXPECT_DOUBLE_EQ(b.Get().y, 2);
  EXPECT_DOUBLE_EQ(b.Get().z, -1);  
  
  double res=a*b;
  EXPECT_DOUBLE_EQ(res, 0);

  res=a*c;
  EXPECT_DOUBLE_EQ(res, 6);

  res=geometry::MixProduct(a,b,c);
  EXPECT_DOUBLE_EQ(res, -6);
}

TEST(Segment, Segment3D_1){
    using Segment3D = geometry::Segment3D;
    using Vector3D = geometry::Vector3D;
    Vector3D a{1,1,1}, b{1,2,3};
    Segment3D seg(a,b);
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

    seg2.SetStart({-1,-1,-1});
    seg2.SetEnd({-2,-2,-2});

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

    seg.Set({5,4,3},{2,1,0});
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

TEST(Intersection, Intersection){
    using Vector3D = geometry::Vector3D;
    using Segment3D = geometry::Segment3D;

    Segment3D seg_a, seg_b;

    seg_a.Set({0,0,0},{2,2,0});
    seg_b.Set({2,0,0},{0,2,0});

    Vector3D res=geometry::Intersect(seg_a, seg_b);
    EXPECT_DOUBLE_EQ(res.Get().x, 1);
    EXPECT_DOUBLE_EQ(res.Get().y, 1);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{0,0,0});
    res=geometry::Intersect(seg_a, seg_b);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{5,1,5});
    res=geometry::Intersect(seg_a, seg_b);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{5,1,5});
    res=geometry::Intersect(seg_a, seg_b);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({0,0,0},{2,2,2});
    EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::SkewError);
    try{
        res=geometry::Intersect(seg_a, seg_b);
    }
    catch(const geometry::SkewError& e){
        EXPECT_STREQ(e.what(), "Segments are skew (not parallel and lie in different planes).");
    }

    seg_a.Set({2,0,5},{0,2,5});
    EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::ParallelError);

    seg_a.Set({3,-1,0},{5,-3,0});
    EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::NoIntersectError);
    try{
        res=geometry::Intersect(seg_a, seg_b);
    }
    catch(const geometry::NoIntersectError& e){
        EXPECT_STREQ(e.what(), "Segments do not intersect.");
    }

    seg_a.Set({-1,3,0},{-1,3,0});
    EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::NoIntersectError);

    seg_a.Set({3,-1,0},{0,2,0});
    EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::OverlapError);
    try{
        res=geometry::Intersect(seg_a, seg_b);
    }
    catch(const geometry::OverlapError& e){
        EXPECT_DOUBLE_EQ(e.GetOverlap().first.Get().x, 2);
        EXPECT_DOUBLE_EQ(e.GetOverlap().first.Get().y, 0);
        EXPECT_DOUBLE_EQ(e.GetOverlap().first.Get().z, 0);
        EXPECT_STREQ(e.what(), "Segments overlap.");
    }

    seg_a.Set({2,0,0},{2,0,0});
    res=geometry::Intersect(seg_a, seg_b);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{4,-2,0});
    res=geometry::Intersect(seg_a, seg_b);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({3,-1,0},{3,-1,4});
    EXPECT_THROW(geometry::Intersect(seg_a, seg_b), geometry::NoIntersectError);
}

TEST(Intersection, IntersectVec3){
    using Segment3D = geometry::Segment3D;

    Segment3D seg_a, seg_b;

    seg_a.Set({0,0,0},{2,2,0});
    seg_b.Set({2,0,0},{0,2,0});

    geometry::Vec3 res_vec=geometry::IntersectVec3(seg_a, seg_b);
    EXPECT_DOUBLE_EQ(res_vec.x, 1);
    EXPECT_DOUBLE_EQ(res_vec.y, 1);
    EXPECT_DOUBLE_EQ(res_vec.z, 0);
}

TEST(Intersection, IntersectWrapper){
    using Vector3D = geometry::Vector3D;
    using Segment3D = geometry::Segment3D;

    Segment3D seg_a, seg_b;

    seg_a.Set({0,0,0},{2,2,0});
    seg_b.Set({2,0,0},{0,2,0});

    Vector3D res;
    geometry::IntersectionType type;

    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
    EXPECT_DOUBLE_EQ(res.Get().x, 1);
    EXPECT_DOUBLE_EQ(res.Get().y, 1);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{0,0,0});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{5,1,5});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{5,1,5});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({0,0,0},{2,2,2});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

    seg_a.Set({2,0,5},{0,2,5});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

    seg_a.Set({3,-1,0},{5,-3,0});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

    seg_a.Set({-1,3,0},{-1,3,0});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);

    seg_a.Set({3,-1,0},{0,2,0});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kOverlap);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);    

    seg_a.Set({2,0,0},{2,0,0});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({2,0,0},{4,-2,0});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kIntersect);
    EXPECT_DOUBLE_EQ(res.Get().x, 2);
    EXPECT_DOUBLE_EQ(res.Get().y, 0);
    EXPECT_DOUBLE_EQ(res.Get().z, 0);

    seg_a.Set({3,-1,0},{3,-1,4});
    type=geometry::IntersectWrapper(seg_a, seg_b, res);
    EXPECT_EQ(type, geometry::IntersectionType::kNoIntersect);
}