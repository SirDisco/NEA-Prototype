#include "Program.h"

namespace NEA
{
	Program* Program::s_Instance = nullptr;

	Program::Program(State* initialState)
	{
		if (s_Instance)
			printf("Error, Instance of program already created\n");
		else
			s_Instance = this;

		m_StateStack.push(initialState);
	}

	Program::~Program()
	{
		while (!m_StateStack.empty())
			PopState();
	}

	void Program::PushState(State* state)
	{
		m_StateStack.push(state);
		m_StateStack.top()->Initialize();
	}

	void Program::PopState()
	{
		delete m_StateStack.top();
		m_StateStack.pop();
	}

	State* Program::Top()
	{
		return m_StateStack.top();
	}

	void Program::Run()
	{
		m_StateStack.top()->Execute();
	}
}