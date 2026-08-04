class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

    if (edges.size() != n - 1) return false;

    vector<vector<int>> adj(n);

    for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
    vector<int> vis(n, 0);

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    int cnt = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adjNode:adj[node]){
            if (vis[adjNode] != 1){
                vis[adjNode] = 1;
                q.push(adjNode);
                cnt++;
            }
        }
    }
    return cnt == n;
  }
};
