//
// Created by Олег on 02.07.2021.
//

#include <algorithm>
#include <iostream>

#include "Rectangle.h"

Point::Point(int x, int y, int z) : x_(x), y_(y), z_(z) {}

Parallelepiped::Parallelepiped(Point first_point, Point second_point)
    : first_point_(first_point), second_point_(second_point) {}

int Parallelepiped::volume(Parallelepiped second_parallelepiped) {
  int height = find_section(this->first_point_.z_,
                            this->second_point_.z_,
                            second_parallelepiped.first_point_.z_,
                            second_parallelepiped.second_point_.z_);
  int width = find_section(this->first_point_.y_,
                           this->second_point_.y_,
                           second_parallelepiped.first_point_.y_,
                           second_parallelepiped.second_point_.y_);
  int length = find_section(this->first_point_.x_,
                            this->second_point_.x_,
                            second_parallelepiped.first_point_.x_,
                            second_parallelepiped.second_point_.x_);
  return (height * width * length);
}

int Parallelepiped::find_section(int a, int b, int c, int d) {
  int height = 0;
  if (a < c) {
    // a<c
    if (a < d) {
      //a<d
      if (b < c) {
        //b<c
        if (b < d) {
          // b<d
          return 0;
        } else {
          // b>d
          height = abs(b - d);
        }
      } else {
        //b>c
        if (b < d) {
          //b<d
          height = abs(b - c);
        } else {
          //b>d
          height = abs(d - c);
        }
      }
    } else {
      //a>d
      if (b < c) {
        //b<c
        if (b < d) {
          //b<d
          height = abs(a - d);
        } else {
          //b>d
          height = abs(b - a);
        }
      } else {
        //b>c
        height = abs(a - c);
      }
    }
  } else {
    //a>c
    if (a > d) {
      //a<d
      if (b > c) {
        //b<c
        if (b > d) {
          // b<d
          return 0;
        } else {
          // b>d
          height = abs(b - d);
        }
      } else {
        //b>c
        if (b > d) {
          //b<d
          height = abs(b - c);
        } else {
          //b>d
          height = abs(d - c);
        }
      }
    } else {
      //a>d
      if (b > c) {
        //b<c
        if (b > d) {
          //b<d
          height = abs(a - d);
        } else {
          //b>d
          height = abs(b - a);
        }
      } else {
        //b>c
        height = abs(a - c);
      }
    }
  }
}

