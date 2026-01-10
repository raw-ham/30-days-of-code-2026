#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void sort012(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    int i = 0;
    for (int j = 0; j < freq.size(); j++)
    {
        for (int k = 0; k < freq[j]; k++)
        {
            arr[i++] = j;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
    sort012(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}