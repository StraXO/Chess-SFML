#pragma once

#include <memory>
#include <stack>

#include "State.h"

using namespace std;

namespace GameEngine
{
	typedef std::unique_ptr<State> state_ref;

	class StateManager
	{
	public:
		StateManager() = default;
		~StateManager() = default;

		void AddState(state_ref newState, bool isReplacing = true);
		void RemoveState();

		void ProcessStateChanges();

		state_ref& GetActiveState();

	private:
		stack<state_ref> _states;
		state_ref _newState;

		bool _isRemoving = false;
		bool _isAdding = false;
		bool _isReplacing = false;
	};
}
