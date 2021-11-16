#include <iostream>
using namespace std;

void insertionSort(int* , int);
void print(int*, int);

int main()
{
    int arr[] = {6, 3, 2, 7, 4, 2, 8, 6, 4, 2, 4, 0, 1};
    int len = sizeof(arr) / sizeof(arr[0]);


    cout << "Before: "; print(arr, len);

    insertionSort(arr, len);

    cout << "After: "; print(arr, len);


    

    return 0;
}

void print(int* arr, int size)
{
    for(int i=0; i<size; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

void insertionSort(int* arr, int size)
{
    for(int i=1; i<size; ++i)
    {
        int temp = arr[i];

        int j = 1;
        while(i-j >= 0 && arr[i - j] > temp)
        {
            arr[i-j+1] = arr[i-j];
            ++j;
        }

        arr[i-j+1] = temp;
    }
}