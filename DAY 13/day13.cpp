#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalHours(vector<int>& piles, int k) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k; 
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long requiredHours = totalHours(piles, mid);

            if (requiredHours <= h) {
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
};

int main() {
    Solution sol;

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum Eating Speed: " << result << endl;

    return 0;
}
