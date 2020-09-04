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

		virtual int GetColumnChoice(Connect4Board state) = 0;

		virtual void GameWon() = 0;
		virtual void GameLost() = 0;

	};
}