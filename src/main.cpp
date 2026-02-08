
#include <iostream>

#include "lib/intersection.h"

int main() {
  using namespace geometry;
  using std::cin, std::cout, std::endl;

  double x, y, z;
  Segment3D seg_a, seg_b;
  cout << "Input coordinates of the begining and end of the first segment (Xb Yb Zb Xe Ye Ze)." << endl;
  cin >> x >> y >> z;
  seg_a.SetStart(Vector3D(x, y, z));
  cin >> x >> y >> z;
  seg_a.SetEnd(Vector3D(x, y, z));

  cout << "Input coordinates of the begining and end of the second segment (Xb Yb Zb Xe Ye Ze)." << endl;
  cin >> x >> y >> z;
  seg_b.SetStart(Vector3D(x, y, z));
  cin >> x >> y >> z;
  seg_b.SetEnd(Vector3D(x, y, z));

  Vector3D intersection_point;
  IntersectionType type = IntersectWrapper(seg_a, seg_b, intersection_point);
  if (type == IntersectionType::kIntersect)
    cout << "The segments intersected at (" << intersection_point.Get().x << ", " << intersection_point.Get().y << ", "
         << intersection_point.Get().z << ")." << endl;
  else if (type == IntersectionType::kNoIntersect)
    cout << "The segments did not intersect." << endl;
  else
    cout << "The segments overlapped. The beginning of overlap is at (" << intersection_point.Get().x << ", "
         << intersection_point.Get().y << ", " << intersection_point.Get().z << ")." << endl;
  return 0;
}