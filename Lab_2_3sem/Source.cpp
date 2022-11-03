#include "Header1.h"

int main() {
	DATE date1, date2, sum;
	cout << "How do you want to enter and output dates?\n";
	cout << "1) Console stream;\n";
	cout << "2) String stream;\n";
	cout << "3) File stream.\n";
	int in;
	cin >> in;
	while (in < 1 || in > 3) {
		cout << "Incorrect input!\n";
		cin >> in;
	}
	cout << "What do you want to do?\n";
	cout << "1) Add up dates;\n";
	cout << "2) Subtract dates;\n";
	cout << "3) Compare dates.\n";
	int num;
	cin >> num;
	while (num < 1 || num > 3) {
		cout << "Incorrect input!\n";
		cin >> num;
	}

	if (in == 1) {
		cin >> date1;
		cin >> date2;
	}
	if (in == 2) {
		stringstream ss;
		ss << "27 0 10 2022" << "\n";
		ss >> date1;
		ss << "1 2 3 4" << "\n";
		ss >> date2;
	}
	if (in == 3) {
		ifstream in1("C:\\Users\\nikit\\Desktop\\input1.txt");
		if (in1.is_open())
		{
			in1 >> date1;
		}
		in1.close();
		ifstream in2("C:\\Users\\nikit\\Desktop\\input2.txt");
		if (in2.is_open())
		{
			in2 >> date2;
		}
		in2.close();
	}

	switch (num)
	{
	case 1:
		sum = date1 + date2;
		if (in == 1) cout << sum;
		if (in == 2) {
			stringstream ss;
			ss << sum;
			cout << ss.str() << endl;
		}
		if (in == 3) {
			ofstream out("C:\\Users\\nikit\\Desktop\\output.txt");
			if (out.is_open())
			{
				out << sum;
			}
			out.close();
		}
		break;
	case 2:
		sum = date1 - date2;
		if (in == 1) cout << sum;
		if (in == 2) {
			stringstream ss;
			ss << sum;
			cout << ss.str() << endl;
		}
		if (in == 3) {
			ofstream out("C:\\Users\\nikit\\Desktop\\output.txt");
			if (out.is_open())
			{
				out << sum;
			}
			out.close();
		}
		break;
	case 3:
		if (in == 1) {
			if (date1 > date2) cout << date1 << " more than " << date2 << endl;
			if (date1 < date2) cout << date1 << " less than " << date2 << endl;
			if (date1 == date2) cout << date1 << " equally " << date2 << endl;
		}
		if (in == 2) {
			stringstream out;
			if (date1 > date2) out << date1 << " more than " << date2;
			if (date1 < date2) out << date1 << " less than " << date2;
			if (date1 == date2) out << date1 << " equally " << date2;
			cout << out.str() << endl;
		}
		if (in == 3) {
			ofstream out("C:\\Users\\nikit\\Desktop\\output.txt");
			if (out.is_open())
			{
				if (date1 > date2) out << date1 << " more than " << date2;
				if (date1 < date2) out << date1 << " less than " << date2;
				if (date1 == date2) out << date1 << " equally " << date2;
			}
			out.close();
		}
		break;
	}
}