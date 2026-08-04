class Solution {
public:


    void dfsTraversal(int vertex, vector<vector<int>> &graph,  vector<bool> &vis){
        vis[vertex] = true;
        for(int child: graph[vertex]){
            if(vis[child]) continue;

            dfsTraversal(child,graph,vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);

        for(int i =0; i<edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int cnt = 0;
        for(int i =0; i<n; i++){
            if(vis[i]) continue;
            dfsTraversal(i,graph,vis);
            cnt++;
        }

        return cnt;
    }
};
