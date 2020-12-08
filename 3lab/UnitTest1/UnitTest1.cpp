#include "pch.h"
#include "CppUnitTest.h"
#include "../3_lab_alg/BST.h"
#include "../3_lab_alg/BST.inl"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Contains_Test)
		{
			BinaryTree<int>* binarytree = new BinaryTree<int>;
			binarytree->insert(8);
			binarytree->insert(3);
			binarytree->insert(1);
			binarytree->insert(6);
			binarytree->insert(4);
			binarytree->insert(7);
			binarytree->insert(10);
			binarytree->insert(14);
			binarytree->insert(13);
			Assert::IsTrue(binarytree->contains(4) && 
							binarytree->contains(8) &&
							binarytree->contains(14));
		}

		TEST_METHOD(Insert_Test)
		{
			BinaryTree<int>* binarytree = new BinaryTree<int>;
			binarytree->insert(8);
			binarytree->insert(3);
			binarytree->insert(1);
			binarytree->insert(6);
			binarytree->insert(4);
			binarytree->insert(7);
			binarytree->insert(10);
			binarytree->insert(14);
			binarytree->insert(13);
			Assert::IsTrue(	binarytree->contains(4) &&
							binarytree->contains(8) &&
							binarytree->contains(14));
		}

		TEST_METHOD(Remove_Test)
		{
			BinaryTree<int>* binarytree = new BinaryTree<int>;
			binarytree->insert(8);
			binarytree->insert(3);
			binarytree->insert(1);
			binarytree->insert(6);
			binarytree->insert(4);
			binarytree->insert(7);
			binarytree->insert(10);
			binarytree->insert(14);
			binarytree->insert(13);
			binarytree->remove(14);
			binarytree->remove(8);
			Assert::IsFalse(binarytree->contains(14) &&
							binarytree->contains(8));
		}

		TEST_METHOD(bft_iterator_Test)
		{
			BinaryTree<int>* binarytree = new BinaryTree<int>;
			binarytree->insert(8);
			binarytree->insert(3);
			binarytree->insert(1);
			binarytree->insert(6);
			binarytree->insert(4);
			binarytree->insert(7);
			binarytree->insert(10);
			binarytree->insert(14);
			binarytree->insert(13);

			int list[9];
			int ans[9]{8,3,10,1,6,14,4,7,13};

			BinaryTree<int>::bft_iterator it(binarytree->begin());
			for (int i = 0; i < 9; i++) {
				++it;
				list[i] = *it;
				Assert::AreEqual(list[i], ans[i]);
			}
		}

		TEST_METHOD(dft_iterator_Test)
		{
			BinaryTree<int>* binarytree = new BinaryTree<int>;
			binarytree->insert(8);
			binarytree->insert(3);
			binarytree->insert(1);
			binarytree->insert(6);
			binarytree->insert(4);
			binarytree->insert(7);
			binarytree->insert(10);
			binarytree->insert(14);
			binarytree->insert(13);

			int list[9];
			int ans[9]{ 8,3,1,6,4,7,10,14,13 };

			BinaryTree<int>::dft_iterator it(binarytree->begin());
			for (int i = 0; i < 9; i++) {
				list[i] = *it;
				++it;
				Assert::AreEqual(list[i], ans[i]);
			}
		}

	};
}
