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



#endif // !TETRIS_H
