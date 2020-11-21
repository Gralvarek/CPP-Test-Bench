#include "pch.h"
#include "CppUnitTest.h"
#include "tetris.h"
#include "state.h"

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
			/*
			auto is_smaller_than_play_field = [](const Shape::ShapePosition& shape)
			{
				return (shape);
			};
			*/
		}
	};


	TEST_CLASS(StateMachineTests)
	{
		TEST_METHOD_INITIALIZE(StateMachineGraph)
		{
			std::unordered_map<State, > map =
			{
				{StateType::START, }
			};
			
		}

		TEST_METHOD(CanHaveStatesAddedAndRemoved)
		{
			StateMachine sm(map);
			sm.Add(StateType::START);
			Assert::AreEqual(sm.Remove(StateType::START), true);
		}

		TEST_METHOD(CanHaveStatesRemovedOnlyWhenPreviouslyAdded)
		{
			StateMachine sm(map);
			Assert::AreEqual(sm.Remove(StateType::START), false);
			sm.Add(StateType::END);
			Assert::AreEqual(sm.Remove(StateType::END), true);
			Assert::AreEqual(sm.Remove(StateType::END), false);

		}
		TEST_METHOD(CanOnlyHaveUniqueStates)
		{
			StateMachine sm;
			sm.Add(StateType::START);
			sm.Add(StateType::START);
			Assert::AreEqual(sm.Size(), 1);
			sm.Add(StateType::END);
			Assert::AreEqual(sm.Size(), 2);
		}

		TEST_METHOD(CanMoveBetweenStates)
		{
			StateMachine sm;
			Assert::IsFalse(sm.MoveToNextState(StateType::START));
			sm.Add(StateType::START);
			Assert::IsTrue(sm.MoveToNextState(StateType::START));
			sm.Add(StateType::END);
			Assert::IsTrue(sm.MoveToNextState(StateType::END));
			Assert::IsTrue(sm.MoveToNextState(StateType::START));
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
			State state(StateType::START);
			auto is_type = [&state](const StateType& state_type)
			{
				return state.GetStateType() == state_type;
			};
			Assert::IsTrue(is_type(StateType::START));
			Assert::IsFalse(is_type(StateType::END));
		}
	};
}
