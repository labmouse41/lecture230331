#include "Player.h"
#include "MyGameEngine.h"
#include "World.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 2;
	Y = 2;
	bIsCollision = false;
	R = 44;
	G = 255;
	B = 44;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
	: AActor(NewX, NewY, NewShape)
{
	SortOrder = 3;
	R = 44;
	G = 255;
	B = 44;
}

void APlayer::Tick()
{
	if( GEngine->MyEvent.type != SDL_KEYDOWN ) 
	{		
		return;
	}

	switch (GEngine->MyEvent.key.keysym.sym)
	{
	case SDLK_UP:
	case SDLK_w:
		//¹Ì¸® °¡º½
		if (!GEngine->GetWorld()->CheckCollision(X, Y - 1))
		{
			Y--;
		}
		break;
	case SDLK_DOWN:
	case SDLK_s:
		if (!GEngine->GetWorld()->CheckCollision(X, Y + 1))
		{
			Y++;
		}
		break;
	case SDLK_LEFT:
	case SDLK_a:
		if (!GEngine->GetWorld()->CheckCollision(X - 1, Y))
		{
			X--;
		}
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		if (!GEngine->GetWorld()->CheckCollision(X + 1, Y))
		{
			X++;
		}
		break;
	case SDLK_q:
	case SDLK_ESCAPE:
		GEngine->Stop();
		break;
	}
}

APlayer::~APlayer()
{
}
