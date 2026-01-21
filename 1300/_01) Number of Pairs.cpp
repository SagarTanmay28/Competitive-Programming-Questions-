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
