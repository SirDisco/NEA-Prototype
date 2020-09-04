#pragma once

namespace NEA
{
	class Connect4Board
	{
	public:

		Connect4Board()
		{
			// Initialize board to empty
			for (int i = 0; i < 7; i++)
				for (int j = 0; j < 6; j++)
					m_Board[i][j] = ' ';

			m_RecentColumn = -1;
			m_RecentRow = -1;

			m_RecentChar = '\n';
		}

		virtual ~Connect4Board() {}

	public:

		// Places the counter in the column given and returns if that place is valid
		bool PlaceCounter(int column, char character)
		{
			// If there is a counter at the top of the column chosen then it is invalid
			if (m_Board[column][0] != ' ')
				return false;

			// Loop downwards until a counter is found then place the new one above that
			// Only need to loop from i = 1 as we know that the top space is open at least
			for (int i = 1; i < 6; i++)
			{
				if (m_Board[column][i] != ' ')
				{
					m_Board[column][i - 1] = character;

					m_RecentColumn = column;
					m_RecentRow = i - 1;
					m_RecentChar = character;

					return true;
				}
			}

			// If got to here then there are no counters in the column so place at bottom

			m_Board[column][5] = character;

			m_RecentColumn = column;
			m_RecentRow = 5;
			m_RecentChar = character;

			return true;
		}

		bool GameOver()
		{
			return GameWon() | GameDrawn();
		}

		bool GameWon()
		{
			// Check in all possible lines (up-down, left-right, both diagonals)
			int dx[] = {  0, -1, -1, -1 };
			int dy[] = { -1, -1,  0,  1 };

			for (int i = 0; i < 4; i++)
			{
				// The most recent one is already 1 in a row
				int inARow = 1;

				// Check all counters in a direction for 3 steps
				for (int step = 1; step < 4; step++)
				{
					// Position to check
					int x = m_RecentColumn + dx[i] * step;
					int y = m_RecentRow + dy[i] * step;

					// If out of bounds
					if (x < 0 || x > 6 || y < 0 || y > 5)
						break;

					if (m_Board[x][y] != m_RecentChar)
						break;

					inARow++;
				}
				
				// Check the negative direction
				for (int step = 1; step < 4; step++)
				{
					// Position to check
					int x = m_RecentColumn - dx[i] * step;
					int y = m_RecentRow - dy[i] * step;

					// If out of bounds
					if (x < 0 || x > 6 || y < 0 || y > 5)
						break;

					if (m_Board[x][y] != m_RecentChar)
						break;

					inARow++;
				}

				// If 4 or more counters were found then the game has been won
				if (inARow >= 4)
					return true;
				return false;
			}
		}

		bool GameDrawn()
		{
			// Loop through the top positions in each column
			// If any are empty then the game hasn't been drawn yet
			for (int i = 0; i < 7; i++)
				if (m_Board[i][0] == ' ')
					return false;
			return true;
		}

	private:

		// Current state of the board
		char m_Board[7][6];

		// Most recent position chosen to make GameWon more efficient
		int m_RecentColumn;
		int m_RecentRow;
		char m_RecentChar;

	};
}