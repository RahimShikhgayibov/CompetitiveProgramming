// CSES 1094 - Increasing Array
// https://cses.fi/problemset/task/1094
// Mövzu: greedy, running max, long long
// İdeya:
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int prev=0;
    long long count=0;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(prev>a){
            count=count + prev-a;
            a=prev;
        }
        prev=a;
    }
    cout<<count<<"\n";
    return 0;
}
