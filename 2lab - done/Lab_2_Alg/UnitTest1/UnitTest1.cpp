#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2_Alg/Sort.h"
#include "../Lab_2_Alg/Sort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(BinarySearch)
		{
			int arr[10] = { 1, 3, 4, 10, 19, 18, 43, 54, 67, 82 };
			Assert::IsTrue(Sort::BinarySearch(arr, 10, 19) == 4);
		}

		TEST_METHOD(QuickSort)
		{
			int arr[10] = { 1, 7, 2, 4, 6, 5, 3, 9, 8, 15 };
			Sort::QuickSort(arr, 0, 9);
			Assert::IsTrue(Sort::isOrder(arr, 10));
		}

		TEST_METHOD(BubbleSort)
		{
			int arr[10] = { 10, 9, 6, 2, 1, 3, 4, 8, 5, 7 };
			Sort::InsertionSort(arr, 10);
			Assert::IsTrue(Sort::isOrder(arr, 10));
		}

		TEST_METHOD(BogoSort)
		{
			int arr[10] = { 10, 9, 6, 2, 1, 3, 4, 8, 5, 7 };
			Sort::BogoSort(arr, 10);
			Assert::IsTrue(Sort::isOrder(arr, 10));
		}

		TEST_METHOD(CountingSort)
		{
			bool flag = true;
			char arr[10] = { "gcdhabef" };
			char ans[10] = { "abcdefgh" };
			Sort::CountingSort(arr, 10);
			for (int i = 0; i < 8; i++)
				if (arr[i] != ans[i])
					flag = false;
			Assert::IsTrue(flag);
		}
	};
}