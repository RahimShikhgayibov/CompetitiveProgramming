// YouKnowWho Academy (Array) M - Replace MinMax
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/M
// Mövzu: min/max indeksi
// İdeya: Bir keçiddə min və max-ın indekslərini tap, o iki elementin yerini dəyiş, massivi çap et.
// Mürəkkəblik: O(n)
// Upsolve: yes

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mnIdx = 0, mxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[mnIdx]) mnIdx = i;
        if (a[i] > a[mxIdx]) mxIdx = i;
    }

    int temp = a[mnIdx];
    a[mnIdx] = a[mxIdx];
    a[mxIdx] = temp;

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}
