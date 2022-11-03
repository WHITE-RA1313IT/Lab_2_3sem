#include "Header1.h"

int TIME::ConversionminutesToseconds() {
	int seconds = minutes * 60;
	return seconds;
}

int TIME::ConversionhourToseconds() {
	int seconds = hour * 3600;
	return seconds;
}

void TIME::Addmilsecondss(int m) {
	milseconds += m;
	seconds += milseconds / 1000;
	milseconds %= 1000;
}

void TIME::Addsecondss(int s) {
	seconds += s;
	minutes += milseconds / 60;
	seconds %= 60;
}

void TIME::Addminutess(int m) {
	minutes += m;
	hour += minutes / 60;
	minutes %= 60;
}

void TIME::Addhours(int h) {
	hour += h;
	hour %= 24;
}

void TIME::Add(TIME TIME1, TIME TIME2) {
	milseconds = TIME1.Getmilseconds();
	minutes = TIME1.Getminutes();
	hour = TIME1.Gethour();
	Addmilsecondss(TIME2.Getmilseconds());
	Addsecondss(TIME2.Getseconds());
	Addminutess(TIME2.Getminutes());
	Addhours(TIME2.Gethour());
}

void TIME::Subtractmilsecondss(int m) {
	milseconds -= m;
	seconds -= milseconds / 1000;
	milseconds %= 1000;
}

void TIME::Subtractsecondss(int s) {
	seconds -= s;
	minutes -= milseconds / 60;
	seconds %= 60;
}

void TIME::Subtractminutess(int m) {
	minutes -= m;
	hour -= minutes / 60;
	minutes %= 60;
}

void TIME::Subtracthours(int h) {
	hour -= h;
	hour %= 24;
}

void TIME::Subtract(TIME TIME1, TIME TIME2) {
	milseconds = TIME1.Getmilseconds();
	minutes = TIME1.Getminutes();
	hour = TIME1.Gethour();
	Subtractmilsecondss(TIME2.Getmilseconds());
	Subtractsecondss(TIME2.Getseconds());
	Subtractminutess(TIME2.Getminutes());
	Subtracthours(TIME2.Gethour());
}

bool TIME::Less(TIME TIME2) {//this - 17:01  < (>) time2 - 16:29
	if (Gethour() < TIME2.Gethour()) {
		return true;
	}
	else if (Gethour() == TIME2.Gethour()) {
		if (Getminutes() < TIME2.Getminutes()) {
			return true;
		}
		else if (Getminutes() == TIME2.Getminutes()) {
			if (Getseconds() < TIME2.Getseconds()) {
				return true;
			}
			else if (Getseconds() == TIME2.Getseconds()) {
				if (Getmilseconds() < TIME2.Getmilseconds()) {
					return true;
				}
			}
		}
	}
	else return false;
}

bool TIME::More(TIME TIME2) {
	return !Less(TIME2);
}

bool TIME::Equally(TIME TIME2) {
	if (Gethour() != TIME2.Gethour()) {
		return false;
	}
	else {
		if (Getminutes() != TIME2.Getminutes()) {
			return false;
		}
		else {
			if (Getseconds() != TIME2.Getseconds()) {
				return false;
			}
			else {
				if (Getmilseconds() != TIME2.Getmilseconds()) {
					return false;
				}
			}
		}
	}
	return true;
}

istream& operator >> (istream& is, TIME& TIME) {
	int d, w, m, y;
	is >> d >> w >> m >> y;
	TIME.Sethour(y);
	TIME.Setminutes(m);
	TIME.Setseconds(w);
	TIME.Setmilseconds(d);
	return is;
}

ostream& operator << (ostream& os, TIME& TIME) {
	os << TIME.Gethour() << ":" << TIME.Getminutes() << ":" << TIME.Getseconds() << ":" << TIME.Getmilseconds();
	return os;
}

int DATE::ConversionWeekToDays() {
	int days = week * 7;
	return days;
}

int DATE::ConversionMonthToDays() {
	int days = 0;
	map <int, int> days_in_month = { {1, 31}, {2, 28}, {3, 31}, {4, 30},
									{5, 31}, {6, 30}, {7, 31}, {8, 31},
									{9, 30}, {10, 31}, {11, 30}, {12, 31} };
	if (year % 4 == 0) days_in_month[2] = 29;
	for (int i = 1; i < month; i++) {
		if (i % 12 != 0) days += days_in_month[i % 12];
		else days += days_in_month[12];
	}
	return days;
}

