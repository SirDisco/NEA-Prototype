#pragma once

#include <iostream>
#include <fstream>

#include "Program/Program.h"
#include "Connect4GameState.h"
#include "Systems/Connect 4/Connect4Account.h"
#include "Systems/Connect 4/Connect4AI.h"
#include "Systems/Connect 4/Connect4Human.h"

namespace NEA
{
	class PlayState : public State
	{
	public:

		PlayState() {}
		virtual ~PlayState() {}

	public:

		void Initialize() override
		{
		}

		void Execute() override
		{
			printf("\n-------------------------------------------------\n\n");

			printf("Play\n");
			printf("	- At any point type 'QUIT' to go back\n\n");

			std::cin.ignore(1, '\n');

			printf("Player 1\n\n");

			Connect4Account* player1 = GetPlayer();

			if (!player1)
				return;

			printf("\n--------- Player 2 --------\n\n");

			Connect4Account* player2 = GetPlayer();

			if (!player2)
				return;

			Program::s_Instance->PopState();
			Program::s_Instance->PushState(new Connect4State(player1, player2));
		}

	private:
		
		Connect4Account* GetPlayer()
		{
			bool isHuman = isHumanPlaying();

			if (isHuman)
			{
				// Need username and password to be correct
				return GetHuman();
			}
			else
			{
				// Only need username to be correct
				return GetAI();
			}
		}

		Connect4Human* GetHuman()
		{
			std::string username = GetUsername();

			if (username == "")
				return nullptr;

			Connect4Human* user = new Connect4Human(username + ".usr");

			// Check password matches

			std::string password;

			bool verified = false;

			while (!verified)
			{
				printf("\nPlease enter password: ");

				std::getline(std::cin, password);

				if (password._Equal("QUIT"))
				{
					Program::s_Instance->PopState();
					return nullptr;
				}
				else
				{
					// Check password matches
					verified = user->PasswordMatches(password);
				}

				if (!verified)
					printf("\n	! Incorrect Password !\n");
			}

			// Password is correct

			return user;
		}

		Connect4AI* GetAI()
		{
			std::string username = GetUsername();

			if (username == "")
				return nullptr;

			return new Connect4AI(username + ".usr");
		}

		std::string GetUsername()
		{
			std::string userName;

			bool available = false;

			// Get Username from user

			while (!available)
			{
				printf("\nPlease enter username: ");

				std::getline(std::cin, userName);

				if (userName._Equal("QUIT"))
				{
					Program::s_Instance->PopState();
					return "";
				}
				else
				{
					// Check username doesn't already exist
					available = CheckNameExists(userName);
				}

				if (!available)
					printf("\n	! Invalid Name !\n");
			}

			return userName;
		}

		bool CheckNameExists(std::string& name)
		{
			std::ifstream listOfUsers("res/Accounts/accounts.ls");

			std::string line;
			while (std::getline(listOfUsers, line))
			{
				if (name == line)
				{
					listOfUsers.close();
					return true;
				}
			}

			listOfUsers.close();

			return false;
		}

		bool isHumanPlaying()
		{
			std::string input;

			bool isHuman = false;
			bool valid = true;

			do
			{
				printf("Is Human Playing (y/n): ");
				std::getline(std::cin, input);

				if (input == "y" || input == "Y")
				{
					isHuman = true;
					valid = true;
				}
				else if (input == "n" || input == "N")
				{
					isHuman = false;
					valid = true;
				}
				else
				{
					valid = false;
					printf("\n	! Invalid Input !\n\n");
				}

			} while (!valid);

			return isHuman;
		}

	};
}