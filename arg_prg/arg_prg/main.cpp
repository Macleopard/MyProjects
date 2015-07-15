#include <iostream>
#include <string>
#include "name.h"
using namespace std;

int main(int argc, char *argv[])
{
	string name111;
	switch (argc)
	{
	case 1 : name1(); break;
	case 2 : name(argv[1]);break;
	default: error(); 
	}
	/*int count;
	for(count = 0; count < argc; count++ )
	cout << "  argv[" << count << "]   "
	<< argv[count] << "\n";*/
	system("pause");
	return EXIT_SUCCESS;
}