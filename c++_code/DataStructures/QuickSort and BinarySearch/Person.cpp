//----------------------------------------------------------
// CS260 Assignment 1 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include "Person.h"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

bool operator==(const Person& p1, const Person& p2){
    if(p1.kNum == p2.kNum)
        return true;
    else
        return false;
}

void copyPerson(const Person& source, Person& target){
    target.first = source.first;
    target.kNum = source.kNum;
    target.last = source.last;
    target.zipCode = source.zipCode;
}

void swapPerson(Person& person1, Person& person2){
    Person temp;
    copyPerson(person1, temp);
    copyPerson(person2, person1);
    copyPerson(temp, person2);
}

void numberSort(Person& target, Person* array, int size){
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    //start loop to find if target zipcode is less than zipcode in position 0
    for(int i=0;i<size;i++){
        try{
            if(target.zipCode <= array[i].zipCode){
                //shifting entire array to the right by 1 position until position found
                for(int r=size-1;r>=i;r--){
                    copyPerson(array[r], array[r+1]);
                }
                copyPerson(target, array[i]);
                break;
            }
        }catch(...){
            cout << "An unexpected error occured at entry " << i << endl;
        }
    }
    //log<< "Completed numberSort with " << size << "people." << endl;
}

void partialZipSort(Person* array, int start, int end) {
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    try{
        //temp array for sorting into, then copy back
        Person * sorter;
        //size of temp array based on zipsort parameters
        sorter = new Person[end - start];
        //copying first zipcode over for a point of reference
        sorter[0] = array[start];
        //go through the rest of original array, one by one, and send to sort
        for(int i=1, r=(start+1); i<(end - start); i++, r++){
            numberSort(array[r], sorter, i);
        }
        //transpose new temp array to original
        for(int i=0; i<(end-start);i++){
            copyPerson(sorter[i], array[start+i]);
        }
        //cleanup
        delete [] sorter;
    }catch(...){
        cout << "An unexpected error occured" << endl;
    }
    //log<< "Completed partialZipSort with " << (end - start) << " entries." << endl;
}

//void nameSort(Person* array, int size) {
//	//TODO
//}
//////////////////////////////////////////////////////////////////////////////////
int partitionFunct(Person arr[], int low, int high) {
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    try{
        string pivot = arr[low].last;
        int tracker = low;
        low++;
        int decision;
        while(low <= high){
            //log<< "Started decision tree at " << low << " and " << high << "." << endl;
            if(arr[low].last == arr[high].last && arr[low].kNum != arr[high].kNum){
                decision = 5;
            }
            if(arr[low].last > pivot && arr[high].last <= pivot){
                decision = 1;
                //log<< "Decision is that " << arr[low].last << " > " << pivot << " && " << arr[high].last << " <= " << pivot << "." << endl;
            }
            if(arr[low].last <= pivot && arr[high].last <= pivot){
                decision = 2;
                //log<< "Decision is that " << arr[low].last << " <= " << pivot << " && " << arr[high].last<< " <= " << pivot << "." << endl;
            }
            if(arr[low].last > pivot && arr[high].last > pivot){
                decision = 3;
                //log<< "Decision is that " << arr[low].last << " > " << pivot << " && " << arr[high].last << " > " << pivot << "." << endl;
            }
            if(arr[low].last <= pivot && arr[high].last > pivot){
                decision = 4;
                //log<< "Decision is that " << arr[low].last << " <= " << pivot << " && " << arr[high].last << " > " << pivot << "." << endl;
            }
            switch(decision){
            case 1:
                swapPerson(arr[low], arr[high]);
                low++;
                high--;
                //log<< "Completed swap from "<< low << " to " << high << "." << endl;
                break;
            case 2:
                low++;
                //log<< "Low is okay at " << low-1 << "." << endl;
                break;
            case 3:
                high--;
                //log<< "High is okay at " << high+1 << "." << endl;
                break;
            case 4:
                low++;
                high--;
                //log<< "Both low and high are fine at" << low << " and " << high << "." << endl;
                break;
            case 5:
                if(arr[low].first > arr[high].first){
                    swapPerson(arr[low], arr[high]);
                    low++;
                    high--;
                    //log<< "Sorting by first names completed for " << arr[low-1].last << " , " << arr[low-1].first << endl;
                }
                break;
            }
        }
        if(high <= low){
            swapPerson(arr[tracker], arr[high]);
            tracker = high;
            //log<< "Completed partitioning... now swapping " << arr[tracker].last << "." << endl;
            return tracker;
        }else{
            swapPerson(arr[tracker], arr[low]);
            tracker = low;
            //log<< "Completed partitioning... now swapping " << arr[tracker].last << "." << endl;
            return tracker;
        }
    }catch(...){
        cout << "An unexpected error occured." << endl;
    }
}


