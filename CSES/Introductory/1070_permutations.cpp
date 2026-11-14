// CSES 1070 - Permutations
// https://cses.fi/problemset/task/1070
// Mövzu: konstruksiya, kiçik hallardan pattern
// İdeya: n=4 və n=5 üçün düzülüşləri əllə yazıb pattern tapdım: əvvəl cüt ədədləri, sonra təkləri yaz; n=2 və 3 üçün həll yoxdur.
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

    if(n<=3 && n!=1){
        cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=2;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    return 0;
}
