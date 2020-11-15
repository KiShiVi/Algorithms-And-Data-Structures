#include <iostream>
#include "Sort.h"
#include <stdlib.h>
#include <ctime>
#define sizeArr 100000

using namespace std;

int main() {
	int list[sizeArr];
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		for (int i = 0; i < sizeArr; i++)
			list[i] = rand() % sizeArr;
		int start = clock();
		Sort::InsertionSort(list, sizeArr);
		int finish = clock();
		cout << finish - start << endl;
	}
}