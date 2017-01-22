#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
	public:
	string name;
	int age;
	vector <double> points;
	public:
	double average () {
		if (points.size () == 0)
			return 0;
		double sum = 0;
		for (int i = 0; i < points.size (); ++i) {
			sum += points[i];
		}
		return sum / points.size ();
	}
	public:
	double best_mark () {
		if (points.size () == 0)
			return 0;
		double mx = 0;
		for (int i = 0; i < points.size (); ++i) {
			mx = max (mx, points[i]);
		}
		return mx;
	}
	public:
	void change_name (string changed_name) {
		name = changed_name;
	}
};


vector <Student> KBTU;

int main () {

	while (1) {
		cout << "What do you want?\n";
		string query;
		cout << "if you want to know best student, print " << '"' << "best" << '"' << " without quotes\n";
		cout << "if you want to exit, print " << '"' << "exit" << '"' << " without quotes\n";
		cout << "if you want to add student, print " << '"' << "add" << '"' << " without quotes\n";
		cout << "if you want to delete student, print " << '"' << "delete" << '"' << " without quotes\n";
		cout << "if you want to add mark to student, print student name\n";
		cin >> query;
		if (query == "exit")
			break;
		else if (query == "best") {
			if (KBTU.empty ()) {
				cout << "there isn't any student at KBTU\n";
				continue;
			}
			int best = 0;
			for (int i = 0; i < KBTU.size (); ++i) {
				if (KBTU[i].average () > KBTU[best].average ())
					best = i;
			}
			cout << "Best student is " << KBTU[best].name << endl;
		}
		else if (query == "add") {
			Student new_student;
			cout << "Print name: ";
			string x;
			cin >> x;
			new_student.name = x;
			cout << "Print age: ";
			int age;
			cin >> age;
			new_student.age = age;
			cout << "Thank you\n";
			KBTU.push_back (new_student);
		} else if (query == "delete") {
			cout << "Print name: ";
			string x;
			cin >> x;
			for (int i = 0; i < KBTU.size (); ++i) {
				if (KBTU[i].name == x) {
					KBTU.erase (KBTU.begin () + i);
				}
			}

		} else {
			int cnt = 0;
			for (int i = 0; i < KBTU.size (); ++i) {
				if (KBTU[i].name == query) {
					cout << "Print new mark: ";
					double mark;
					cin >> mark;
					KBTU[i].points.push_back (mark);
					cnt++;
				}
			}
			if (cnt == 0) {
				cout << "No such student\n";
			}
		}
	}


	return 0;
}
