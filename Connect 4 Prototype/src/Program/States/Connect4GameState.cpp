#include "Connect4GameState.h"

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
			int columnChoice = 0; // int columnChoice = currentTurn->GetColumnChoice(board);

			char character = (currentTurn == m_Player1 ? '#' : '@');

			// Place counter at that column
			m_Board.PlaceCounter(columnChoice, character);

			// Repeat if no one has won or the game has been drawn
		} while (!m_Board.GameOver());

		// Pop state

		if (m_Board.GameWon())
		{
			// Push win state
		}
		else
		{
			// Push draw state
		}

		return;

	}
}