#include "stdafx.h"


MainProc _main;

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));
	 
	_main.Init();

	while (!_main.BISQUIT())
	{
		_main.Update();
		_main.Render();
	}
	
	_main.Release();
	
	

	return 0;
}