#pragma once

class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	bool operator<(const AActor& RHS)
	{
		return (this->SortOrder) < (RHS.SortOrder);
	}

	bool operator>(const AActor& RHS)
	{
		return (this->SortOrder) > (RHS.SortOrder);
	}

	static inline bool Compare(const AActor* LHS, const AActor* RHS)
	{
		return (LHS->SortOrder) < (RHS->SortOrder);
	}

public:
	int X;
	int Y;
	char Shape;
	int SortOrder = 1;
	bool bIsCollision = false;

	int R;
	int G;
	int B;
};

