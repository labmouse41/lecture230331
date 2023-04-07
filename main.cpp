#include <iostream>
#include <ctime>
#include <conio.h>
#include "Player.h"
#include "World.h"
#include "Goal.h"

using namespace std;

int main()
{
	UWorld* World = new UWorld();

	World->SpawnActor(new APlayer);
	World->SpawnActor(new AGoal);
	
	delete World;

//
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

	int PlayerPosX = 1;
	int PlayerPosY = 1;
	bool bIsRunning = true;

	while (bIsRunning)
	{
		//input
		char key;
		key = _getch();

		//tick
		if (key == 'd')
		{
			PlayerPosX++;
		}
		else if (key == 'a')
		{
			PlayerPosX--;
		}
		else if (key == 'w')
		{
			PlayerPosY--;
		}
		else if (key == 's')
		{
			PlayerPosY++;
		}
		else if (key == 'q')
		{
			bIsRunning = false;
		}

		//render
		system("cls");
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
	}

	return 0;
}








