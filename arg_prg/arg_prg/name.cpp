#include <iostream>
#include <string>
using namespace std;

void name(char *name)
{
	cout << "Hello, " << name << endl;
}
void name1()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Hello, " << name << endl; 
}
void error()
{
	cout << "Too many arguments" << endl;
}