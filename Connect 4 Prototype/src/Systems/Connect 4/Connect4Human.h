#pragma once

#include <vector>

#include "Systems/Connect 4/Connect4Account.h"
#include "Systems/NeuralNetwork.h"

namespace NEA
{
	class Connect4Human : public Connect4Account
	{
	public:

		Connect4Human(std::string filename)
			: Connect4Account(filename) { }

	public:

		int GetColumnChoice(Connect4Board& layout, char character) override  // Needs to check if column is valid inside this method !!Very Important!!
		{
			printf("You are %c's\n", character);

			PrintBoard(layout.GetBoard());

			int choice = -1;

			while (true)
			{
				printf("Enter column (1-7): ");
				std::cin >> choice;

				if (choice < 1 || choice > 7)
				{
					printf("Invalid column choice!\n");
					continue;
				}

				if (layout.IsValidPosition(choice - 1))
				{
					SaveTrainingExample(layout, choice - 1, character);
					return choice - 1;
				}
				else
					printf("Column is full!\n");
			}
		}

		void GameWon() override
		{
			m_HumanStats.wins++;

			m_Network->Train(m_TrainingSet, ETA);

			m_TrainingSet.clear();

			SaveToFile();
		}

		void GameLost() override
		{
			m_HumanStats.losses++;

			m_Network->Train(m_TrainingSet, ETA);

			m_TrainingSet.clear();

			SaveToFile();
		}

	private:

		void SaveTrainingExample(Connect4Board& board, int columnChoice, char character)
		{
			// Turn board into array of floats in correct format
			Eigen::VectorXf boardVector = ConvertBoard(board, character);

			// Turn column choice into correct format
			Eigen::VectorXf choiceVector = Eigen::VectorXf::Zero(7);
			choiceVector[columnChoice] = 1.0f;

			m_TrainingSet.push_back({ boardVector, choiceVector });
		}

	private:

		std::vector<TrainingExample> m_TrainingSet;

	};
}