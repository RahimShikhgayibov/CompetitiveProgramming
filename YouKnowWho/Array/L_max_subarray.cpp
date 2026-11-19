// YouKnowWho Academy (Array) L - Max Subarray
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/L
// Mövzu: alt massivlər (i, j), running max
// İdeya: Hər başlanğıc i üçün j-ni sağa uzat, maksimumu gedə-gedə yenilə və hər addımda çap et.
// Mürəkkəblik: O(N²)
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

        for(int i=0;i<n;i++){
            int currentMax=nums[i];
            for(int j=i;j<n;j++){
                if(nums[j]>currentMax){
                    currentMax=nums[j];
                }
                cout<<currentMax<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
