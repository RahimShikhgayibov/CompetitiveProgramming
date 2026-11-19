// YouKnowWho Academy (Array) R - Permutation with arrays
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/R
// Mövzu: hashmap, tezlik sayma
// İdeya: İki hashmap ilə A və B-də hər elementin sayını say; saylar eynidirsə yes.
// Mürəkkəblik: O(n)
// Upsolve: yes

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    unordered_map<int,int> freqA;
    unordered_map<int,int> freqB;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        freqA[num]++;
    }
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        freqB[num]++;
    }

    if(freqA==freqB){
        cout<<"yes"<<"\n";
    }
    else{
        cout<<"no"<<"\n";
    }
    return 0;
}
