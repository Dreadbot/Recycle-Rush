#include "FSM.h"

namespace dreadbot
{
	void FiniteStateMachine::init(FSMTransition* newStateTable, FSMState* initState)
	{
		this->stateTable = newStateTable;
		this->currentState = initState;
		this->currentState->enter();
	}
	void FiniteStateMachine::update()
	{
		int input = currentState->update();
		for (auto state = &this->stateTable[0]; state->currentState != nullptr; state++)
		{
			if (state->input == input && state->currentState == this->currentState)
			{
				if (state->action != nullptr) {
					state->action(input, state->currentState, state->nextState);
				}
				if (state->nextState != this->currentState) {
					state->nextState->enter();
				}
				this->currentState = state->nextState;
				break;
			}
		}
	}
}
