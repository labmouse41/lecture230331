#pragma once
#include <iostream>

using namespace std;

class AActor
{
public:
	AActor();
	AActor(int newX, int newY, char newIcon);
	virtual ~AActor();

	virtual void Input();
	virtual void Tick();
	virtual void Render();

	int GetPosX();
	int GetPosY();
	void SetPos(int _posX, int _posY);
	char GetIcon();
	void SetIcon(char _Icon);

protected:
	int posX = 0;
	int posY = 0;
	char icon = ' ';
};
