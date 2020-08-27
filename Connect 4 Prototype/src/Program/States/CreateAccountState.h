#pragma once

#include <iostream>

#include "Program/Program.h"

namespace NEA
{
	class CreateAccountState : public State
	{
	public:

		CreateAccountState() {}
		virtual ~CreateAccountState() {}

	public:

		void Initialize() override
		{
		}

		void Execute() override
		{
			printf("\n-------------------------------------------------\n\n");

			printf("Place holder state. Nothing here for now\n\n");

			printf("Please select an option\n\n");
			printf("1) Back\n\n");

			int input = -1;
			std::cin >> input;

			while (input < 1 || input > 1)
			{
				printf("Invalid Choice\n");
				std::cin >> input;
			}

			switch (input)
			{
			case 1:
				Program::s_Instance->PopState();
				break;
			}
		}

	};
}