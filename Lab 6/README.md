## **Bubble Sort**

Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the array is sorted.

| Metric | Complexity | Note |
| --- | --- | --- |
| **Best Case** | O(n) | Occurs when the array is already sorted (if optimized with a swap flag). |
| **Average Case** | O(n²) | Elements are in random order. |
| **Worst Case** | O(n²) | Occurs when the array is reverse sorted. |
| **Space Complexity** | O(1) | In-place sorting algorithm; requires no extra memory. |

```cpp
#include <iostream>
using namespace std;

// Optimized Bubble Sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, array is sorted
        if (!swapped)
            break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Unsorted array: ";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "Sorted array (Bubble Sort): ";
    printArray(arr, n);
    
    return 0;
}

```

---

## **Insertion Sort**

Insertion Sort builds the final sorted array one item at a time. It iterates through the input array, removes one element, finds the location it belongs within the sorted portion, and inserts it there.

| Metric | Complexity | Note |
| --- | --- | --- |
| **Best Case** | O(n) | Occurs when the array is already sorted. |
| **Average Case** | O(n²) | Elements are in random order. |
| **Worst Case** | O(n²) | Occurs when the array is reverse sorted. |
| **Space Complexity** | O(1) | In-place sorting algorithm. |

```cpp
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Unsorted array: ";
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    cout << "Sorted array (Insertion Sort): ";
    printArray(arr, n);
    
    return 0;
}

```

---

## **Selection Sort**

Selection Sort divides the input array into two parts: a sorted subarray and an unsorted subarray. It repeatedly selects the smallest element from the unsorted subarray and swaps it with the leftmost unsorted element.

| Metric | Complexity | Note |
| --- | --- | --- |
| **Best Case** | O(n²) | It always scans the remaining elements to find the minimum. |
| **Average Case** | O(n²) | Elements are in random order. |
| **Worst Case** | O(n²) | Requires scanning the remaining array every time. |
| **Space Complexity** | O(1) | In-place sorting algorithm. |

```cpp
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Unsorted array: ";
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    cout << "Sorted array (Selection Sort): ";
    printArray(arr, n);
    
    return 0;
}

```
