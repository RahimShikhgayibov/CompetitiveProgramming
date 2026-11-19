// YouKnowWho Academy (Array) Q - Count Subarrays
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Q
// Mövzu: alt massivlər (i, j)
// İdeya: Hər başlanğıc i üçün j-ni sağa uzat, a[j] ≥ a[j−1] olduqca say, pozulanda dayan.
// Mürəkkəblik: O(N²)  (optimal O(N): hər j-də bitən azalmayan ardıcıllığın uzunluğunu topla)
// Upsolve: yes

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        vector<int> nums;

        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            nums.push_back(num);
        }

        int subarrayCount=0;
        for(int i=0;i<n;i++){
            subarrayCount++;
            for(int j=i+1;j<n;j++){
                if(nums[j]>=nums[j-1]){
                    subarrayCount++;
                }
                else{
                    break;
                }
            }
        }
        cout<<subarrayCount<<"\n";
    }
    return 0;
}
