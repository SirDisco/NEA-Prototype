#pragma once

#include "Systems/Connect 4/Connect4Account.h"

namespace NEA
{
	class Connect4AI : public Connect4Account
	{
	public:

		Connect4AI(std::string filename)
			: Connect4Account(filename) { }

	public:

		inline const std::string GetName() const override { return std::string(m_Name + "'s AI"); }

		int GetColumnChoice(Connect4Board& layout, char character) override  // Needs to check if column is valid inside this method !!Very Important!!
		{
			auto board = layout.GetBoard();

			// Turn the board into a different type for the NN to use
			Eigen::VectorXf boardLayout = ConvertBoard(layout, character);

			auto choices = m_Network->FeedForward(boardLayout);

			// Get highest ranking valid choice

			float max = 2.0f;
			int choice = -1;

			while (true)
			{
				float currentBest = 0.0f;

				for (int i = 0; i < 7; i++)
				{
					if (choices[i] < max)
					{
						if (choices[i] > currentBest)
						{
							currentBest = choices[i];
							choice = i;
						}
					}
				}

				// If the positions chosen is valid then use it
				// Otherwise find the next highest ranked one

				if (layout.IsValidPosition(choice))
					return choice;
				else
					max = currentBest;
			}
		}

		void GameWon() override
		{
			m_AIStats.wins++;
		}

		void GameLost() override
		{
			m_AIStats.losses++;
		}

		void GameOver() override {}

	};
}