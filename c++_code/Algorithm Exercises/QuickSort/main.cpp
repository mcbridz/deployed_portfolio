#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

void genNums(int arr[], int arrSize);


///------------------Quick Sort-----------------------------

//Postcondition: array is partitioned around some index p
//   such that for all i < p arr[i] <= A[p] and
//             for all j > p arr[j] >= A[p]
//  Returns index of p
int partitionFunct(int arr[], int low, int high) {
    int pivot = arr[low];
    int tracker = low;
    low++;
    int decision;
    while(low <= high){
        if(arr[low] > pivot && arr[high] <= pivot){
            decision = 1;
        }
        if(arr[low] <= pivot && arr[high] <= pivot){
            decision = 2;
        }
        if(arr[low] > pivot && arr[high] > pivot){
            decision = 3;
        }
        if(arr[low] <= pivot && arr[high] > pivot){
            decision = 4;
        }
        int temp;
        switch(decision){
        case 1:
            temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
            low++;
            high--;
            break;
        case 2:
            low++;
            break;
        case 3:
            high--;
            break;
        case 4:
            low++;
            high--;
            break;
        }
    }
    if(high <= low){
        int temp = arr[high];
        arr[high]= arr[tracker];
        arr[tracker] = temp;
        tracker = high;
        return tracker;
    }else{
        int temp = arr[low];
        arr[low]= arr[tracker];
        arr[tracker] = temp;
        tracker = low;
        return tracker;
    }
}


void quickSortInternal (int arr[], int low, int high) {
    if (low >= high) return; // base case : 1 or less item
    //call partitionFunction to partition range low - high
    // it will return pivot location
    int pivot = partitionFunct(arr, low, high);
    //recursively sort from low to pivot - 1
    //recursiely sort from pivot + 1 to high
    quickSortInternal(arr, low, pivot -1);
    quickSortInternal(arr, pivot +1, high);
}


void quickSort (int arr[], int arrSize) {
    quickSortInternal (arr, 0, arrSize-1);
}



///--------------No Need to Modify Below This Line -----------


//Fill array with random values 0-999,999
void genNums(int arr[], int arrSize) {
    default_random_engine generator;
    generator.seed(static_cast<unsigned int>(time(nullptr)));  //sequence based on time
    //generator.seed(1);            //same sequence each time

    uniform_int_distribution<int> distribution(0,999999);

    for(int i = 0; i < arrSize; i++)
        arr[i] = distribution(generator);
}


int main()
{
    ///------------Function testing----------------
    //    cout << "Testing partition function:" << endl;
//    int temp2[10]  = {12, 18, 3, 20, 6, 7, 15, 2, 24, 17};
//    cout << "Initial state : " << endl << " ";
//    for(int i : temp2) cout << i << " ";
//    cout << endl;
//    quickSort(temp2,10);
//    cout << "End state: " << endl << " ";
//    for(int i: temp2) cout << i << " ";
    //    int newPartLoc = partitionFunct(temp2, 0, 9);
    //    cout << "Partition returned location: " << newPartLoc << " which has value: " << temp2[newPartLoc] << endl;
    //    cout << " Verify all items to the left of that are smaller and all to the right are bigger" << endl;
    //    for(int i : temp2) cout << i << " ";
    //    cout << endl << endl;

    ///------------Actual sort testing----------------

    cout << endl << "Testing quickSort..." << endl;
    const int BIG_SIZE = 100000;

    int* bigNums = new int[BIG_SIZE];
    genNums(bigNums, BIG_SIZE);

    clock_t start= clock();
    quickSort(bigNums, BIG_SIZE);
    clock_t duration = clock() - start;

    if(std::is_sorted(bigNums, bigNums + BIG_SIZE)) {
        cout << "quickSort took: " << duration << endl;
    } else {
        cout << "quickSort failed!!" << endl;
    }

    return 0;
}

