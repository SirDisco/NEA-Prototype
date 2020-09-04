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

		// int GetColumnChoice(board layout) override

		void GameWon() override;
		void GameLost() override;

	};
}