int DATE::ConversionYearToDays() {
	int days = 0;
	for (int i = 0; i < year; i++) {
		if (i % 4 != 0) days += 365;
		else days += 366;
	}
	return days;
}

void DATE::AddDays(int d) {
	map <int, int> days_in_month = { {1, 31}, {2, 28}, {3, 31}, {4, 30},
									{5, 31}, {6, 30}, {7, 31}, {8, 31},
									{9, 30}, {10, 31}, {11, 30}, {12, 31} };
	day += d;
	if (year % 4 == 0) days_in_month[2] = 29;
	while (day > days_in_month[month]) {
		if (year % 4 == 0) days_in_month[2] = 29;
		else days_in_month[2] = 28;
		day -= days_in_month[month];
		month++;
		if (month > 12) {
			month %= 12;
			year++;
		}
	}
}

void DATE::AddWeeks(int w) {
	AddDays(w * 7);
}

void DATE::AddMonths(int m) {
	month += m;
	while (month > 12) {
		month -= 12;
		year++;
	}
	if (year % 4 != 0 && month == 2 && day == 29) {
		month = 3;
		day = 1;
	}
}

void DATE::AddYears(int y) {
	year += y;
	if (year % 4 != 0 && month == 2 && day == 29) {
		month = 3;
		day = 1;
	}
}

void DATE::Add(DATE date1, DATE date2) {
	day = date1.GetDay();
	month = date1.GetMonth();
	year = date1.GetYear();
	AddYears(date2.GetYear());
	AddMonths(date2.GetMonth());
	AddWeeks(date2.GetWeek());
	AddDays(date2.GetDay());
}

void DATE::SubtractDays(int d) {
	map <int, int> days_in_month = { {1, 31}, {2, 28}, {3, 31}, {4, 30},
									{5, 31}, {6, 30}, {7, 31}, {8, 31},
									{9, 30}, {10, 31}, {11, 30}, {12, 31} };
	for (int i = 0; i < d; i++) {
		if (year % 4 == 0) days_in_month[2] = 29;
		else days_in_month[2] = 28;
		day--;
		if (day == 0) {
			month--;
			day = days_in_month[month];
		}
		if (month == 0) {
			month = 12;
			day = days_in_month[month];
			year--;
		}
	}
}

void DATE::SubtractWeeks(int w) {
	SubtractDays(w * 7);
}

void DATE::SubtractMonths(int m) {
	for (int i = 0; i < m; i++) {
		month--;
		if (month == 0) {
			month = 12;
			year--;
		}
	}
}

void DATE::SubtractYears(int y) {
	year -= y;
}

void DATE::Subtract(DATE date1, DATE date2) {
	day = date1.GetDay();
	month = date1.GetMonth();
	year = date1.GetYear();
	SubtractDays(date2.GetDay());
	SubtractWeeks(date2.GetWeek());
	SubtractMonths(date2.GetMonth());
	SubtractYears(date2.GetYear());
}

bool DATE::Less(DATE date2) {
	if (GetYear() < date2.GetYear()) {
		return true;
	}
	else {
		if (GetMonth() < date2.GetMonth()) {
			return true;
		}
		else {
			if (GetDay() < date2.GetDay()) {
				return true;
			}
		}
	}
	return false;
}

bool DATE::More(DATE date2) {
	if (GetYear() > date2.GetYear()) {
		return true;
	}
	else {
		if (GetMonth() > date2.GetMonth()) {
			return true;
		}
		else {
			if (GetDay() > date2.GetDay()) {
				return true;
			}
		}
	}
	return false;
}

bool DATE::Equally(DATE date2) {
	if (GetYear() != date2.GetYear()) {
		return false;
	}
	else {
		if (GetMonth() != date2.GetMonth()) {
			return false;
		}
		else {
			if (GetDay() != date2.GetDay()) {
				return false;
			}
		}
	}
	return true;
}

istream& operator >> (istream& is, DATE& date) {
	int d, w, m, y;
	is >> d >> w >> m >> y;
	date.SetDay(d);
	date.SetWeek(w);
	date.SetMonth(m);
	date.SetYear(y);
	return is;
}

ostream& operator << (ostream& os, DATE& date) {
	if (date.GetDay() < 10) os << "0";
	os << date.GetDay() << ".";
	if (date.GetMonth() < 10) os << "0";
	os << date.GetMonth() << "." << date.GetYear() << " (" << date.GetWeek() << "/53)";
	return os;
}