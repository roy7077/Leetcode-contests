class Solution {
    public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi=0;
        unordered_map<int,int> mp;
        
        int i=0;
        int j=0;
        
        while(j<nums.size())
        {
            mp[nums[j]]++;
            if(mp[nums[j]]>k)
            {
                while(i<=j)
                {
                    if(nums[i]==nums[j])
                    {
                        mp[nums[i]]--;
                        i++;
                        break;
                    }
                    mp[nums[i]]--;
                    i++;
                }
            }
            
            maxi=max(j-i+1,maxi);
            j++;
        }
        
        return maxi;
    }
};
