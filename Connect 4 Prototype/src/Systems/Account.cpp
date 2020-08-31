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

		std::string filePath = "res/Accounts/Users/" + filename;
		std::ifstream file(filePath, std::ios::binary);

		// Read 4 bytes - size of name
		int nameSize = 0;
		file.read((char*)&nameSize, sizeof(int));

		// Read x bytes - name itself
		m_Name.resize(nameSize);
		file.read(&m_Name[0], nameSize);

		// Read 4 bytes - password size
		int passwordSize = 0;
		file.read((char*)&passwordSize, sizeof(int));

		// Read x bytes - password itself
		m_Password.resize(passwordSize);
		file.read(&m_Password[0], passwordSize);

		// Read 8 bytes - date created
		file.read((char*)&m_DateCreated, sizeof(time_t));

		// Read 8 bytes twice - both human and ai stats
		file.read((char*)&m_HumanStats, sizeof(WinLosses));
		file.read((char*)&m_AIStats, sizeof(WinLosses));

		// Count how many bytes in the NN data
		const auto begin = file.tellg();
		file.seekg(0, std::ios::end);
		size_t NNBytes = file.tellg() - begin;

		// Read NN Data and create NN object
		file.seekg(begin);
		char* NNData = new char[NNBytes];
		file.read(NNData, NNBytes);

		m_Network = new NeuralNetwork(NNData);

		delete[] NNData;

		file.close();
	}

	Account::~Account()
	{
		delete m_Network;
	}

	void Account::SaveToFile()
	{
		// Serialize all values and put them into a file
		// Make sure file structure is the same for loading in from a file

		// File to store data in
		std::string filePath = "res/Accounts/Users/" + m_Name + ".usr";
		std::ofstream file(filePath, std::ios::binary | std::ios::trunc);

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