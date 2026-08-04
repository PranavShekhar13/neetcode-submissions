class Solution {
public:
    string foreignDictionary(vector<string>& words) {
         int N = words.size();
        vector<int> adj[26];
        vector<int> indegree(26, 0);
        vector<bool> exists(26, false);
        int uniqueChars = 0;

        // Mark which characters are present in the dictionary
        for (const string& w : words) {
            for (char c : w) {
                if (!exists[c - 'a']) {
                    exists[c - 'a'] = true;
                    uniqueChars++;
                }
            }
        }

        // 1. Build the Graph
        for (int i = 0; i < N - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            
            // Edge Case: Check if s2 is a prefix of s1 (e.g., "apple", "app")
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) return "";

            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    int u = s1[ptr] - 'a';
                    int v = s2[ptr] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
        }

        // 2. Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            // Only push characters that actually exist and have 0 indegree
            if (exists[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string topo = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo += char(node + 'a');
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // Return empty string if a cycle is detected (topo length != unique characters)
        return (topo.size() == uniqueChars) ? topo : "";
    }
};
