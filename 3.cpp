#include <iostream>
#include <climits>
#include <chrono>
using namespace std;

void findMinAndMax(int arr[], int low, int high, int &min, int &max)
{

    if (low == high)
    {
        if (max < arr[low])
        {
            max = arr[low];
        }

        if (min > arr[high])
        {
            min = arr[high];
        }

        return;
    }

    if (high - low == 1)
    {
        if (arr[low] < arr[high])
        {
            if (min > arr[low])
            {
                min = arr[low];
            }

            if (max < arr[high])
            {
                max = arr[high];
            }
        }
        else
        {
            if (min > arr[high])
            {
                min = arr[high];
            }

            if (max < arr[low])
            {
                max = arr[low];
            }
        }
        return;
    }

    int mid = (low + high) / 2;

    findMinAndMax(arr, low, mid, min, max);

    findMinAndMax(arr, mid + 1, high, min, max);
}

int main()
{
    cout << "Enter the size of array: " << endl;
    int size = 0;
    cin >> size;
    int array[size];

    cout << "Enter " << size << "integers in any order : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    int max = INT_MIN, min = INT_MAX;
    auto start = std::chrono::high_resolution_clock::now();
    findMinAndMax(array, 0, size - 1, min, max);
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed_time = double(std::chrono::duration_cast<std ::chrono::milliseconds>(end - start).count());
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max;
    std::cout << "\nElapsed time : " << elapsed_time  << " ns " << std::endl;

    return 0;
}
