#include <iostream>
#include <string>
#include "students.h"
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
	SetConsoleTitle(TEXT("Students" ));
	// declaration of new variables
	string st_name,st_last_name;
	int final_scores[5] = {4,4,5,5,5};
	float average_ball;

	cout << "Enter Student name: ";
	cin >> st_name;
	cout << "Enter Student last name: ";
	cin >> st_last_name;
	Students *Student = new Students(st_name,st_last_name);
	cout << "Enter Student scores: ";
	for (int i=0;i<5;i++)
	{
		cin >> final_scores[i];
	}

	Student->set_student_name(st_name);
	Student->set_student_last_name(st_last_name);
	Student->set_student_score(final_scores);
	average_ball = Student->calculate_average_ball(final_scores);

	cout << "Current profile of student: " << endl;
	cout << Student->get_student_name() << endl;
	cout << Student->get_student_last_name() << endl;
	cout << Student->get_average_ball() << endl;
	cout << endl;
	Student->show_scores();
	cout << "Saving current profile to file..." << endl;
	Student->save_profile();
	delete Student;
	system("pause");
	return EXIT_SUCCESS;
}