#include "Program/Program.h"
#include "Program/States/MainMenuState.h"

int main()
{
	NEA::Program p(new NEA::MainMenuState());

	while (p.isRunning())
		p.Run();
}