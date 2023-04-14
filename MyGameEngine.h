#pragma once
#include "GameEngine.h"

//글쓰기 위에서 아래로, 왼쪽에서 오른쪽

class MyGameEngine : public GameEngine
{
private:
	MyGameEngine();

public:
	virtual ~MyGameEngine();

	static inline MyGameEngine* GetEngine()
	{
		if (Instance == nullptr)
		{
			Instance = new MyGameEngine();
		}

		return Instance;
	}

	virtual void Init() override;

private:
	static MyGameEngine* Instance;
};

#define GEngine		MyGameEngine::GetEngine()

