class Solution {
    public:
    string shortestBeautifulSubstring(string s, int k) {
        
        vector<pair<int,int>> p;
        int i=0;
        int j=0;
        int one=0;
        
        int min=1e9;
        while(i<s.length() and j<s.length())
        {
            if((s[j]-'0')==1)
            one++;
            
            while(one>k or (one==k and s[i]-'0'==0))
            {
                if((s[i]-'0')==1)
                one--;
                
                i++;
            }
            
            if(one==k)
            {
                //cout<<"first "<<i<<" - "<<j<<endl;
                //cout<<"len - "<<j-i+1<<" min - "<<min<<endl;
                if((j-i+1)<=min)
                {
                    //cout<<i<<" "<<j<<endl;
                    min=j-i+1;
                    p.push_back({i,j});
                }
            }
            
            j++;
        }
        
        // for(auto it:p)
        // cout<<it.first<<" "<<it.second<<endl;
        // return "sagar";
        
        // cout<<min<<endl;
        // cout<<p.size()<<endl;
        vector<string> ans;
        for(auto it:p)
        {
            if((it.second-it.first+1)!=min)
            continue;
            
            string st="";
            for(int i=it.first;i<=it.second;i++)
            st+=s[i];
            
            ans.push_back(st);
        }
        
        sort(ans.begin(),ans.end());
        // for(auto it:ans)
        // cout<<it<<endl;
        
        return ans.size()==0 ? "":ans[0];
        return ans[0];
    }
};