#include<bits/stdc++.h>

using namespace std;

vector<int> fibonacci(int n) {

    vector<int> fib(n);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib;
}

int main()
{
    int n, count=0;
    cin >> n;

    vector<int> res = fibonacci(n);

    for (int i = 0; i < res.size(); i++) {

        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}