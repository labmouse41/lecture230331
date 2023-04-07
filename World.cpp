#include "World.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::SpawnActor(AActor* newActor)
{
	if (newActor != nullptr)
	{
		Actors.push_back(newActor);
	}
}
