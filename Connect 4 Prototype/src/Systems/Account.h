#pragma once

#include <string>
#include <ctime>

#include "NeuralNetwork.h"

namespace NEA
{
	struct WinLosses
	{
		int wins = 0;
		int losses = 0;
	};

	class Account
	{
	public:

		Account(std::string name, std::string password);
		Account(std::string filename);
		virtual ~Account();

	public:

		void SaveToFile();

		inline const std::string& GetName() const { return m_Name; }

		inline bool PasswordMatches(std::string& password) const { return m_Password == password; }

		inline const std::time_t& GetDateCreated() const { return m_DateCreated; }

		inline WinLosses& GetHumanStats() { return m_HumanStats; }
		inline WinLosses& GetAIStats() { return m_AIStats; }

	private:

		std::string m_Name;
		std::string m_Password;

		std::time_t m_DateCreated;

		WinLosses m_HumanStats;
		WinLosses m_AIStats;

		NeuralNetwork* m_Network;

	};
}