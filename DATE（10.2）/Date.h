#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class CDate {
public:
	enum Month{Jan = 1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
	class Bad_date{}; //异常类
	CDate(int dd = 0, Month mm = Month(0), int yy = 0);

	//获取Date的函数
	int get_year() const;
	int get_month() const;
	int get_day() const;

	string string_rep() const; //字符串表示
	void char_rep(char s[]) const; //c风格字符串表示
	static void set_default(int, Month, int);

	//修改Date的函数
	CDate& add_year(int n);
	CDate& add_month(int n);
	CDate& add_day(int n);

private:
	int d, m, y;
	static CDate default_date;
};

ostream& operator<<(ostream& mout, const CDate& mdate);

#endif