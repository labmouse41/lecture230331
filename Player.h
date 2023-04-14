#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape = 'P');

	virtual void Tick() override;

	virtual ~APlayer();
};

