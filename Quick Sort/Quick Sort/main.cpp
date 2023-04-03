#include <iostream>
using namespace std;

int medianThree(int a, int b, int c)   //Function to find median of 3 (low, middle, high)
{
    if ((a > b) && (a>c))
        return a;
    else if ((b < a) && (b < c))
        return b;
    else
        return c;
}

int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int pivotIndex = medianThree(low, mid, high);   //sets the pivot index as the median of 3 values
 

    int pivot = arr[pivotIndex];    //sets pivot to the element at the pivotIndex
    int i = low - 1;
    for (int j = low; j < high; j++) {  
        if (arr[j] < pivot) {  //checks if current element is smaller than the pivot element

            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivotIndex]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {    //Quicksort function 
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  //before pivot
        quickSort(arr, pivotIndex + 1, high);  //after pivot
    }
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int size;
    cout << "Enter the number of values you'd like to sort: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> *(arr + i);
    }

    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "   ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "   ";
    }
    cout << endl;

    return 0;
}
