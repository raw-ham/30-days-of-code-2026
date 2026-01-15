#include <iostream>
#include <numeric>
using namespace std;

// alternative method with high time compl(Brute)
int count(int n, int a, int b, int c)
{
    int count = 0;
    int i = 1;
    int key;
    while (count < n)
    {
        if (i % a == 0 || i % b == 0 || i % c == 0)
        {
            count++;
            key = i;
        }
        i++;
    }

    return key;
}

int nthUglyNumber(int k, int A, int B, int C)
{
    int low = 1, high = 2 * (int)1e9;
    long a = long(A), b = long(B), c = long(C);
    long ab = a * b / gcd(a, b);
    long bc = b * c / gcd(b, c);
    long ac = a * c / gcd(a, c);
    long abc = a * bc / gcd(a, bc);
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
        if (cnt < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main()
{
    int n = 3, a = 2, b = 3, c = 5;
    int i = 1;
    int countk = 0;
    int key;

    cout << nthUglyNumber(n, a, b, c);
}