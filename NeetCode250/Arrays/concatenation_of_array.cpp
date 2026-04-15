/*
* Problem  : Concatenation of Array
 * Platform : NeetCode 250 / LeetCode #1929
 * Difficulty: Easy
 * Topic    : Arrays
 * Link     : https://leetcode.com/problems/concatenation-of-an-array/
 *
 * Time  : O(n)
 * Space : O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        // -------------------------------------------------------
        // Approach 1: Double loop push_back
        // Simply iterate nums twice and push each element
        // -------------------------------------------------------
        vector<int> ans;
        for (int i = 0; i < 2; i++)
            for (int num : nums)
                ans.push_back(num);
        return ans;

        // -------------------------------------------------------
        // Approach 2: Index mirror  →  ans[i] == ans[i + n]
        // Allocate 2n array, then set both positions at once
        // -------------------------------------------------------
        // int n = nums.size();
        // vector<int> ans(2 * n);
        // for (int i = 0; i < n; i++)
        //     ans[i] = ans[i + n] = nums[i];
        // return ans;
    }
};