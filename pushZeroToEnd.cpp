#include <iostream>
using namespace std;

void pushZeroEnd(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] == 0)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//better approach (two pointer) O(n)
void pushzeroes(int *nums, int n)
{
    if (n == 1)
    {
        return;
    }
    int l = 0;
    int r = 1;
    while (r < n)
    {
        if (nums[l] == 0 && nums[r] == 0)
        {
            r++;
        }
        else
        {
            if (nums[l] == 0 && nums[r] != 0)
            {
                swap(nums[l], nums[r]);
                l++;
                r++;
            }
            else
            {
                l++;
                r++;
            }
        }
    }
}

int main()
{
    int arr[] = {0, 0, 1, 4, 1, 0, 9};
    // pushZeroEnd(arr, 7);
    pushzeroes(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
