//
// Created by Олег on 02.07.2021.
//
#include <iostream>
#include <algorithm>
#include <cmath>

#include "RationalNumber.h"
RationalNumber::RationalNumber(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}

void RationalNumber::sum(RationalNumber second_number) {
  numerator_ = numerator_ * second_number.denominator_ + second_number.numerator_ * denominator_;
  denominator_ = denominator_ * second_number.denominator_;
  abbreviation();
}

void RationalNumber::substraction(RationalNumber second_number) {
  numerator_ = numerator_ * second_number.denominator_ - second_number.numerator_ * denominator_;
  denominator_ = denominator_ * second_number.denominator_;
  abbreviation();
}

void RationalNumber::division(RationalNumber second_number) {
  numerator_ = numerator_ * second_number.denominator_;
  denominator_ = denominator_ * second_number.numerator_;
  abbreviation();
}

void RationalNumber::multiplication(RationalNumber second_number) {
  numerator_ = numerator_ * second_number.numerator_;
  denominator_ = denominator_ * second_number.denominator_;
  abbreviation();
}

void RationalNumber::abbreviation() {
  int dividable = std::max(abs(numerator_), abs(denominator_));  // алгоритм Евклида для нахождения НОДа
  int divider = std::min(abs(numerator_), abs(denominator_));
  int remainder = 1;
  while (remainder != 0) {
    remainder = dividable % divider;
    // std::cout << dividable << " = " << dividable / divider << "*" << divider << " + " << remainder << '\n';
    dividable = divider;
    divider = remainder;
  }
  numerator_ /= dividable;
  denominator_ /= dividable;
}

void RationalNumber::print() const {
  std::cout << numerator_ << "/" << denominator_ << " ";
}
