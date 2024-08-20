// User function Template for C++

class Solution {
  public:
    
    bool check(vector<int> adj[] , int src , unordered_map<int , bool>&visited,unordered_map<int,bool>&dfs,int safenodes[]){
        visited[src] = true;
        dfs[src] = true;
        safenodes[src] = 0;
        
        for(auto nbr: adj[src]) {
            if(!visited[nbr]) {
                bool ans = check(adj , nbr,visited,dfs,safenodes);
                if(ans == true) {
                    return true;
                }
            }
            if(visited[nbr]==1 && dfs[nbr]==1) {
                //cycle present
                return true;
            }
        }
        
        
        //backtrack - [yahi galti karta hu]
         dfs[src] = false;
         safenodes[src] =1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int , bool>visited , dfs;
        int safenodes[V] = {0};
        
        for(int i =0 ;i<V ;++i){
            if(!visited[i]) check(adj ,i , visited,dfs,safenodes);
        }
        for(int i =0; i<V;++i)
            if(safenodes[i]) ans.push_back(i);
        return ans;
        
        
        // code here
    }
};