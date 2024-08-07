//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detect(int node, vector<int> adj[], int vis[]){
        queue<pair<int,int>> q;
        vis[node]=1;
        q.push({node,-1});
        while(!q.empty()){
            int n=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[n]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,n});
                }
                else if(it!=parent)
                    return true;
            }
        }
        return false;
    }
  public:
    //[USING BFS]
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends