#include <iostream>

using namespace std;

int BinarySearch(int arr[], int left, int right, int target)
{

    int result;
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (target > arr[mid])
    {
        result = BinarySearch(arr, mid + 1, right, target);
    }
    else if (arr[mid] == target)
    {
        for (int i = mid - 1; i>=left; i--)
        {
            if( arr[i] == target)
            {
                mid--;
            }
            else
            {
                break;
            }
        }
        
        return mid;
    }
    else
    {
        result = BinarySearch(arr, left, mid - 1, target);
    }

    return result;
}

int main()
{
    int n;

    cin >> n;

    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int m;
    cin >> m;

    int numbersToCheck[m];

    for (int i = 0; i < m; i++)
    {
        cin >> numbersToCheck[i];
    }

    int result;

    for (int i = 0; i < m; i++)
    {
        result = BinarySearch(&numbers[0], 0, n - 1, numbersToCheck[i]);
        cout << result << " ";
    }

    return 0;
}