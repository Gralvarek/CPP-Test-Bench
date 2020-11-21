#include "state.h"






inline bool operator==(const State& lhs, const State& rhs)
{
	return lhs.m_id == rhs.m_id;
}


inline bool operator<(const State& lhs, const State& rhs)
{
	return lhs.m_id < rhs.m_id;
}








void StateMachine::Add(const State& state)
{
	m_states.insert(state);
}

bool StateMachine::Remove(const State& state)
{
	auto it = std::find(m_states.begin(), m_states.end(), state);
	bool state_exists = (it != m_states.end());
	m_states.erase(it, m_states.end());
	return state_exists;
}


bool StateMachine::MoveToNextState(const State& state)
{
	auto it = std::find(m_states.begin(), m_states.end(), state);
	bool state_exists = (it != m_states.end());
	if (state_exists)
		return true;
	else
		return false;
}


int StateMachine::Size()
{
	return m_states.size();
}
