// Time Complexity - O(N)
// Space Complexity- O(2*N)
#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();
        vector<ll> front(n,0);
        vector<ll> back(n,0);
        
        int max_front=-1e9;
        int max_back=-1e9;
        
        for(int i=0;i<n;i++)
        {
            front[i]=max_front;
            back[n-i-1]=max_back;
            
            if(nums[i]>max_front)
            max_front=nums[i];
            
            if(nums[n-i-1]>max_back)
            max_back=nums[n-i-1];
        }
        
        ll ans=-1;
        for(int i=0;i<n-1;i++)
        {
            //cout<<"i-> "<<front[i]<<" "<<nums[i]<<" "<<back[i]<<" ";
            ll temp=(front[i]-nums[i])*back[i];
            ans=max(ans,temp);
            //cout<<ans<<endl;
        }
        
        return ans<0 ? 0:ans;
    }
};