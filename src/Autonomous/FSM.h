#pragma once

#define END_STATE_TABLE {nullptr, 0, nullptr, nullptr}

namespace dreadbot
{
	class FSMState
	{
	public:
		virtual void enter() = 0; //Automatically when this state is first entered.
		virtual int update() = 0;
		virtual ~FSMState() {}
	};

	class FSMTransition
	{
	public:
		FSMState* currentState;
		int input;
		void (*action)(int input, FSMState* current, FSMState* nextState);
		FSMState* nextState;
	};

	class FiniteStateMachine
	{
	public:
		virtual void init(FSMTransition* newStateTable, FSMState* initState);
		virtual void update();
		virtual ~FiniteStateMachine() {}
	protected:
		FSMTransition* stateTable;
		FSMState* currentState;
	};
}
