// YouKnowWho Academy (Array) G - Palindrome Array
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/G
// Mövzu: iki göstərici
// İdeya: Ortaya qədər a[i] ilə a[n-1-i]-ni müqayisə et; biri fərqlidirsə NO, hamısı eynidirsə YES.
// Mürəkkəblik: O(n)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }

    for(int i=0;i<n/2;i++){
        if(nums[i]!=nums[n-i-1]){
            cout<<"NO"<<"\n";
            return 0;
        }
    }
    cout<<"YES"<<"\n";
    return 0;
}
