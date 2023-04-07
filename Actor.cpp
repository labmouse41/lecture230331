#include "Actor.h"
#include <iostream>
#include <windows.h>

using namespace std;

AActor::AActor()
{
	posX = 1;
	posY = 1;
	icon = ' ';
}

AActor::AActor(int newX, int newY, char newIcon)
{
	posX = newX;
	posY = newY;
	icon = newIcon;
}

AActor::~AActor()
{
}

void AActor::Input()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Pos;
	Pos.X = posX;
	Pos.Y = posY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	cout << icon;
}

int AActor::GetPosX()
{
	return posX;
}

int AActor::GetPosY()
{
	return posY;
}

void AActor::SetPos(int _posX, int _posY)
{
	posX = _posX;
	posY = _posY;
}

char AActor::GetIcon()
{
	return icon;
}

void AActor::SetIcon(char _Icon)
{
	icon = _Icon;
}
