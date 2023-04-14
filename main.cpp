#include <iostream>
#include "MyGameEngine.h"

using namespace std;

int SDL_main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();

	delete GEngine;

	return 0;
}
