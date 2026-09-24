// CSES 1083 - Missing Number
// https://cses.fi/problemset/task/1083
// Mövzu: math
// İdeya:
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    ll total = (ll)n * (n + 1) / 2;
    cout << total - sum << "\n";
}
