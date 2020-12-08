#ifndef SORT_H
#define SORT_H

class Sort {
private:
	static void swap(int* value_1, int* value_2);
public:
	static bool isOrder(int* array, size_t size);
	static int BinarySearch(int* array, size_t size, int value);
	static void QuickSort(int* array, int left, int right);
	static void InsertionSort(int* array, size_t size);
	static void BogoSort(int* array, size_t size);
	static void CountingSort(char* array, size_t size);
};

#endif // !SORT_H