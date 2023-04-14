#include "Floor.h"

AFloor::AFloor()
{
	R = 100;
	G = 100;
	B = 100;
}

AFloor::AFloor(int NewX, int NewY, char NewShape)
	: AActor(NewX, NewY, NewShape)
{
	R = 100;
	G = 100;
	B = 100;

	SortOrder = 1;
}

AFloor::~AFloor()
{
}
