// CSES 1069 - Repetitions
// https://cses.fi/problemset/task/1069
// Mövzu: strings, implementation
// İdeya:
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cur = 1, best = 1;
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) cur++;
        else cur = 1;
        best = max(best, cur);
    }

    cout << best << '\n';
    return 0;
}
