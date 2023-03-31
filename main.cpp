#include <iostream>
#include <ctime>

using namespace std;


int main()
{

	int Map[10][10]
		= { {1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1}, 
			{1,0,0,0,0,0,0,0,0,1}, 
			{1,0,0,0,0,0,0,0,0,1}, 
			{1,0,0,0,0,0,0,0,0,1}, 
			{1,0,0,0,0,0,0,0,0,1}, 
			{1,0,0,0,0,0,0,0,0,1}, 
			{1,0,0,0,0,0,0,0,0,1}, 
			{1,1,1,1,1,1,1,1,1,1} };

	while (true)
	{


		int PlayerPosX = 1;
		int PlayerPosY = 1;

		for (int Y = 0; Y < 10; Y++)
		{
			for (int X = 0; X < 10; X++)
			{
				if (PlayerPosX == X && PlayerPosY == Y)
				{
					cout << 'P';
				}
				else if (Map[Y][X] == 1)
				{
					cout << '#';
				}
				else
				{
					cout << ' ';
				}
			}
			cout << endl;
		}
		system("cls");
	}

	return 0;
}








