// CSES 1094 - Increasing Array
// https://cses.fi/problemset/task/1094
// Mövzu: greedy
// İdeya:
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long prev, x;
    long long moves = 0;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x < prev) {
            moves += prev - x;
        } else {
            prev = x;
        }
    }

    cout << moves << '\n';
}
