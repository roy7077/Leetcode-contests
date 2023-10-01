// Time complexity - O(3*N)
// Space complexity- O(N)

#define ll long long
class Solution {
    public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        ll maxsum=0;
        for(auto it:nums)
        maxsum+=it;
        
        ll d=target/maxsum;
        ll rem=target%maxsum;
        if(!rem)
        return d*nums.size();
        
        target=rem;
        ll cnt=0;
        int i=0;
        int j=0;
        ll sum=0;
        ll cnt2=0;
        ll ans=1e9;
    
        while(cnt<2*nums.size())
        {
            cnt++;
            j%=nums.size();
            sum+=nums[j];
            cnt2++;
            
            while(sum>target)
            {
                cnt2--;
                i%=nums.size();
                sum-=nums[i];
                i++;
            }
            if(sum==target and cnt2<ans and cnt2>=1)
            {
                ans=cnt2;
            }
            j++;
        }
        
        if(ans>=1e9)
        return -1;
        else
        {
            ll result=(d*nums.size())+ans;
            return result;
        }
    }
};