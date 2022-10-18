#include <iostream>
#include <map>
using namespace std;

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

	int ConversionWeekToDays() {
		int days = 0;
		for (int i = 0; i < week; i++) {
			days += 7;
		}
		return days;
	}

	int ConversionMonthToDays() {
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

	int ConversionYearToDays() {
		int days = 0;
		for (int i = 0; i < year; i++) {
			if (i % 4 != 0) days += 365;
			else days += 366;
		}
		return days;
	}

	void AddDays(int d) {
		map <int, int> days_in_month = { {1, 31}, {2, 28}, {3, 31}, {4, 30}, 
			                            {5, 31}, {6, 30}, {7, 31}, {8, 31}, 
			                            {9, 30}, {10, 31}, {11, 30}, {12, 31} };
		day += d;
		while (day > days_in_month[month]) {
			day -= days_in_month[month];
			month++;
			if (month > 12) {
				month %= 12;
				year++;
				if (year % 4 == 0) days_in_month[2] = 29;
				else days_in_month[2] = 28;
			}
		}
	}

	void AddWeeks(int w) {
		AddDays(w * 7);
	}

	void AddMonths(int m) {
		month += m;
		while (month > 12) {
			if (year % 4 != 0) day--;
			month -= 12;
			year++;
		}
	}

	void AddYears(int y) {
		for (int i = 1; i <= y; i++) {
			if (year + i % 4 != 0) AddDays(365);
			else AddDays(366);
		}
	}

	void Add(DATE date) {
		AddDays(date.GetDay());
		AddWeeks(date.GetWeek());
		AddMonths(date.GetMonth());
		AddYears(date.GetYear());
	}

	void SubtractDays(int d) {
		map <int, int> days_in_month = { {1, 31}, {2, 28}, {3, 31}, {4, 30},
										{5, 31}, {6, 30}, {7, 31}, {8, 31},
										{9, 30}, {10, 31}, {11, 30}, {12, 31} };
		for (int i = 0; i < d; i++) {
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
			if (year % 4 == 0) days_in_month[2] = 29;
			else days_in_month[2] = 28;
		}
	}

	void SubtractWeeks(int w) {
		SubtractDays(w * 7);
	}

	void SubtractMonths(int m) {
		for (int i = 0; i < m; i++) {
			month--;
			if (month == 0) {
				month = 12;
				year--;
				if (year % 4 != 0) day++;
			}
		}
	}

	void SubtractYears(int y) {
		for (int i = 1; i <= y; i++) {
			if (year - i % 4 != 0) SubtractDays(365);
			else SubtractDays(366);
		}
	}

	void Subtract(DATE date1, DATE date2) {
		day = date1.GetDay();
		week = date1.GetWeek();
		month = date1.GetMonth();
		year = date1.GetYear();
		SubtractDays(date2.GetDay());
		SubtractWeeks(date2.GetWeek());
		SubtractMonths(date2.GetMonth());
		SubtractYears(date2.GetYear());
	}

	DATE operator+(DATE date0) {
		DATE date;
		date.Add(date0);
		return date;
	}

private:
	int day, week, month, year;
};

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

int main() {
	DATE date1 = DATE(11, 0, 10, 2022);
	date1.SetWeek((date1.ConversionMonthToDays() + date1.GetDay()) * 52 / 365 + 1);
	cout << date1 << endl;

	/*for (int i = 1; i <= 666; i++) {
		date1 = DATE(11, 0, 10, 2022);
		date1.AddDays(i);
		date1.SetWeek((date1.ConversionMonthToDays() + date1.GetDay()) * 52 / 365 + 1);
		cout << date1.GetDay() << " " << date1.GetMonth() << " " << date1.GetYear() << " (" << date1.GetWeek() << "/53)" << endl;
	}*/

	Dates lot{666, 0, 0, 0};
	DATE length_of_time = lot;
	cout << length_of_time << endl;
	DATE sum;
	sum = sum + date1;
	//sum = sum + length_of_time;
	//+length_of_time;
	//sum.Add(length_of_time);
	sum.SetWeek((sum.ConversionMonthToDays() + sum.GetDay()) * 52 / 365 + 1);
	//date1.AddWeeks(length_of_time.GetWeek()); 
    //date1.AddMonths(length_of_time.GetMonth());
	//date1.AddYears(length_of_time.GetYear());
	cout << sum << endl;
	date1.Subtract(sum, length_of_time);
	date1.SetWeek((date1.ConversionMonthToDays() + date1.GetDay()) * 52 / 365 + 1);
	cout << date1 << endl;

}