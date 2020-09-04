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

		void PrintBoard(const char board[][6])
		{
			printf("\n");
			printf(" 1   2   3   4   5   6   7\n");

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