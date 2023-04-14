#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	X = 9;
	Y = 9;

	R = 200;
	G = 200;
	B = 0;
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
	: AActor(NewX, NewY, NewShape)
{
	SortOrder = 2;

	R = 200;
	G = 200;
	B = 0;
}

AGoal::~AGoal()
{
}
