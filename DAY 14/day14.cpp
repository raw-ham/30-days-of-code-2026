#include <iostream>
using namespace std;

int main()
{
    int a ;
    cin >> a;
    int rem = a;
    int count = 0 ;
    while (rem != 0)
    {   
        cout<<rem<< rem % 2;
        if ((rem % 2 )== 1)
        {
            count++ ;
        }
        rem = rem/2 ;
        cout<< rem<<endl;
        
    }
    cout<<count ;
    
    return 0;
}