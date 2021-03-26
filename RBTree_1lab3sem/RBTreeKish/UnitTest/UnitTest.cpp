#include "pch.h"
#include "CppUnitTest.h"
#include "../RBTreeKish/RBTree.h"
#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(insert_test)
		{
			RBTree<int, int> tree;
			tree.insert(1, 5);
			tree.insert(2, 4);
			tree.insert(3, 3);
			tree.insert(4, 2);
			tree.insert(5, 1);
			list<int> answer = { 2, 1, 4, 3, 5 };
			list<int> out = tree.get_keys();
			list<int>::iterator it2 = answer.begin();
			for (list<int>::iterator it1 = out.begin(); it1 != out.end(); ++it1) {
				if (*it1 != *it2) {
					Assert::Fail();
				}
				++it2;
			}
		}



		TEST_METHOD(remove_test)
		{
			RBTree<int, int> tree;
			tree.insert(1, 5);
			tree.insert(2, 4);
			tree.insert(3, 3);
			tree.insert(4, 2);
			tree.insert(5, 1);
			tree.remove(2);
			list<int> answer = { 3, 1, 4, 5 };
			list<int> out = tree.get_keys();
			list<int>::iterator it2 = answer.begin();
			for (list<int>::iterator it1 = out.begin(); it1 != out.end(); ++it1) {
				if (*it1 != *it2) {
					Assert::Fail();
				}
				++it2;
			}
		}



		TEST_METHOD(find_test)
		{
			RBTree<int, int> tree;
			tree.insert(1, 5);
			tree.insert(2, 4);
			tree.insert(3, 3);
			tree.insert(4, 2);
			tree.insert(5, 1);
			Assert::AreEqual(tree.find(2), 4);
		}



		TEST_METHOD(get_keys_test)
		{
			RBTree<int, int> tree;
			tree.insert(1, 5);
			tree.insert(2, 4);
			tree.insert(3, 3);
			tree.insert(4, 2);
			tree.insert(5, 1);
			list<int> answer = { 2, 1, 4, 3, 5 };
			list<int> out = tree.get_keys();
			list<int>::iterator it2 = answer.begin();
			for (list<int>::iterator it1 = out.begin(); it1 != out.end(); ++it1) {
				if (*it1 != *it2) {
					Assert::Fail();
				}
				++it2;
			}
		}




		TEST_METHOD(get_values_test)
		{
			RBTree<int, int> tree;
			tree.insert(1, 5);
			tree.insert(2, 4);
			tree.insert(3, 3);
			tree.insert(4, 2);
			tree.insert(5, 1);
			list<int> answer = { 4, 5, 2, 3, 1 };
			list<int> out = tree.get_values();
			list<int>::iterator it2 = answer.begin();
			for (list<int>::iterator it1 = out.begin(); it1 != out.end(); ++it1) {
				if (*it1 != *it2) {
					Assert::Fail();
				}
				++it2;
			}
		}
	};
}
