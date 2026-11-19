// YouKnowWho Academy (Array) I - Smallest Pair (optimal)
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/I
// Mövzu: prefix minimum (f(i) + g(j) ayırma)
// İdeya: (Ai−i)+(Aj+j) kimi ayır; hər j-də indiyə qədərki ən kiçik (Ai−i)-ni saxla.
// Pattern: prefix minimum. NeetCode Best Time to Buy and Sell Stock-da təkrar rast gələcəm.
// Mürəkkəblik: O(N)
// Upsolve: yes

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int bestLeft = a[0] - 0;
        int ans = INT_MAX;
        for (int j = 1; j < n; j++) {
            ans = min(ans, a[j] + j + bestLeft);
            bestLeft = min(bestLeft, a[j] - j);
        }
        cout << ans << "\n";
    }
}
