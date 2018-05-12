#include "stdafx.h"
#include "CppUnitTest.h"

#include "DLNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Container::DLNode;

namespace ContainersTests
{		
	TEST_CLASS(DLNodeTests)
	{
	public:
		
		TEST_METHOD(TestAppend)
		{
			// Setup Variables
			int l1 = 1;
			int l2 = 2;
			int l3 = 3;
			int l4 = 4;
			
			typedef DLNode<int> IntNode;

			IntNode lN1 = IntNode(l1);
			IntNode lN2 = IntNode(l2);
			IntNode lN3 = IntNode(l3);
			IntNode lN4 = IntNode(l4);

			// Append Lists
			lN1.append(lN4);
			lN1.append(lN3);
			lN1.append(lN2);
			
			// Check Results
			int i = 0;
			for (const IntNode* lP = &lN1; lP != &IntNode::NIL; lP = &lP->getNext())
			{
				i++;
				Assert::AreEqual(i, lP->getValue());
			}
		}

		TEST_METHOD(TestPrepend)
		{
			// Setup Variables
			int l1 = 1;
			int l2 = 2;
			int l3 = 3;
			int l4 = 4;

			typedef DLNode<int> IntNode;

			IntNode lN1 = IntNode(l1);
			IntNode lN2 = IntNode(l2);
			IntNode lN3 = IntNode(l3);
			IntNode lN4 = IntNode(l4);

			// Append Lists
			lN4.prepend(lN1);
			lN4.prepend(lN2);
			lN4.prepend(lN3);

			// Check Results
			int i = 0;
			for (const IntNode* lP = &lN1; lP != &IntNode::NIL; lP = &lP->getNext())
			{
				i++;
				Assert::AreEqual(i, lP->getValue());
			}
		}

	};
}