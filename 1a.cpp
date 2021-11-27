#include <iostream>
#include <chrono>
using namespace std;

void merge(int arr[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;

    int temp[size];

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r)
    {

        int m = (l + r) / 2;

        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);

        merge(arr, l, m, r, size);
    }
}

int main()
{
    cout << "Enter size of array: " << endl;
    int size;
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
    mergeSort(myarray, 0, (size - 1), size);
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed_time = double(std::chrono::duration_cast<std ::chrono::milliseconds>(end - start).count());
    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    std::cout << " \nElapsed time :" << elapsed_time  << " ms" << std::endl;
    return 0;
}