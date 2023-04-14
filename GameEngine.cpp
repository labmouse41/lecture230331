#define _CRT_SECURE_NO_WARNINGS 

#include "GameEngine.h"
#include "World.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Goal.h"
#include "Monster.h"

#include <iostream>
#include <algorithm>
#include <conio.h>



GameEngine::GameEngine()
{
	bIsRunning = true;
	World = nullptr;
    KeyCode = 0;
}

GameEngine::~GameEngine()
{
	if (World != nullptr)
	{
		delete World;
		World = nullptr;
	}

    SDL_DestroyRenderer(MyRenderer);
    SDL_DestroyWindow(MyWindow);
    SDL_Quit();
}

void GameEngine::Init()
{
	World = new UWorld();

    SDL_Init(SDL_INIT_EVERYTHING);

    MyWindow = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_VULKAN);
    MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_ACCELERATED);
}

void GameEngine::LoadLevel(std::string Filename)
{
    FILE* file;
    char c;

    file = fopen(Filename.c_str(), "r");
    int PositionX = 1;
    int PositionY = 1;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '*')
        {
            GetWorld()->SpawnActor(new AWall(PositionX, PositionY));
            GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
            //printf("벽");
        }
        else if (c == ' ')
        {
            GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
            //printf("바닥");
        }
        else if (c == 'P')
        {
            GetWorld()->SpawnActor(new APlayer(PositionX, PositionY));
            GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
            //printf("플레이어");
        }
        else if (c == 'G')
        {
            GetWorld()->SpawnActor(new AGoal(PositionX, PositionY));
            GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
            //printf("목표");
        }
        else if (c == 'M')
        {
            GetWorld()->SpawnActor(new AMonster(PositionX, PositionY));
            GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
            //printf("몬스터");
        }
        if (c == '\n')
        {
            ++PositionY;
            PositionX = 0;
            //printf("줄바꿈");
        }
        //printf("%d, %d\n", PositionX, PositionY);

        ++PositionX;
    }

    fclose(file);

    GetWorld()->Sort();
}

void GameEngine::Run()
{
	while (bIsRunning) //Frame
	{
		//system("cls");
		Input();
		Tick();
		Render();
	}
}

void GameEngine::Stop()
{
	bIsRunning = false;
}

void GameEngine::Input()
{
    //KeyCode = _getch();
    SDL_PollEvent(&MyEvent);
}

void GameEngine::Tick()
{
	World->Tick();
}

void GameEngine::Render()
{
    SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
    SDL_RenderClear(MyRenderer);

	World->Render();

    SDL_RenderPresent(MyRenderer);
}
