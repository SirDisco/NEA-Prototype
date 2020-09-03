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

		// virtual int GetColumnChoice(board state) = 0;

	};
}