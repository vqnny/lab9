#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename T> // ???
void printArray(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    string stringArray[] = {"hello", "world", "C++", "templates"};
    printArray(intArray, 5);
    printArray(charArray, 5);
    printArray(stringArray, 4);
    return 0;
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    if (start < 0 || end < 0 || start > end) {
        return false;
    }
    for (int i = start; i <= end; ++i) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}
int main() {
    string arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << (seqSearch("cherry", arr, 1, 3) ? "Found" : "Not Found") << endl;
    cout << (seqSearch("apple", arr, 2, 4) ? "Found" : "Not Found") << endl;

    return 0;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;	
}
int main() {
    float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << (binSearch(3.3, arr, size) ? "Found" : "Not Found") << endl;
    cout << (binSearch(7.7, arr, size) ? "Found" : "Not Found") << endl;

    return 0;
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchHelper(char target, char charray[], int left, int right) {
    // base case
    if (left > right) {
        return false;
    }
    int mid = left + (right - left) / 2;
    if (charray[mid] == target) {
        return true;
    }
    else if (charray[mid] < target) {
        return binSearchHelper(target, charray, left, mid - 1);
    }
}
bool binSearchR(char target, char charray[], int n)  { 
    return binSearchHelper(target, charray, 0, n - 1);
}
int main() {
    char charray[] = {'a', 'c', 'e', 'g', 'i', 'k', 'm'};
    int size = sizeof(charray) / sizeof(charray[0]);

    cout << (binSearchR('e', charray, size) ? "Found" : "Not Found") << endl;
    cout << (binSearchR('z', charray, size) ? "Found" : "Not Found") << endl;

    return 0;
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int index1, int index2) {
    double temp = darray[index1];
    darray[index1] = darray[index2];
    darray[index2] = temp;
}

int minFind(double darray[], int start, int n) {
    int minIndex = start;
    for (int i = start + 1; i < n; ++i) {
        if (darray[i] < darray[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void newSort(double darray[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = minFind(darray, i, n);
        swap(darray, i, minIndex);
    }
}
int main() {
    double darray[] = {3.5, 2.1, 5.7, 1.8, 4.3};
    int n = sizeof(darray) / sizeof(darray[0]);
    newSort(darray, n);
    for (int i = 0; i < n; ++i) {
        cout << darray[i] << " ";
    }
    cout << endl;
    return 0;
}
