#pragma once
#include <vector>
class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void SpawnActor(AActor* newActor);


	std::vector<AActor*> Actors;

};

