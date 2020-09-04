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

		int GetColumnChoice(Connect4Board& layout, char character) override  // Needs to check if column is valid inside this method !!Very Important!!
		{
			auto board = layout.GetBoard();

			PrintBoard(board);

			// Turn the board into a different type for the NN to use
			Eigen::VectorXf boardLayout(6 * 7 * 3, 1);
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					int index = 3 * (i * 7 + j);

					if (board[j][i] == ' ')
					{
						// Empty position
						boardLayout[index + 0] = 0.0f;
						boardLayout[index + 1] = 0.0f;
						boardLayout[index + 2] = 1.0f;
					}
					else if (board[j][i] == character)
					{
						// Your own counter
						boardLayout[index + 0] = 0.0f;
						boardLayout[index + 1] = 1.0f;
						boardLayout[index + 2] = 0.0f;
					}
					else
					{
						// Enemies counter
						boardLayout[index + 0] = 1.0f;
						boardLayout[index + 1] = 0.0f;
						boardLayout[index + 2] = 0.0f;
					}
				}
			}

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
						currentBest = std::max(currentBest, choices[i]);
						choice = i;
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

	};
}