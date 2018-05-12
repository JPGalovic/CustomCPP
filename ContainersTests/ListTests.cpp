#include "stdafx.h"
#include "CppUnitTest.h"

#include "List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Container::List;

namespace ContainersTests
{
	TEST_CLASS(ListTests)
	{
	public:

		TEST_METHOD(TestAdd)
		{
			// Construct list with 10 items
			List<int> lList;

			Assert::AreEqual(0, lList.size());
			for (int i = 0; i < 10; i++)
				lList.add(i);
			Assert::AreEqual(10, lList.size());

			for (int i = 0; i < 10; i++)
				Assert::AreEqual(i, lList[i]);
		}

		TEST_METHOD(TestAppend)
		{
			// Prepare Items
			int l1 = 1;
			int l2 = 2;
			int l3 = 3;

			List<int> lList;

			// Append List
			lList.append(l1);
			lList.append(l2);
			lList.append(l3);

			// Check elements of list;
			Assert::AreEqual(l1, lList[0]);
			Assert::AreEqual(l2, lList[1]);
			Assert::AreEqual(l3, lList[2]);
		}

		TEST_METHOD(TestPrepend)
		{
			// Prepare Items
			int l1 = 1;
			int l2 = 2;
			int l3 = 3;

			List<int> lList;

			// Append List
			lList.prepend(l1);
			lList.prepend(l2);
			lList.prepend(l3);

			// Check elements of list;
			Assert::AreEqual(l3, lList[0]);
			Assert::AreEqual(l2, lList[1]);
			Assert::AreEqual(l1, lList[2]);
		}
	};
}