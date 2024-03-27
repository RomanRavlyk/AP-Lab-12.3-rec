#include "pch.h"
#include "CppUnitTest.h"
#include "..//AP Lab 12.3 rec/AP Lab 12.3 rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			DoublyLinkedList list;

			for (int i = 0; i < 5; i++) {
				list.insert(i);
			}
			int targetValue = 4;
			list.removeBefore(targetValue);
			Assert::AreEqual(4, targetValue);
		}
	};
}
