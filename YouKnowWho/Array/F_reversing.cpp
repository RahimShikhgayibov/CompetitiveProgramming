// YouKnowWho Academy (Array) F - Reversing
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/F
// Mövzu: iki göstərici, yerində çevirmə
// İdeya: Ortaya qədər a[i] ilə a[n-1-i]-ni temp ilə dəyiş (iki göstərici), sonra çap et.
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> array;

    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        array.push_back(element);
    }

    int index=0;
    for(int i=n-1;i>=n/2;i--){
        int temp=array[i];
        array[i]=array[index];
        array[index]=temp;
        index++;
    }

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
