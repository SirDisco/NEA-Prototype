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

		int GetColumnChoice(Connect4Board layout) override  // Needs to check if column is valid inside this method !!Very Important!!
		{

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