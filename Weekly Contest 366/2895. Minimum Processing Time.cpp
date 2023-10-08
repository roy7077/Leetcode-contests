class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        
        sort(p.begin(),p.end());
        sort(t.begin(),t.end(),greater<int>());
        
        int ans=0;
        int cnt=0;
        int part=t.size()/p.size();
        
        int i=0;
        int j=0;
        while(j<t.size())
        {
            int temp=p[i]+t[j];
            ans=max(ans,temp);
            cnt++;
            
            if(cnt==part)
            {
                i++;
                cnt=0;
            }
            j++;
        }
        
        return ans;
    }
};