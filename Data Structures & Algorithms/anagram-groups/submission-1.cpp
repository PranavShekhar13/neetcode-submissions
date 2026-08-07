class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        
        for(string &str:strs){
            string x = str;
            sort(x.begin(), x.end());
            mp[x].push_back(str);
        }

        for(auto &pr:mp){
            result.push_back(pr.second);
        }
        return result;
    } 
};
