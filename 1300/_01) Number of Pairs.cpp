**You are given an array a of n integers. Find the number of pairs (i, j) (1 ≤ i < j ≤ n) where the sum of ai + aj is greater than or equal to l and less than or equal to r (that is, l ≤ ai + aj ≤ r).**

**For example, if n = 3, a = [5, 1, 2], l = 4 and r = 7, then two pairs are suitable:**

**i = 1 and j = 2 (4 ≤ 5 + 1 ≤ 7);**
**i = 1 and j = 3 (4 ≤ 5 + 2 ≤ 7).**


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long solve(long long x,vector<long long>& nums){
        long long i = 0;
        long long j = nums.size() - 1;

        long long count = 0;

        while(i < j){
            long long sum = nums[i] + nums[j];

            if(sum <= x){
                count += (j - i);
                i++;
            }
            else{
                j--;
            }
        }

        return count;

}

int main(){
    long long t;
    cin >> t;

    while(t--){
        long long n,l,r;
        cin >> n >> l >> r;

        vector<long long> nums(n,0);
        for(long long i=0;i<n;i++) cin >> nums[i];

        sort(nums.begin(),nums.end());

        cout << solve(r,nums) - solve(l-1,nums) << endl; // Very Important 
    }
}
