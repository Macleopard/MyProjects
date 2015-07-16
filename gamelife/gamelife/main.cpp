#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

const int FieldWidth(20), FieldHeight(10);
const unsigned char chLiveCell(219), chDeadCell('.');

bool CellArray[FieldWidth * FieldHeight] = {false};
bool TempCellArray[FieldWidth * FieldHeight] = { false };

int iGenerations(10);

bool randomBool() 
{
	return rand() % 2 == 1;
}

void array(bool arr[]) 
{
	srand((unsigned)time(NULL));
	short shRandomNumber = rand();

	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			CellArray[x + y *FieldWidth] = randomBool(); // rand() % 2
			if (CellArray[x + y * FieldWidth])
			{
				cout << chLiveCell;
			}
			else
			{
				cout << chDeadCell;
			}
			
		}
		cout << endl;
	}
}



int main()
{
	array(CellArray);
	cout << endl;
	int CellCounter = 0;
	for (int g = 0; g < iGenerations; g++)
	{
		for (int y = 0; y < FieldHeight; y++)
		{
			for (int x = 0; x < FieldWidth; x++)
			{
				// Analyse neighboring cells

				// #..
				// ...
				// ...
				if (((x-1)>=0)  && ((y-1) >=0))
				{
					if (CellArray[(x - 1) + (y - 1) * FieldWidth])
					{
						CellCounter++;
					}
				}
				// .#.
				// ...
				// ...
				if (((y - 1) >= 0))
				{
					if (CellArray[ x  + (y - 1) * FieldWidth])
					{
						CellCounter++;
					}
				}
				// ..#
				// ...
				// ...
				if (((x + 1) <= FieldWidth) && ((y - 1) >= 0))
				{
					if (CellArray[(x + 1) + (y - 1) * FieldWidth])
					{
						CellCounter++;
					}
				}
				// ...
				// #..
				// ...
				if (((x - 1) >= 0))
				{
					if (CellArray[(x + 1) + y* FieldWidth])
					{
						CellCounter++;
					}
				}
				// ...
				// ..#
				// ...

				if (((x + 1) <= FieldWidth-1))
				{
					if (CellArray[(x + 1) + y* FieldWidth])
					{
						CellCounter++;
					}
				}
				// ...
				// ...
				// #..

				if ((((x - 1) >= 0)) && ((y+1) <=FieldHeight-1))
				{
					if (CellArray[(x - 1) + (y+1)* FieldWidth])
					{
						CellCounter++;
					}
				}
				// ...
				// ...
				// .#.
				if (((y + 1) <= FieldHeight - 1))
				{
					if (CellArray[x + (y + 1)* FieldWidth])
					{
						CellCounter++;
					}
				}
				// ...
				// ...
				// ..#
				if ((((x + 1) <= FieldWidth - 1)) && ((y + 1) <= FieldHeight - 1))
				{
					if (CellArray[(x + 1) + (y + 1) * FieldWidth])
					{
						CellCounter++;
					}
				}
				// Defination state

				if ((CellCounter < 2) || (CellCounter>3)) 
				{
					TempCellArray[x + y * FieldWidth] = false;
					cout << chDeadCell;
				}
				else
				{
					if ((!CellArray[x + y*FieldWidth]) && (CellCounter != 3))
					{
						TempCellArray[x + y * FieldWidth] = false;
						cout << chDeadCell;
					}
					else
					{
						TempCellArray[x + y * FieldWidth] = true;
						cout << chLiveCell;
					}
				}
				CellCounter = 0;
				
			} // Horizontal field
			cout << endl;
			
		} // Vertical field
		cout << endl;
		cout << endl;
		for (int i = 0; i < (FieldWidth*FieldHeight); i++)
		{
			CellArray[i] = TempCellArray[i];
		}
	}
	_getch();
	return 0;
}