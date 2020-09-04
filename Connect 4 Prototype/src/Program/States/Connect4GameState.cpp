#include "Connect4GameState.h"

#include "Connect4WinState.h"
#include "Connect4DrawState.h"

namespace NEA
{
	Connect4State::Connect4State(Connect4Account* player1, Connect4Account* player2)
		: m_Player1(player1), m_Player2(player2) { }

	Connect4State::~Connect4State()
	{
		delete m_Player1;
		delete m_Player2;
	}

	void Connect4State::Initialize()
	{
		printf("\n-------------------------------------------------\n\n");

		printf("Connect 4\n\n");
	}

	void Connect4State::Execute()
	{
		// Current turn is player 2 because turns are swapped instantly
		Connect4Account* currentTurn = m_Player2;

		do
		{
			// Swap the turns
			if (currentTurn == m_Player1)
				currentTurn = m_Player2;
			else
				currentTurn = m_Player1;

			printf((currentTurn->GetName() + "'s Turn\n\n").c_str());

			// Get Player/AI's column choice
			char character = (currentTurn == m_Player1 ? '#' : '@');
			int columnChoice = currentTurn->GetColumnChoice(m_Board, character);

			printf("%s chose column %i\n", currentTurn->GetName().c_str(), columnChoice + 1);

			// Place counter at that column
			m_Board.PlaceCounter(columnChoice, character);

			printf("\n-------------------------------------------------\n\n");

			// Repeat if no one has won or the game has been drawn
		} while (!m_Board.GameOver());

		Program::s_Instance->PopState();

		if (m_Board.GameWon())
			Program::s_Instance->PushState(new Connect4WinState(currentTurn, (currentTurn == m_Player1 ? m_Player2 : m_Player1)));
		else
			Program::s_Instance->PushState(new Connect4DrawState(m_Player1, m_Player2));

		return;

	}
}