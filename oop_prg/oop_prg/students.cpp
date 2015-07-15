#include <string>
#include "students.h"
#include <iostream>
#include <fstream>

using namespace std;

string Students::get_student_name()
{
	return name;
}

string Students::get_student_last_name()
{
	return last_name;
}

void Students::set_student_name(string student_name)
{
	name = student_name;
}

void Students::set_student_last_name(string student_last_name)
{
	last_name = student_last_name;
}

void Students::set_student_score(int student_scores[])
{
	for (int i=0; i<5;i++)
	{
		scores[i] = student_scores[i];
	}
}

void Students::show_scores()
{
	for (int i=0;i<5;i++)
	{
		cout << Students::scores[i] << endl;
	}
}

void Students::set_average_ball(float student_average_ball)
{
	average_ball = student_average_ball;
}

float Students::get_average_ball()
{
	return average_ball;
}

float Students::calculate_average_ball(int student_total_scores[])
{
	int total_scores[5];
	int sum;
	float result;
	sum = 0;
	for (int i=0; i<5; i++)
	{
		total_scores[i]=student_total_scores[i];
		sum +=student_total_scores[i];
	}
	result = (float) sum / 5;
	average_ball = result;
	return result;
}

Students::Students(std::string name, std::string last_name)
{
	Students::set_student_name(name);
	Students::set_student_last_name(last_name);
}

void Students::save_profile()
{
	ofstream fout ("students.profile", ios::app);

	fout << Students::get_student_name() << " "
		<< Students::get_student_last_name() << " ";

	for (int i=0;i<5;++i)
	{
		fout << Students::scores[i] << " ";
	}
	fout << Students::get_average_ball();

	fout << endl;
	fout.close();
}

Students::~Students()
{
	cout << "The object Student was deleted succesfully. Have a nice day!" << endl;
}