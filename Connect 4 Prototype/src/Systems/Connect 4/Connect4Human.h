#pragma once

#include "Systems/Connect 4/Connect4Account.h"

namespace NEA
{
	class Connect4Human : public Connect4Account
	{
	public:

		Connect4Human(std::string filename)
			: Connect4Account(filename) { }

	public:

		int GetColumnChoice(Connect4Board& layout, char character) override  // Needs to check if column is valid inside this method !!Very Important!!
		{
			printf("You are %c's\n", character);

			PrintBoard(layout.GetBoard());

			int choice = -1;

			while (true)
			{
				printf("Enter column (1-7): ");
				std::cin >> choice;

				if (choice < 1 || choice > 7)
				{
					printf("Invalid column choice!\n");
					continue;
				}

				if (layout.IsValidPosition(choice - 1))
					return choice - 1;
				else
					printf("Column is full!\n");
			}
		}

		void GameWon() override
		{
			m_HumanStats.wins++;

			// Also update neural network with training data saved in this class
		}

		void GameLost() override
		{
			m_HumanStats.losses++;

			// Also update neural network with training data saved in this class
		}

	};
}