void quickSortInternal (Person arr[], int low, int high) {
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    try{
        if (low >= high) return; // base case : 1 or less item
        //call partitionFunction to partition range low - high
        // it will return pivot location
        int pivot = partitionFunct(arr, low, high);
        //log<< "Completed recursive call to partitionfunct with " << low << " and " << high << "." << endl;
        //recursively sort from low to pivot - 1
        //recursiely sort from pivot + 1 to high
        quickSortInternal(arr, low, pivot -1);
        //log<< "Completed recursive call to quickSortInternal with " << low << " and " << pivot-1 <<"." << endl;
        quickSortInternal(arr, pivot +1, high);
        //log<< "Completed recursive call to quickSortInternal with " << pivot+1 << " and " << high <<"." << endl;
    }catch(...){
        cout << "An unexpected error occured." << endl;
    }
}


void nameSort(Person* array, int size) {
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    quickSortInternal (array, 0, size-1);
    //log<< "Completed nameSort." << endl;
}


//////////////////////////////////////////////////////////////////////////////////
int countLastName(const std::string& lastName, const Person* array, int size) {
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    try{
        int output = 0;
        for(int i=0; i<size; i++){
            if(array[i].last == lastName){
                output++;
                //log<< "Found " << output << " " << array[i].last << " at entry " << i << "." << endl;
            }
        }
        //log<< "Found all the " << lastName << "'s." << endl;
        return output;
    }catch(...){
        cout << "An unexpected error occured." << endl;
        return 0;
    }
}

int binaryFindFirstByLastName(const std::string& value, const Person* array, int size) {
    return binaryFindFirstByLastNameHelper(value, array, 0, size-1);
}
int binaryFindFirstByLastNameHelper(const std::string& lastName, const Person* array, int low, int high){
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    try{
        if(low>high){
            return -1;
        }
        int mid = static_cast<int>((low+high)/2);
        if(array[mid].last == lastName){
            //log<< "Found " << lastName << " by binary search at " << mid << endl;
            int first = mid;
            while(array[first].last == lastName){
                if(first == 0){goto foundzero;};
                first--;
                //log<< "Now checking for " << lastName << " at position " << first;
            }
            foundzero:
            if(first != 0){first++;}
            ////log<< "First " << lastName << " is at position " << first << endl;
            return first +1;
        }else if(array[mid].last > lastName){
            ////log<< "No " << lastName << ", checking below." << endl;
            return binaryFindFirstByLastNameHelper(lastName, array, low, mid-1);
        }else{
            ////log<< "No " << lastName << ", checking above." << endl;
            return binaryFindFirstByLastNameHelper(lastName, array, mid+1, high);
        }
    }catch(...){
        cout << "An unexpected error occured." << endl;
        return 0;
    }
}

int binaryFindLastByLastName(const std::string& value, const Person* array, int size) {
    return binaryFindLastByLastNameHelper(value, array, 0, size-1);
}
int binaryFindLastByLastNameHelper(const std::string& lastName, const Person* array, int low, int high){
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    try{
        if(low>high){
            return -1;
        }
        int mid = static_cast<int>((low+high)/2);
        if(array[mid].last == lastName){
//            log << "Found " << lastName << " by binary search at " << mid << endl;
            int last = mid;
            while(array[last].last == lastName){
                last++;
                //log<< "Checking for " << lastName << " at position " << last << endl;
            }
            ////log<< "Last " << lastName << " is at position " << last-1 << endl;
            return last -1;
        }else if(array[mid].last > lastName){
            ////log<< "No " << lastName << ", checking below." << endl;
            return binaryFindLastByLastNameHelper(lastName, array, low, mid-1);
        }else{
            ////log<< "No " << lastName << ", checking above." << endl;
            return binaryFindLastByLastNameHelper(lastName, array, mid+1, high);
        }
    }catch(...){
        cout << "An unexpected error occured." << endl;
    }
}

int countLastNameInSorted(std::string lastName, const Person* array, int size) {
    //ofstream log;
    //log.open("//log.txt", ios::out | ios::app);
    try{
        int target = binaryFindFirstByLastName(lastName, array, size);
        if(target != -1){
            int output = 1;
            while(array[target+1].last == lastName){
//                log << "Found " << lastName << " by binary search at " << target << endl;
                output++;
                target++;
            }
            return output;
        }else{return 0;}
    }catch(...){
        cout << "An unexpected error occured." << endl;
        return 0;
    }
}
