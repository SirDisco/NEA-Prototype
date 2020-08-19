#pragma once

#include <iostream>

#include "Program/Program.h"

namespace NEA
{
	class AccountsState : public State
	{
	public:

		AccountsState() {}
		virtual ~AccountsState() {}

	public:

		void Initialize() override
		{
		}

		void Execute() override
		{
			printf("\n-------------------------------------------------\n\n");

			printf("Please select an option\n\n");
			printf("1) Create Account\n");
			printf("2) Delete Account\n");
			printf("3) Back\n");

			int input = -1;
			std::cin >> input;

			while (input < 1 || input > 3)
			{
				printf("Invalid Choice\n");
				std::cin >> input;
			}

			switch (input)
			{
			case 1:
				// Add Create Account State
				break;
			case 2:
				// Add Delete Account State
				break;
			case 3:
				Program::s_Instance->PopState();
				break;
			}
		}

	};
}