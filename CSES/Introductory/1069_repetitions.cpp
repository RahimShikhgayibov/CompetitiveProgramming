// CSES 1069 - Repetitions
// https://cses.fi/problemset/task/1069
// Mövzu: string, running max
// İdeya:
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int overallCount=1;
    int temp=1;
    for(int i=s.size()-1;i>0;i--){
        if(s[i]==s[i-1]){
            temp++;
        }
        else{
            temp=1;
        }
        if(temp>overallCount){
            overallCount=temp;
        }
    }
    cout<<overallCount<<"\n";
    return 0;
}
