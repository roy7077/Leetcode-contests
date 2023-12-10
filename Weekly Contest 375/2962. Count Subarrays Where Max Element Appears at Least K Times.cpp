#define ll long long
class Solution {
    public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans=0;
        int maxi=-1;
        for(auto it:nums)
        maxi=max(maxi,it);
        
        int i=0;
        int j=0;
        int cnt=0;
        int last=0;
        int n=nums.size();
        
        while(j<n)
        {
            if(nums[j]==maxi)
            cnt++;
            
            while(cnt>=k)
            {
                ans+=n-j;
                if(nums[i]==maxi)
                cnt--;
                
                i++;
            }
            j++;
        }
        return ans;
    }
};
