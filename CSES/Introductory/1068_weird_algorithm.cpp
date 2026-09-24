// CSES 1068 - Weird Algorithm
// https://cses.fi/problemset/task/1068
// Mövzu: simulation
// İdeya:
// Mürəkkəblik: O(ardıcıllığın uzunluğu)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;

    cin>>n;

    while(true){

        cout<<n<<"\n";

        if(n==1)
        {
            break;
        }

        n = (n % 2 == 0) ? n/2 : n*3+1;
    }

    return 0;
}
