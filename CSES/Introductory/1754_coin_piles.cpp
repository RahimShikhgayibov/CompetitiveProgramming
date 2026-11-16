// CSES 1754 - Coin Piles
// https://cses.fi/problemset/task/1754
// Mövzu: riyazi şərt (lazım və kifayət)
// İdeya: Hər gediş 3 sikkə götürür, ona görə (a+b) 3-ə bölünməlidir; heç bir yığın digərindən 2 dəfədən çox böyük olmamalıdır.
// Mürəkkəblik: O(1) hər test
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if( ((a<=b*2) && (b<=a*2)) && (a+b)%3==0){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}
