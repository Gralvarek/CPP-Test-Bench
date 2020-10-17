#ifndef TETRIS_H
#define TETRIS_H


#include <stdint.h>
#include <vector>
#include <set>
#include <memory>


class Playfield
{
public:
	Playfield(uint32_t height, uint32_t width);
private:
	uint32_t m_height, m_width;
};







class Shape
{
public:
	enum class ShapeType
	{
		Straight,
		Square,
		T,
		L,
		Skew
	};

	enum class MoveDirection
	{
		Left,
		Right,
		Down
	};

	struct ShapePosition
	{
		int x, y;
	
		friend bool operator==(const ShapePosition& lhs, const ShapePosition& rhs);
	};

	Shape(const ShapeType& type);

	void Move(const MoveDirection& direction);
	ShapePosition GetPosition() const;

private:
	ShapePosition m_position;
};








class State
{
public:
	enum class StateType : uint32_t
	{
		Start,
		MainMenu,
		GameScreen,
		End
	};
	State(const StateType& id);

	StateType GetStateType() const;

	friend bool operator==(const State& lhs, const State& rhs);
	friend bool operator<(const State& lhs, const State& rhs);
private:
	StateType m_id;
};
	
class StateManager
{
public:
	StateManager() = default;

	void Add(const State& state);
	bool Remove(const State& state);
	bool MoveToNextState(const State& state);

	int Size();
private:
	std::set<State> m_states;
};










Playfield::Playfield(uint32_t h, uint32_t w)
	:	m_height(h), m_width(w)
{

}



Shape::Shape(const ShapeType& type)
	: m_position({ 0, 0 })
{
	
}

inline bool operator==(const Shape::ShapePosition& lhs, const Shape::ShapePosition& rhs)
{
	return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

void Shape::Move(const MoveDirection& direction)
{
	switch (direction)
	{
	case MoveDirection::Right:
		m_position.x++;
		break;
	case MoveDirection::Left:
		if (m_position.x > 0)
			m_position.x--;
		break;
	default:
		break;
	}
}

inline Shape::ShapePosition Shape::GetPosition() const
{
	return m_position;
}














State::State(const StateType& id)
	:	m_id(id)
{

}

inline State::StateType State::GetStateType() const
{
	return m_id;
}

inline bool operator==(const State& lhs, const State& rhs)
{
	return lhs.GetStateType() == rhs.GetStateType();
}

inline bool operator<(const State& lhs, const State& rhs)
{
	return lhs.GetStateType() < rhs.GetStateType();
}








void StateManager::Add(const State& state)
{
	m_states.insert(state);
}

bool StateManager::Remove(const State& state)
{
	auto it = std::find(m_states.begin(), m_states.end(), state);
	bool state_exists = (it != m_states.end());
	m_states.erase(it, m_states.end());
	return state_exists;
}

bool StateManager::MoveToNextState(const State& state)
{
	auto it = std::find(m_states.begin(), m_states.end(), state);
	bool state_exists = (it != m_states.end());
	if (state_exists)
		return true;
	else
		return false;
}


int StateManager::Size()
{
	return m_states.size();
}


#endif // !TETRIS_H
