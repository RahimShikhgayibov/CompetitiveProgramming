// CSES 1071 - Number Spiral
// https://cses.fi/problemset/task/1071
// Mövzu: riyazi müşahidə, Manhattan məsafəsi
// İdeya: Qat k = max(sətir, sütun); qatın son ədədi k², cüt k-da (k,1), tək k-da (1,k) xanasındadır; cavab = k² − son xanaya qədər məsafə.
// Mürəkkəblik: O(1) hər test
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;

    for(int i=0;i<n;i++){
        long long y,x;
        cin >> y >> x;
        long long k = max(y,x);
        long long lastNumber= k*k;

        long long distance=0;
        if(k%2==0){
            distance = abs(y-k) + abs(x-1);
        }else{
            distance = abs(y-1) + abs(x-k);
        }

        long long number = lastNumber - distance;
        cout<<number<<"\n";
    }
    return 0;
}
