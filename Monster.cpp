#include "Monster.h"
#include "MyGameEngine.h"
#include "World.h"

AMonster::AMonster()
{
	R = 255;
	G = 111;
	B = 111;
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
	: AActor(NewX, NewY, NewShape)
{
	SortOrder = 4;

	R = 255;
	G = 0;
	B = 0;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	if (GEngine->MyEvent.type != SDL_KEYDOWN)
	{
		return;
	}
	int a = rand()%4;
	switch (a)
	{
	case 0:
		//¹Ì¸® °¡º½
		if (!GEngine->GetWorld()->CheckCollision(X, Y - 1))
		{
			Y--;
		}
		break;
	case 1:
		if (!GEngine->GetWorld()->CheckCollision(X, Y + 1))
		{
			Y++;
		}
		break;
	case 2:
		if (!GEngine->GetWorld()->CheckCollision(X - 1, Y))
		{
			X--;
		}
		break;
	case 3:
		if (!GEngine->GetWorld()->CheckCollision(X + 1, Y))
		{
			X++;
		}
		break;
		GEngine->Stop();
		break;
	}
}
