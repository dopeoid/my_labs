//
// Created by Олег on 27.06.2021.
//

#ifndef LAB06__DATE_H_
#define LAB06__DATE_H_

class Date {
 public:
  Date();
  Date(int day, int month, int year);
  void change_day_to_next();
  void change_day_to_previous();
  bool is_leap() const;
  short week_number();
  int day_till_your_birthday(const Date &birthday_date);
  int duration(const Date &date);
  void print();
  int days_between_years(int year, bool is_first_year_bigger);
  bool operator==(const Date &second_date) const;
  bool operator!=(const Date &second_date) const;
//  bool operator<=(const Date &second_date) const;
  short one_year_duration(const Date &second_date, bool is_first_date_bigger);
 private:
  int day_;
  int month_;
  int year_;
};

#endif //LAB06__DATE_H_
