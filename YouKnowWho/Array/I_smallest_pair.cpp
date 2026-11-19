// YouKnowWho Academy (Array) I - Smallest Pair
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/I
// Mövzu: bütün cütlər (brute force)
// İdeya: Bütün i<j cütlərini yoxla, ən kiçik Ai+Aj+j−i-ni saxla.
// Mürəkkəblik: O(N²)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int size;
        cin>>size;
        vector<int> nums;

        for(int i=0;i<size;i++){
            int num;
            cin>>num;
            nums.push_back(num);
        }

        int sum=nums[0] + nums[1] + 1 - 0;
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(nums[i] + nums[j] + j - i < sum){
                    sum = nums[i] + nums[j] + j - i ;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
