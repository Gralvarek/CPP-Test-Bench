#ifndef STATE_H


#include <stdint.h>
#include <unordered_map>


enum class StateType
{
	START,
	MIDDLE,
	END
};

class State
{
public:
	friend bool operator==(const State& lhs, const State& rhs);
	friend bool operator<(const State& lhs, const State& rhs);
private:
	StateType m_id;
};


class StateMachine
{
public:
	StateMachine(const std::unordered_map<State>& graph);

	void Add(const State& state);
	bool Remove(const State& state);
	void MoveToNextState(const State& state);
	void ExecuteState();

	State GetCurrentState();

	int Size();
private:
	std::unordered_map<State> m_states;
};

#endif // !STATE_H