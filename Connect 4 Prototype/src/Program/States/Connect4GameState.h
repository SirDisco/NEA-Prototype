#pragma once

#include <Eigen/Dense>

#include "Program/Program.h"
#include "Program/State.h"
#include "Systems/Connect 4/Connect4Account.h"
#include "Systems/Connect 4/Connect4Board.h"

namespace NEA
{
	class Connect4State : public State
	{
	public:

		Connect4State(Connect4Account* player1, Connect4Account* player2);
		virtual ~Connect4State();

	public:

		void Initialize() override;

		void Execute() override;

	private:

		Connect4Account* m_Player1;
		Connect4Account* m_Player2;

		Connect4Board m_Board;

	};
}