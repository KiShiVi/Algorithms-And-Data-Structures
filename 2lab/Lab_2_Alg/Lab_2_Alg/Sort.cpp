#include "Sort.h"
#include <ctime>
#include <stdlib.h>

void Sort::swap(int* value_1, int* value_2) {
    int temp;
    temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}


bool Sort::isOrder(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++)
        if (array[i] > array[i + 1])
            return false;
    return true;
}

int Sort::BinarySearch(int* array, size_t size, int value) {
	size_t	left		= 0,
			right		= size - 1,
			middle		= 0;
	while (left <= right) {
		middle = (right + left) / 2;
		if (array[middle] == value)
			return middle;
		else if (array[middle] > value)
			right = middle - 1;
		else if (array[middle] < value)	
			left = middle + 1;
	}
	return -1;
}

void Sort::QuickSort(int* array, int left, int right) {
        int i       = left;
        int j       = right;
        int pivot   = array[(i + j) / 2];
        while (i <= j){
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;
            if (i <= j){
                Sort::swap(&array[i], &array[j]);
                i++;
                j--;
            }
        }
        if (j > left)
            QuickSort(array, left, j);
        if (i < right)
            QuickSort(array, i, right);
}



void Sort::InsertionSort(int* array, size_t size) {
    int temp,
        item;
    for (int counter = 1; counter < size; counter++)
    {
        temp = array[counter];
        item = counter - 1;
        while (item >= 0 && array[item] > temp)
        {
            array[item + 1] = array[item];
            array[item] = temp;
            item--;
        }
    }
}


void Sort::BogoSort(int* array, size_t size) {
    srand(time(0));
    while (!Sort::isOrder(array, size)) {
        for (int i = 0; i < size; i++) {
            Sort::swap(&array[i], &array[rand() % size]);
        }
    }
}


void Sort::CountingSort(char* array, size_t size) {
    char* out = new char[size];
    int count[256], i;              //256, т.к. рассчитываем только на значение char 0/256
    for (int i = 0; i < 256; i++)
        count[i] = 0;
    for (i = 0; array[i]; i++)
        count[array[i]]++;
    for (i = 1; i <= 255; i++)
        count[i] += count[i - 1];
    for (i = 0; array[i]; ++i) {
        out[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (i = 0; i < size-1; ++i)
        array[i] = out[i];
}