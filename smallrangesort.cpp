#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <algorithm>
#include <thread>
using namespace std;

void fillRandom(int* p, int size, int upTo) {
    srand(time(0));
    for (int i = 0;i < size;i++) {
        p[i] = rand() % upTo + 1;
    }
}



void smallrangesort(int* start, int length, int range1, int range2) {//sorts by storing values at the index of their numerical value
    int* sortstorage = new int[range2 - range1]{};
    //write
    for (int i = 0;i < length; i++) {
        sortstorage[start[i]-range1-1] += 1;
    }
    //read
    int index = 0;
    for (int i = 0;i < range2-range1;i++) {
        for (int j = 0;j < sortstorage[i];j++) {
            start[index] = i+1 + range1;;
            index++;
            //cout << index << "\n";
        }
    }
    delete[] sortstorage;





}







int main()
{
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    auto t1 = std::chrono::high_resolution_clock::now();


    int rangemax = 3;
    int size = 100000000;
    int* x = new int[size];
    int* x2 = new int[size];
    fillRandom(x, size,rangemax);
    for (int i = 0;i < size;i++) {
        x2[i] = x[i];
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << endl << "Execution 0 took: " << duration << endl;


    t1 = std::chrono::high_resolution_clock::now();
    smallrangesort(x, size, 0, rangemax);
    t2 = std::chrono::high_resolution_clock::now();
     duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << endl << "Execution 1 took: " << duration << endl;


    t1 = std::chrono::high_resolution_clock::now();
    std::sort(x2, x2 + size);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << endl << "Execution 2 took: " << duration << endl;
}

