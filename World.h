#pragma once
#include <vector>
class AActor; //���漱��, ��� ���� ������ ���, ������

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

