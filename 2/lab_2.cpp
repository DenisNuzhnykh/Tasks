#include <iostream>

using namespace std;

void printArray(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int searchMax(int* start, int* end) {
    int max = INT_MIN;
    for (int i = 0; start + i < end; i++) {
        if (max < *(start + i))
            max = *(start + i);
    }
    return max;
}

void bubbleSort(int arr[],int n)
{
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n  - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
    }
}

int main()
{
    int arr[10]{1,0,50,-2,1111,32,4,1,3,5};
    int N = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, 10);
    cout << "Max element in array: " << searchMax(&arr[0], &arr[N]) << endl;
    bubbleSort(arr,N);
    cout << "Sorted array : ";
    printArray(arr, 10);
    return 0;
}