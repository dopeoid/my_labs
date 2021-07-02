//
// Created by Олег on 02.07.2021.
//

#ifndef LAB06__RATIONALNUMBER_H_
#define LAB06__RATIONALNUMBER_H_

class RationalNumber {
 public:
  RationalNumber(int numerator, int denominator);
  void sum(RationalNumber second_number);
  void substraction(RationalNumber second_number);
  void division(RationalNumber second_number);
  void multiplication(RationalNumber second_number);
  void print() const;
 private:
  void abbreviation();
  int numerator_ = 1;
  int denominator_ = 1;

};

#endif //LAB06__RATIONALNUMBER_H_
