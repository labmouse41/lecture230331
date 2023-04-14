#pragma once
#include <vector>
class AActor; //전방선언, 어딘가 쓸때 가져다 써라, 포인터

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void SpawnActor(AActor* NewActor);

	virtual void Tick();
	virtual void Render();

	void Sort();

	//Physics
	bool CheckCollision(int X, int Y);

public:
	std::vector<AActor*> Actors;
};

