#include "pch.h"
#include "CppUnitTest.h"
#include "tetris.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTDDTests
{
	TEST_CLASS(PlayfieldTests)
	{
	public:

		TEST_METHOD(HasNoDefaultConstructor)
		{
			Assert::IsFalse(std::is_default_constructible<Playfield>::value);
		}

		TEST_METHOD(CanBeInitializedWithHeightAndWidth)
		{
			Playfield field(16, 10);
		}

	};

	TEST_CLASS(ShapeTests)
	{
		TEST_METHOD(HasNoDefaultConstructor)
		{
			Assert::IsFalse(std::is_default_constructible<Shape>::value);
		}

		TEST_METHOD(CanBeInitializedWithAShapeType)
		{
			Shape shape(Shape::ShapeType::Straight);
		}

		TEST_METHOD(CanBeMovedInADirection)
		{
			Shape shape(Shape::ShapeType::Straight);

			auto is_equal = [](const Shape::ShapePosition& lhs, const Shape::ShapePosition& rhs)
			{
				return lhs == rhs;
			};
		
			auto pos = shape.GetPosition();
			shape.Move(Shape::MoveDirection::Left);
			auto pos2 = shape.GetPosition();
			Assert::IsFalse(is_equal(pos, pos2));
			shape.Move(Shape::MoveDirection::Right);
			auto pos3 = shape.GetPosition();
			Assert::IsTrue(is_equal(pos, pos3));
		}

		TEST_METHOD(CannotHaveNegativePosition)
		{
			Shape shape(Shape::ShapeType::Straight);

			auto is_not_negative = [](const Shape::ShapePosition& shape)
			{
				return (shape.x >= 0) && (shape.y >= 0);
			};

			auto pos = shape.GetPosition();
			Assert::IsTrue(is_not_negative(pos));
			shape.Move(Shape::MoveDirection::Left);
			auto pos2 = shape.GetPosition();
			Assert::IsTrue(is_not_negative(pos2));
		}

		TEST_METHOD(CannotHavePositionGreaterThanPlayField)
		{
			Shape shape(Shape::ShapeType::Straight);

			auto is_smaller_than_play_field = [](const Shape::ShapePosition& shape)
			{
				return (shape)
			}
		}
	};


	TEST_CLASS(StateManagerTests)
	{
		TEST_METHOD(CanHaveStatesAddedAndRemoved)
		{
			StateManager sm;
			sm.Add(State::StateType::Start);
			Assert::AreEqual(sm.Remove(State::StateType::Start), true);
		}

		TEST_METHOD(CanHaveStatesRemovedOnlyWhenPreviouslyAdded)
		{
			StateManager sm;
			Assert::AreEqual(sm.Remove(State::StateType::Start), false);
			sm.Add(State::StateType::End);
			Assert::AreEqual(sm.Remove(State::StateType::End), true);
			Assert::AreEqual(sm.Remove(State::StateType::End), false);

		}
		TEST_METHOD(CanOnlyHaveUniqueStates)
		{
			StateManager sm;
			sm.Add(State::StateType::Start);
			sm.Add(State::StateType::Start);
			Assert::AreEqual(sm.Size(), 1);
			sm.Add(State::StateType::End);
			Assert::AreEqual(sm.Size(), 2);
		}

		TEST_METHOD(CanMoveBetweenStates)
		{
			StateManager sm;
			Assert::IsFalse(sm.MoveToNextState(State::StateType::Start));
			sm.Add(State::StateType::Start);
			Assert::IsTrue(sm.MoveToNextState(State::StateType::Start));
			sm.Add(State::StateType::End);
			Assert::IsTrue(sm.MoveToNextState(State::StateType::End));
			Assert::IsTrue(sm.MoveToNextState(State::StateType::Start));
		}
	};

	TEST_CLASS(StateTest)
	{
		TEST_METHOD(HasNoDefaultConstructor)
		{
			Assert::AreEqual(std::is_default_constructible<State>::value, false);
		}

		TEST_METHOD(CanHaveStateTypes)
		{
			State state(State::StateType::Start);
			auto is_type = [&state](const State::StateType& state_type)
			{
				return state.GetStateType() == state_type;
			};
			Assert::IsTrue(is_type(State::StateType::Start));
			Assert::IsFalse(is_type(State::StateType::End));
		}
	};
}
