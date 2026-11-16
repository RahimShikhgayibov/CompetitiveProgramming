// CSES 1618 - Trailing Zeros
// https://cses.fi/problemset/task/1618
// Mövzu: riyaziyyat, sadə vuruqlar
// İdeya: Hər sıfır bir 2·5 cütündən yaranır, 2-lər çoxdur, ona görə 5-ləri sayırıq: n-i 0 olana qədər 5-ə bölüb nəticələri toplayırıq.
// Mürəkkəblik: O(log n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;

    while(n>0){
        count+=n/5;
        n/=5;
    }
    cout << count << "\n";
    return 0;
}
