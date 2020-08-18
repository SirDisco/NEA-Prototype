#pragma once

namespace NEA
{
	// Abstract State class used to allow for polymorphism to store all types of states in a data structure
	class State
	{
	public:

		State() {}
		virtual ~State() {}

	public:

		// Used to set any values that need to be set at a specific time (date)
		// Cannot take any parameters so the constructor of the base class must be used for that
		virtual void Initialize() = 0;
		// The main body of the state. Is used to print any messages, take input and give functionality
		// to the object.
		virtual void Execute() = 0;
	};
}