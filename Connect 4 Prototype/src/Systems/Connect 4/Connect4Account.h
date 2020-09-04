#pragma once

#include "Systems/Account.h"
#include "Connect4Board.h"

namespace NEA
{
	class Connect4Account : public Account
	{
	public:

		Connect4Account(std::string filename)
			: Account(filename) {}

	public:

		virtual int GetColumnChoice(Connect4Board& state, char character) = 0;

		virtual void GameWon() = 0;
		virtual void GameLost() = 0;

	protected:

		Eigen::VectorXf ConvertBoard(Connect4Board& board, char character)
		{
			auto boardArray = board.GetBoard();
			Eigen::VectorXf boardLayout(6 * 7 * 3, 1);
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					int index = 3 * (i * 7 + j);

					if (boardArray[j][i] == ' ')
					{
						// Empty position
						boardLayout[index + 0] = 0.0f;
						boardLayout[index + 1] = 0.0f;
						boardLayout[index + 2] = 1.0f;
					}
					else if (boardArray[j][i] == character)
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
			
			return boardLayout;
		}

		void PrintBoard(const char board[][6])
		{
			printf("\n");
			printf(" 1 2 3 4 5 6 7\n");

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					printf("|%c", board[j][i]);
				}
				printf("|\n");
				printf("+-+-+-+-+-+-+-+\n");
			}
		}
	};
}