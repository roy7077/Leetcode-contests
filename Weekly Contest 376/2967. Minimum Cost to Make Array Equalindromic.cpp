#define ll long long
class Solution {
    public:
    
    bool check(int num)
    {
        string temp=to_string(num);
        int i=0;
        int j=temp.length()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])
            return 0;
            
            i++;
            j--;
        }
        return 1;
    }
    
    ll mincost(vector<int>& nums,int n)
    {
        ll cost=0;
        for(auto it:nums)
        cost+=abs(it-n);
        
        return cost;
    }
    
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int ind=nums.size()/2;
        int num=nums[ind];
            
        while(1)
        {
            if(check(num))
            {
                break;
            }

            num++;
        }
            
        ll cost1=mincost(nums,num);
        num=nums[ind];

        while(1)
        {
            if(check(num))
            {
                break;
            }

            num--;
        }
            
        ll cost2=mincost(nums,num);

        return min(cost1,cost2);
    }
};