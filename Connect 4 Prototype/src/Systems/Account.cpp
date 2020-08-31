#include "Account.h"

#include <fstream>

#define NN_LAYER_SIZES { 7 * 6 * 3, 10, 10, 7 }

namespace NEA
{
	Account::Account(std::string name, std::string password)
		: m_Name(name), m_Password(password)
	{
		m_Network = new NeuralNetwork(NN_LAYER_SIZES);
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

	void Account::SaveToFile()
	{
		// Serialize all values and put them into a file
		// Make sure file structure is the same for loading in from a file

		// File to store data in
		std::string filename = "res/Accounts/Users/" + m_Name + ".usr";
		std::ofstream file(filename, std::ios::binary | std::ios::trunc);

		// Store name length and name itself
		unsigned int nameSize = m_Name.size();
		file.write((char*)&nameSize, 4);
		file.write(&m_Name[0], nameSize);

		// Store password length and password itself
		unsigned int passwordSize = m_Password.size();
		file.write((char*)&passwordSize, 4);
		file.write(&m_Password[0], passwordSize);
	
		// Store date created
		file.write((char*)&m_DateCreated, sizeof(time_t));

		// Store both human and ai stats
		file.write((char*)&m_HumanStats, sizeof(WinLosses));
		file.write((char*)&m_AIStats, sizeof(WinLosses));

		BinaryData neuralNetworkData = m_Network->Serialize();

		// Store neural network data
		file.write(neuralNetworkData.first, neuralNetworkData.second);

		delete[] neuralNetworkData.first;

		file.close();
	}
}