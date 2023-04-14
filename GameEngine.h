#pragma once
#include <string>
#include "SDL.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

class GameEngine
{
public:
	GameEngine();
	virtual ~GameEngine();

	virtual void Init();
	virtual void LoadLevel(std::string Filename);
	void Run();
	void Stop();

	inline class UWorld* GetWorld() const { return World; }

	int KeyCode;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

protected:
	void Input();
	void Tick();
	void Render();

	bool bIsRunning = true;

	class UWorld* World;
};

