// ICPC NERC 2023-2024 A - Absolutely Flat
// https://codeforces.com/gym/104772/problem/A
// Mövzu: implementasiya, müşahidə
// İdeya:
// Mürəkkəblik: O(1)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1,a2,a3,a4,b;
    cin>>a1>>a2>>a3>>a4>>b;

    if(a1+b == a2 && a2==a3 && a3==a4 || a1 == a2 && a2==a3 && a3==a4){
        cout<<"1";
    }else if(a2+b == a3 && a4==a3 && a1==a4){
        cout<<"1";
    }else if(a3+b == a2 && a2==a4 && a1==a4){
        cout<<"1";
    }else if(a4+b == a2 && a2==a3 && a1==a3){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
