#include "Wall.h"

AWall::AWall()
{
	bIsCollision = true;
	R = 20;
	G = 20;
	B = 20;
}

AWall::AWall(int NewX, int NewY, char NewShape)
	: AActor(NewX, NewY, NewShape)
{
	bIsCollision = true;
	SortOrder = 2;

	R = 20;
	G = 20;
	B = 20;

}

AWall::~AWall()
{
}
