//
// Created by Олег on 02.07.2021.
//

#ifndef LAB06__RECTANGLE_H_
#define LAB06__RECTANGLE_H_

class Point {
 public:
  Point (int x, int y, int z);
  int x_=0;
  int y_=0;
  int z_=0;
};

class Parallelepiped {
 public:
  Parallelepiped(Point first_point, Point second_point);
  int volume(Parallelepiped second_parallelepiped);
  static int find_section(int a, int b, int c, int d);
 private:
  Point first_point_;
  Point second_point_;
};



#endif //LAB06__RECTANGLE_H_
