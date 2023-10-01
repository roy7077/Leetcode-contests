class Solution {
   public:
    
    int ms;
    int ankit(vector<vector<int>>&v,int node,vector<int>&ans,vector<int>&visi){
        
        if(ans[node]!=-1)  return ans[node];
        
        if(visi[node]!=-1) return 0;
        visi[node]=ms;
        int co=1;
        
        for( auto i:v[node] ){
            co += ankit(v,i,ans,visi);
        }
        
        return ans[node]=co;
    }
    
    vector<int> countVisitedNodes(vector<int>& e) {
     
        int n = e.size();
        vector<int> ans(n,-1);
        vector<int> visi(n,-1);
        
        vector<vector<int>> v(n);
        
        vector<int> indegree(n, 0);
        queue<int> q;
        
        for(int i=0;i<n;i++){
            
            v[i].push_back(e[i]);
            indegree[e[i]]++;
        }


        for (int u = 0; u < n; ++u) {
            if (indegree[u]==0) 
                q.push(u);
        }

        int visitedCount = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visitedCount++;

            for (int i : v[u]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        
       
         for(int i=0;i<n;i++){
             
            if(indegree[i]==0) continue;
            int x = i;
            ms=x;
            
            if(visi[x]==-1){
                ankit(v,i,ans,visi);
                
            }else{
                ans[x] = ans[visi[x]];
            }
            
            
        }
        
        
        
        for(int i=0;i<n;i++){
            
            ms=i;
            if(ans[i]==-1)
               ankit(v,i,ans,visi);
        }
     
        return ans;
    }
};