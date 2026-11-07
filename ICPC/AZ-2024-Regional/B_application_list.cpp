// ICPC AZ-2024-Regional B - Application List
// (link yoxdur: 2024 Azerbaijan Regional, vjudge)
// Mövzu: hashmap, implementasiya
// İdeya: Əlifba sırası ilə hashmap saxla, sözlərin ilk hərflərini yoxla, olan hərfləri yaz, olmayanların yerinə nöqtə qoy.
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_map<char,int> m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m[s[0]]++;
    }
    for(int i=97;i<=122;i++){
        if(i==103 || i==109 || i==115 || i==121){
            cout<<"\n";
        }
        if(m.count((char)i)){
            cout<<(char)i;
        }
        else{
            cout<<".";
        }
    }
    cout<<"\n";
    return 0;
}
