#pragma once

#include "Program/Program.h"

namespace NEA
{
	class Connect4WinState : public State
	{
	public:

		Connect4WinState(Connect4Account* winner, Connect4Account* loser)
			: m_Winner(winner), m_Loser(loser) {}

		virtual ~Connect4WinState()
		{
			delete m_Winner;
			delete m_Loser;
		}

	public:

		void Initialize() override
		{

		}

		void Execute() override
		{
			printf("Congratulations %s. You've won!\n", m_Winner->GetName());

			m_Winner->GameWon();
			m_Loser->GameLost();

			m_Winner->GameOver();
			m_Loser->GameOver();

			Program::s_Instance->PopState();
		}

	private:

		Connect4Account* m_Winner;
		Connect4Account* m_Loser;

	};
}