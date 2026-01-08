#include <iostream>
using namespace std;
string biggestoddd(string num)
{
    int j = num.size() - 1;
    while (j >= 0)
    {
        if ((num[j] - '0') % 2 == 1)
        {
            return num.substr(0, j + 1);
        }

        if (j == 0 && (num[j] - '0') % 2 == 0)
        {
            return "";
        }
        else
        {
            j--;
        }   
    }


}
int main()
{
    cout << biggestoddd("1") << endl;
    return 0;
}