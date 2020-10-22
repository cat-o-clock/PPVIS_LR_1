#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1_PPVIS_Sem1/Rectangle.h"
#include "../Lab_1_PPVIS_Sem1/Exception.h"
#include "C:\Users\Xiaomi\source\repos\Lab_1_PPVIS_Sem1\Lab_1_PPVIS_Sem1\Exception.cpp"
#include "C:\Users\Xiaomi\source\repos\Lab_1_PPVIS_Sem1\Lab_1_PPVIS_Sem1\Rectangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(DefaultConstructorTests)
		{   
			Rectangle R; 
			Assert::IsTrue(R.GetX1() == 0);
			Assert::IsTrue(R.GetX2() == 0);
			Assert::IsTrue(R.GetY1() == 0);
			Assert::IsTrue(R.GetY2() == 0); 
		}
		TEST_METHOD(ParameterConstructorTests)
		{
			Rectangle r(1, 2, 3, 4);
			Assert::IsTrue(r.GetX1() == 1);
			Assert::IsTrue(r.GetX2() == 3);
			Assert::IsTrue(r.GetY1() == 2);
			Assert::IsTrue(r.GetY2() == 4);  
		}
		TEST_METHOD(SetRectangleTests)
		{
			Rectangle r;
			r.SetRectangle(2, 3, 1, 2);
			Assert::IsTrue(r.GetX1() == 1);
			Assert::IsTrue(r.GetX2() == 2);
			Assert::IsTrue(r.GetY1() == 2);
			Assert::IsTrue(r.GetY2() == 3);
		}
		TEST_METHOD(MoveRectungleTest)
		{
			Rectangle r;
			r.SetRectangle(2, 3, 1, 2);
			int dx = -1, dy = 0;
			r.MoveRectungle(dx, dy);
			Assert::IsTrue(r.GetX1() == 1 + dx);
			Assert::IsTrue(r.GetX2() == 2 + dx);
			Assert::IsTrue(r.GetY1() == 2 + dy);
			Assert::IsTrue(r.GetY2() == 3 + dy);
		}
		TEST_METHOD(ResizeRectungleTest)
		{
			Rectangle r;
			r.SetRectangle(2, 3, 1, 2);
			int d = 2;

			r.ResizeRectungle(d);
			Assert::IsTrue(r.GetX2() == 2 * d);
		}
	};
}
