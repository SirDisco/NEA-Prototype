#include "Account.h"

namespace NEA
{
	Account::Account(std::string name, std::string password)
		: m_Name(name), m_Password(password)
	{
		m_DateCreated = std::time(nullptr);
	}

	Account::Account(std::string filename)
	{
		// Need to load in from file
		// Need to determine how the file will be layed out first
	}

	Account::~Account()
	{

	}

	void Account::SaveToFile(std::string filename)
	{
		// Serialize all values and put them into a file
		// Make sure file structure is the same for loading in from a file
	}
}