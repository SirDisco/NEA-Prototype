#pragma once

#include <iostream>

#include "Program/Program.h"

namespace NEA
{
	class DeleteAccountState : public State
	{
	public:

		DeleteAccountState() {}
		virtual ~DeleteAccountState() {}

	public:

		void Initialize() override
		{
		}

		void RemoveAccount(std::string& user)
		{
			std::ifstream listOfUsers("res/Accounts/accounts.ls");

			std::vector<std::string> users;

			std::string line;
			while (std::getline(listOfUsers, line))
			{
				if (line != user)
					users.push_back(line);
			}

			listOfUsers.close();

			std::ofstream output("res/Accounts/accounts.ls", std::ios::trunc);
			for (std::string & u : users)
				output << u << '\n';

			output.close();

			remove(("res/Accounts/Users/" + user + ".usr").c_str());

			return;
		}

		void Execute() override
		{
			printf("\n-------------------------------------------------\n\n");

			printf("Delete An Account\n");
			printf("	- At any point type 'QUIT' to exit\n\n");

			std::string userName;
			std::string password;

			bool available = false;
			
			std::cin.ignore(1, '\n');

			// Get Username from user

			while (!available)
			{
				printf("Please enter username: ");

				std::getline(std::cin, userName);

				if (strcmp(userName.c_str(), "QUIT"))
				{
					Program::s_Instance->PopState();
					return;
				}
				else
				{
					// Check username doesn't already exist
					available = CheckNameExists(userName);
				}

				if (!available)
					printf("\n	! Invalid Name !\n\n");
			}

			Account user(userName + ".usr");

			// Check password matches

			bool verified = false;
			
			//std::cin.ignore(1, '\n');

			while (!verified)
			{
				printf("Please enter password: ");

				std::getline(std::cin, password);

				if (strcmp(password.c_str(), "QUIT"))
				{
					Program::s_Instance->PopState();
					return;
				}
				else
				{
					// Check password matches
					verified = user.PasswordMatches(password);
				}

				if (!verified)
					printf("\n	! Incorrect Password !\n\n");
			}

			// User exists and password matches so delete the account
			RemoveAccount(userName);

			printf("\nAccount Deleted Successfully\n");

			Program::s_Instance->PopState();
			return;
		}

	private:

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

	};
}