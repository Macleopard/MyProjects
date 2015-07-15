#include <string>
#pragma once
using namespace std;

class Students
{
public:
	Students::Students(std::string name, std::string last_name);

	string get_student_name();
	string get_student_last_name();

	void save_profile();
	void set_student_name(string student_name);
	void set_student_last_name(string student_last_name);
	void set_student_score(int student_scores[]);
	void set_average_ball(float student_average_ball);
	void show_scores();
	float get_average_ball();
	float calculate_average_ball(int student_total_scores[]);
	~Students();
private:

	int scores[5];

	float average_ball;

	string name;
	string last_name;
};
