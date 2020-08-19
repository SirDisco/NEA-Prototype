#pragma once

#include <stack>

#include "State.h"

namespace NEA
{
	class Program
	{
	public:

		Program(State* initialState);
		virtual ~Program();

	public:

		void PushState(State* state);
		void PopState();

		inline State* Top();

		void Run();

		inline bool isRunning() { return !m_StateStack.empty(); }

	public:

		static Program* s_Instance;

	private:

		std::stack<State*> m_StateStack;

	};
}