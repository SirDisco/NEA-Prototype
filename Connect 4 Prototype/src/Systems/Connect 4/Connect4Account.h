#pragma once

#include "Systems/Account.h"

namespace NEA
{
	class Connect4Account : public Account
	{
	public:

		Connect4Account(std::string filename)
			: Account(filename) {}

	public:

		// virtual int GetColumnChoice(board state) = 0; // Needs to check if column is valid inside this method !!Very Important!!

		virtual void GameWon() = 0;
		virtual void GameLost() = 0;

	};
}