//
// Created by Олег on 27.06.2021.
//

#include "Date.h"

#include <cmath>
#include <iostream>

Date::Date() {
  day_ = 1;
  month_ = 1;
  year_ = 1;
}

bool Date::operator==(const Date &second_date) const {
  if (second_date.day_ == this->day_ && second_date.month_ == this->month_ && second_date.year_ == this->year_) {
    return true;
  }
  return false;
}

bool Date::operator!=(const Date &second_date) const {
  return !(*this == second_date);
}

Date::Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}

void Date::change_day_to_next() {
  if (abs(7.5 - month_) % 2) {  // функция, которая выдает 0 если в месяце 31, и 1 если 30 или меньше
    if (month_ == 2) {
      if ((is_leap() && day_ == 29) || (!(is_leap()) && day_ == 28)) {  // проверка февраля
        month_++;
        day_ = 1;
      } else {
        day_++; // нет переполнения
      }
    } else if (day_ == 30) {  // месяцы, где 30 дней
      day_ = 1;
      month_++;
    } else { // нет переполнения
      day_++;
    }
  } else if (day_ == 31) {
    if (month_ == 12) {  // проверка января
      month_ = 1;
      day_ = 1;
      year_++;
    } else {
      month_++;  // если не январь
      day_ = 1;
    }
  } else { // нет переполнения
    day_++;
  }
}

void Date::change_day_to_previous() {
  if (day_ == 1) {
    switch (month_) {

      case (2): {}
      case (4): {}
      case (6): {}
      case (8): {}
      case (9): {}
      case (11): {
        month_--;
        day_ = 31;
        break;
      }
      case (5): {}
      case (7): {}
      case (10): {}
      case (12): {
        month_--;
        day_ = 30;
        break;
      }
      case (3): {
        if (is_leap()) {
          day_ = 29;
        } else {
          day_ = 28;
        }
        month_ = 2;
        break;
      }
      case (1): {
        day_ = 31;
        month_ = 12;
        year_--;
        break;
      }
    }
  } else {
    day_--;
  }
}

bool Date::is_leap() const {
  if (year_ % 4 == 0) {
    if (year_ % 100 == 0 && year_ % 400 != 0) {
      return false;
    }
    return true;
  }
  return false;
}

short Date::week_number() {
  Date date_counter(1, 1, year_);

  short counter = 0;
  while (date_counter != *this) {
    date_counter.change_day_to_next();
    date_counter.print();
    std::cout << '\n';
    counter++;
  }

  return (counter / 7);
}

int Date::day_till_your_birthday(const Date &birthday_date) {
  if (this->month_ < birthday_date.month_) { // если дата уже прошла, мы делаем is_date_bigger=true
    return (this->one_year_duration(birthday_date, false));
  } else if (this->month_ == birthday_date.month_) {
    if (this->day_ < birthday_date.day_) {
      return (this->one_year_duration(birthday_date, false));
    } else {
      return (this->one_year_duration(birthday_date, true));
    }
  } else {
    return (this->one_year_duration(birthday_date, true));
  }
}

int Date::duration(const Date &date) {
  if (this->year_ == date.year_) {  // работает как и для day_till_your_birthday
    return this->day_till_your_birthday(date);
  }
  int day_counter=0;
  if (this->year_ < date.year_) {
    day_counter=this->days_between_years(date.year_,false);
  } else {
    day_counter=this->days_between_years(date.year_, true);
  }
  day_counter+=this->day_till_your_birthday(date);  // добавили дни
  return day_counter;
}

void Date::print() {
  std::cout << day_ << "." << month_ << "." << year_;
}

short Date::one_year_duration(const Date &second_date, bool is_first_date_bigger) {
  short counter = 0;
  Date date_counter(day_, month_, second_date.year_);
  if (is_first_date_bigger) {   // случай, если текущая дата по месяцу больше
    while (date_counter != *this) {
      date_counter.change_day_to_previous();
      date_counter.print();
      std::cout << '\n';
      counter++;
    }
    return (365 + this->is_leap()
        - counter);  // так как текущая дата больше, то значит мы должны посчитать 365-количество
  } else {   // если текущая дата по месяцу меньше
    while (date_counter != second_date) {
      date_counter.change_day_to_next();
      date_counter.print();
      std::cout << '\n';
      counter++;
    }
    return (this->is_leap() + counter);
  }
}

int Date::days_between_years(int year, bool is_first_year_bigger) {
  int day_counter = 0;
  for (int i = std::min(this->year_, year); i < std::max(this->year_, year); ++i) {
    Date tmp_date(1, 1, i);  // объект класса Date для применения функции is_leap
    if (tmp_date.is_leap()) {
      day_counter += 366;
    } else {
      day_counter += 365;
    }
  }
  return day_counter;
}
