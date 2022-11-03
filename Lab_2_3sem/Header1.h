#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct Times {
	int milseconds;
	int seconds;
	int minutes;
	int hour;
};

class TIME {
public:
	TIME() {
		milseconds = 0;
		seconds = 0;
		minutes = 0;
		hour = 0;
	}

	TIME(int d, int w, int m, int y) {
		hour = d;
		minutes = w;
		seconds = m;
		milseconds = y;
	}

	TIME(Times t) {
		milseconds = t.milseconds;
		seconds = t.seconds;
		minutes = t.minutes;
		hour = t.hour;
	}

	int Getmilseconds() {
		return milseconds;
	}
	void Setmilseconds(int value) {
		milseconds = value;
	}

	int Getseconds() {
		return seconds;
	}
	void Setseconds(int value) {
		seconds = value;
	}

	int Getminutes() {
		return minutes;
	}
	void Setminutes(int value) {
		minutes = value;
	}

	int Gethour() {
		return hour;
	}
	void Sethour(int value) {
		hour = value;
	}

	int ConversionminutesToseconds();

	int ConversionhourToseconds();

	void Addmilsecondss(int m);

	void Addsecondss(int s);

	void Addminutess(int m);

	void Addhours(int h);

	void Add(TIME TIME1, TIME TIME2);

	void Subtractmilsecondss(int m);

	void Subtractsecondss(int s);

	void Subtractminutess(int m);

	void Subtracthours(int h);

	void Subtract(TIME TIME1, TIME TIME2);

	bool Less(TIME TIME2);

	bool More(TIME TIME2);

	bool Equally(TIME TIME2);

	TIME operator+(TIME TIME0) {
		TIME TIME, sub_TIME = { Getmilseconds(), Getseconds(), Getminutes(), Gethour() };
		TIME.Add(sub_TIME, TIME0);
		return TIME;
	}

	TIME operator-(TIME TIME0) {
		TIME TIME, sub_TIME = { Getmilseconds(), Getseconds(), Getminutes(), Gethour() };
		TIME.Subtract(sub_TIME, TIME0);
		return TIME;
	}

	bool operator<(TIME TIME0) {
		return Less(TIME0);
	}

	bool operator>(TIME TIME0) {
		return More(TIME0);
	}

	bool operator==(TIME TIME0) {
		return Equally(TIME0);
	}

private:
	int milseconds, seconds, minutes, hour;
};

istream& operator >> (istream& is, TIME& TIME);

ostream& operator << (ostream& os, TIME& TIME);

struct Dates {
	int day;
	int week;
	int month;
	int year;
};

class DATE {
public:
	DATE() {
		day = 0;
		week = 0;
		month = 0;
		year = 0;
	}

	DATE(int d, int w, int m, int y) {
		day = d;
		week = w;
		month = m;
		year = y;
	}

	DATE(Dates d) {
		day = d.day;
		week = d.week;
		month = d.month;
		year = d.year;
	}

	int GetDay() {
		return day;
	}
	void SetDay(int value) {
		day = value;
	}

	int GetWeek() {
		return week;
	}
	void SetWeek(int value) {
		week = value;
	}

	int GetMonth() {
		return month;
	}
	void SetMonth(int value) {
		month = value;
	}

	int GetYear() {
		return year;
	}
	void SetYear(int value) {
		year = value;
	}

	int ConversionWeekToDays();

	int ConversionMonthToDays();

	int ConversionYearToDays();

	void AddDays(int d);

	void AddWeeks(int w);

	void AddMonths(int m);

	void AddYears(int y);

	void Add(DATE date1, DATE date2);

	void SubtractDays(int d);

	void SubtractWeeks(int w);

	void SubtractMonths(int m);

	void SubtractYears(int y);

	void Subtract(DATE date1, DATE date2);

	bool Less(DATE date2);

	bool More(DATE date2);

	bool Equally(DATE date2);

	DATE operator+(DATE date0) {
		DATE date, sub_date = { GetDay(), GetWeek(), GetMonth(), GetYear() };
		date.Add(sub_date, date0);
		return date;
	}

	DATE operator-(DATE date0) {
		DATE date, sub_date = { GetDay(), GetWeek(), GetMonth(), GetYear() };
		date.Subtract(sub_date, date0);
		return date;
	}

	bool operator<(DATE date0) {
		return Less(date0);
	}

	bool operator>(DATE date0) {
		return More(date0);
	}

	bool operator==(DATE date0) {
		return Equally(date0);
	}

private:
	int day, week, month, year;
};

istream& operator >> (istream& is, DATE& date);

ostream& operator << (ostream& os, DATE& date);