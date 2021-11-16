#include <iostream>
using namespace std;

void buildHeap(int[], int);

int main()
{
    int arr[] = {15, 20, 7, 9, 30};
    buildHeap(arr, sizeof(arr) / sizeof( arr[0] ));

    return EXIT_SUCCESS;
}

void buildHeap(int a[], int n)
{
    // 15 20 7 9 30
    
}