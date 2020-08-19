#pragma once

#include <iostream>

#include "Program/Program.h"
#include "PlayState.h"
#include "LeaderboardState.h"
#include "AccountsState.h"

namespace NEA
{
	class MainMenuState : public State
	{
	public:

		MainMenuState() {}
		virtual ~MainMenuState() {}

	public:

		void Initialize() override
		{
		}

		void Execute() override
		{
			printf("\n-------------------------------------------------\n\n");

			printf("Welcome to Connect 4 with AI - Prototype\n\n");
			printf("Please select an option\n\n");
			printf("1) Play\n");
			printf("2) Leaderboard\n");
			printf("3) Accounts\n");
			printf("4) Exit\n\n");

			int input = -1;
			std::cin >> input;

			while (input < 1 || input > 4)
			{
				printf("Invalid Choice\n");
				std::cin >> input;
			}

			switch (input)
			{
			case 1:
				Program::s_Instance->PushState(new PlayState());
				break;
			case 2:
				Program::s_Instance->PushState(new LeaderboardState());
				break;
			case 3:
				Program::s_Instance->PushState(new AccountsState());
				break;
			case 4:
				Program::s_Instance->PopState();
				break;
			}
		}

	};
}