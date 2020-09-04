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

		int GetColumnChoice(Connect4Board layout) override  // Needs to check if column is valid inside this method !!Very Important!!
		{

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