#include <iostream>
#include <chrono>
using namespace std;

int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, (p - 1));
        QuickSort(arr, (p + 1), e);
    }
}

int main()
{

    int size = 0;
    cout << "Enter Size of array: " << endl;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(myarray, 0, (size - 1));
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed_time = double(std::chrono::duration_cast<std ::chrono::nanoseconds>(end - start).count());
    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    std::cout << " \nElapsed time : " << elapsed_time / 1e9 << " ns" << std::endl;
    return 0;
}