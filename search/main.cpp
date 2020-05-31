#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

void PrintFirstFifty(int* array, string str) {
    cout << "First 50 " + str + " elements: ";
    for (int i = 0; i < 50; ++i)
        cout << array[i] << " ; ";
    cout << endl;
}

void Swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void FillMassiveForRandom(int* array, int size, int range_min, int range_max) {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < size; ++i)
        array[i] = rand() % (range_max - range_min + 1) + range_min;
}

int BinSearch(int* arr, int leftBorder, int rightBorder, int element)
{
    int middle;
    while (leftBorder <= rightBorder)
    {
        middle = (leftBorder + rightBorder) / 2;
        if (element > arr[middle]) leftBorder = middle + 1;
        else if (element < arr[middle]) rightBorder = middle - 1;
        else return middle;
    }
    return -1;
}

int RecursiveBinSearch(int* arr, int leftBorder, int rightBorder, int element) {
    int middle = (rightBorder + leftBorder) / 2;
    if (arr[middle] == element)
        return middle;
    if (middle == rightBorder || middle == leftBorder)
        return -1;
    if (arr[middle] > element)
        return RecursiveBinSearch(arr, leftBorder, middle, element);
    if (arr[middle] < element)
        return RecursiveBinSearch(arr, middle, rightBorder, element);
    return -1;
}

int LinearSearch(int* array, int size, int element) {
    for (int i = 0; i < size; i++)
        if (array[i] == element)
            return i;
    return -1;
}

void QuickSort(int* arr, int start, int end) {
    int mid;
    int s = start, e = end;
    mid = arr[(s + e) / 2];
    do
    {
        while (arr[s] < mid) s++;
        while (arr[e] > mid) e--;
        if (s <= e)
        {
            Swap(&arr[s], &arr[e]);
            s++;
            e--;
        }
    } while (s < e);
    if (start < e) QuickSort(arr, start, e);
    if (s < end) QuickSort(arr, s, end);
}



int Partition(int arr[], int l, int h) {
    int x = arr[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}


void quickSortIterative(int arr[], int start, int end)
{
    auto stack = new int[end - start + 1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;
    while (top >= 0) {
        end = stack[top--];
        start = stack[top--];
        int p = Partition(arr, start, end);
        if (p - 1 > start) {
            stack[++top] = start;
            stack[++top] = p - 1;
        }
        if (p + 1 < end) {
            stack[++top] = p + 1;
            stack[++top] = end;
        }
    }
    delete[] stack;
}

int main()
{
    int arrForSearch[10000];
    FillMassiveForRandom(arrForSearch, 10000, -1000, 1000);
    int indexOfElement = LinearSearch(arrForSearch, 10000, 1);
    if (indexOfElement == -1)
        cout << "the required element was not found" << endl;
    else
        cout << "the required element under the index: " << indexOfElement << endl;


    int arrForSort[100];
    FillMassiveForRandom(arrForSort, 100, -10, 10);
    auto startTime = chrono::steady_clock::now();
    indexOfElement = LinearSearch(arrForSort, 100, 4);
    auto endTime = chrono::steady_clock::now();
    auto timeOfUnsortedLinearSearch = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    startTime = chrono::steady_clock::now();
    indexOfElement = BinSearch(arrForSort, 0, 100, 4);
    endTime = chrono::steady_clock::now();
    auto timeOfUnsortedBinarySearch = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    startTime = chrono::steady_clock::now();
    indexOfElement = RecursiveBinSearch(arrForSort, 0, 100, 4);
    endTime = chrono::steady_clock::now();
    auto timeOfUnsortedBinarySearchRecursive = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);


    PrintFirstFifty(arrForSort, "not sorted");
    QuickSort(arrForSort, 0, 99);
    PrintFirstFifty(arrForSort, "sorted");
    FillMassiveForRandom(arrForSort, 100, -10, 10);
    PrintFirstFifty(arrForSort, "not sorted");
    quickSortIterative(arrForSort, 0, 99);
    PrintFirstFifty(arrForSort, "sorted");
    startTime = chrono::steady_clock::now();
    indexOfElement = LinearSearch(arrForSearch, 100, 3);
    endTime = chrono::steady_clock::now();
    auto timeOfSortedLinearSearch = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    startTime = chrono::steady_clock::now();
    indexOfElement = BinSearch(arrForSort, 0, 100, 3);
    endTime = chrono::steady_clock::now();
    cout << "the required element under the index: " << indexOfElement << endl;
    auto timeOfSortedBinarySearch = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    startTime = chrono::steady_clock::now();
    indexOfElement = RecursiveBinSearch(arrForSort, 0, 100, 3);
    endTime = chrono::steady_clock::now();
    cout << "the required element under the index: " << indexOfElement << endl;
    auto timeOfSortedBinarySearchRecursive = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "Linear search in unsorted array is: " << timeOfUnsortedLinearSearch.count() << " ns" << endl;
    cout << "Linear search in sorted array is: " << timeOfSortedLinearSearch.count() << " ns" << endl;
    cout << "Binary search iterative in unsorted array is: " << timeOfUnsortedBinarySearch.count() << " ns" << endl;
    cout << "Binary search iterative in sorted array is: " << timeOfSortedBinarySearch.count() << " ns" << endl;
    cout << "Binary search recursive in unsorted array is: " << timeOfUnsortedBinarySearchRecursive.count() << " ns" << endl;
    cout << "Binary search recursive in sorted array is: " << timeOfSortedBinarySearchRecursive.count() << " ns" << endl;
    return 0;
}




