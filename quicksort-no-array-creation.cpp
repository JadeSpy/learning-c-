#include <iostream>     
#include <vector>       
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;
void quickSort(int*, int);
void fillRandom(int*, int,int b2);
int main() {
	//setup arrays
	int size = 200000;
	auto myints = new int[size];
	auto myints2 = new int[size];
	fillRandom(myints, size,10);
	std::copy(myints, myints + size, myints2);

	//measurement 1
	auto t1 = std::chrono::high_resolution_clock::now();
	cout << "Separation" << endl;
	quickSort(myints, size);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << endl << "Execution 1 took: "<< duration << endl;

	//measurement 2
	t1 = std::chrono::high_resolution_clock::now();
	std::sort(myints2,myints2+size);
	t2 = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << endl << "Execution 2 took: " << duration << endl;


	cout << "finished!";
	return 1;
}
void fillRandom(int* p, int size,int upTo) {
	srand(time(0));
	for (int i = 0;i < size;i++) {
		p[i] = rand() % upTo + 1;
	}
}
void quickSortSwap(int *p1, int*p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}
void quickSort(int* original, int len) {
	int split = *original;
	int greaterIndex = len - 1;
	int lesserIndex = 1;
	int* currentP;
	//rearrange stuff so smaller is left, bigger is right
	for (int i = 1;i < len;i++) {
		currentP = original + lesserIndex;
		//cout << *currentP << " compared to " << split << endl;
		if (*currentP <= split) {
			lesserIndex++;
		}
		else {
			//cout << "greater: " << *currentP <<endl;
			quickSortSwap(currentP, original + greaterIndex);
			greaterIndex--;
		}
		
	}

	//uhh, now we switch pivot element with the right most left side element. Adjust our left side length measurement accordingly.
	lesserIndex--;
	quickSortSwap(original, original + lesserIndex);
	greaterIndex++;
	//this point
	if (lesserIndex > 1) {
		quickSort(original, lesserIndex);
	}
	int greater_range = len - greaterIndex;
	if (greater_range > 1) {
		quickSort(original + greaterIndex, greater_range);
	}
}



