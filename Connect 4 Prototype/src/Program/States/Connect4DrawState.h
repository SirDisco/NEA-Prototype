#pragma once

#include "Program/Program.h"

#include "Systems/Connect 4/Connect4Account.h"

namespace NEA
{
	class Connect4DrawState : public State
	{
	public:

		Connect4DrawState(Connect4Account* player1, Connect4Account* player2)
			: m_Player1(player1), m_Player2(player2) {}

		virtual ~Connect4DrawState()
		{
			delete m_Player1;
			delete m_Player2;
		}

	public:

		void Initialize() override
		{

		}

		void Execute() override
		{
			printf("It was a draw between %s and %s!\n", m_Player1->GetName(), m_Player2->GetName());
			printf("No wins/losses will be added to your accounts!\n");

			m_Player1->GameOver();
			m_Player2->GameOver();

			Program::s_Instance->PopState();
		}

	private:

		Connect4Account* m_Player1;
		Connect4Account* m_Player2;

	};
}