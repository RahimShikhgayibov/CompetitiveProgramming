// Codeforces 4A - Watermelon (Beta Round #4, Div. 2)
// https://codeforces.com/contest/4/problem/A
// Mövzu: math
// İdeya: 
// Mürəkkəblik: O(1)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;          // overflow refleksi: şübhə varsa -> ll
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin>> n;

    if(n%2==0 and n!=2) cout<< "YES\n";
    else cout<< "NO\n";
}

int main() {
    ios::sync_with_stdio(false);   // fast I/O
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;                   // CF-də çox test varsa bu sətri aç
    while (t--) solve();
    return 0;
}
