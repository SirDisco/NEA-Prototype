#pragma once

#include <iostream>

#include "Program/Program.h"

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
			printf("\n\n-------------------------------------------------\n\n");
		}

		void Execute() override
		{
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
				// Add Play State
				break;
			case 2:
				// Add Leaderboard State
				break;
			case 3:
				// Add Accounts State
				break;
			case 4:
				Program::s_Instance->PopState();
				break;
			}
		}

	};
}