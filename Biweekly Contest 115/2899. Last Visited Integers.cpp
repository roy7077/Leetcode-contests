
class Solution {
    public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        
        vector<int> ans;
        vector<int> store;
        int ind=-1;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i][0]=='p')
            {
                if(ind==-1)
                ans.push_back(-1);
                else
                {
                    ans.push_back(store[ind]);
                    ind--;
                }
                
            }
            else
            {
                int temp=stoi(words[i]);
                store.push_back(temp);
                ind=store.size()-1;
            }
        }
        
        return ans;
    }
};