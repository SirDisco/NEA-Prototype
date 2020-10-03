#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Program/Program.h"
#include "Systems/Account.h"

namespace NEA
{
	class CreateAccountState : public State
	{
	public:

		CreateAccountState() {}
		virtual ~CreateAccountState() {}

	public:

		void Initialize() override
		{
		}

		void Execute() override
		{
			printf("\n-------------------------------------------------\n\n");

			printf("Create An Account\n");
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
					available = CheckNameIsFree(userName);
				}

				if (!available)
					printf("\n	! Invalid Name !\n\n");
			}

			// Ask user for password

			printf("Please enter password: ");

			std::getline(std::cin, password);

			if (strcmp(password.c_str(), "QUIT"))
			{
				Program::s_Instance->PopState();
				return;
			}

			// Create new account and save to file

			Account newAccount(userName, password);
			newAccount.SaveToFile();

			// Add new account to list of accounts

			std::ofstream listOfUsers("res/Accounts/accounts.ls", std::ios::app);

			listOfUsers << userName << '\n';

			listOfUsers.close();

			printf("\nAccount created successfully\n");
			
			Program::s_Instance->PopState();

		}

	private:

		bool CheckNameIsFree(std::string& name)
		{
			std::ifstream listOfUsers("res/Accounts/accounts.ls");

			std::string line;
			while (std::getline(listOfUsers, line))
			{
				if (name == line)
				{
					listOfUsers.close();
					return false;
				}
			}

			listOfUsers.close();

			return true;
		}

	};
}