#include "StateManager.h"

namespace GameEngine
{
	void StateManager::AddState(state_ref newState, const bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		
		this->_newState = move(newState);
	}

	void StateManager::RemoveState()
	{
		this->_isRemoving = true;
	}

	void StateManager::ProcessStateChanges()
	{
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();

			if (!this->_states.empty())
				this->_states.top()->Resume();

			this->_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
					this->_states.pop();
				else 
					this->_states.top()->Pause();
			}
			
			this->_states.push(move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;
		}
	}

	state_ref& StateManager::GetActiveState()
	{
		return this->_states.top();
	}

}