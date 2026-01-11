#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
        
    }
int main()
{   
    vector<int> arr = {1, 3, 2, 4, 5, 6, 7, 8, 9};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}