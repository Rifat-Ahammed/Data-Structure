#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n1 = 0, n2=1, count=0, fibo, num=0; 

    int n;
    cin >> n;

    while(count<n)
    {
        if(count<=1)
        {
            fibo = count;
        }
        else{
            fibo = n1+n2;
            n1 = n2;
            n2  =fibo;
            num = n1+n2;
        }
        count++;
    }
    cout<<num<<endl;

    return 0;
}