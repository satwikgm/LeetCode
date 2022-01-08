//                     350   Intersection of Two Arrays II

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

// SOLUTION USING HASHING : 
// 1. We will insert elements of the first array into an unordered set.
// 2. Now we traverse the second array and if we find that the element of the second array exists in the set we will push the element into the vector and erase the particular      element from the set .
// 3. The return type of the function will be vector<int> and we will return the vector containing elements common to both arrays .

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> v;
        unordered_set<int> s;
        for(int i=0;i<nums1.size();i++)
        {
            s.insert(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++)
        {
            if(s.find(nums2[j])!=s.end())
            {
               v.push_back(nums2[j]);
                s.erase(nums2[j]);
            }
        }
        return v;
    }
};