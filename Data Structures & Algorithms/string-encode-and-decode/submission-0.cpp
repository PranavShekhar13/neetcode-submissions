class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string encoded="";
        for(string &str:strs){
            encoded+= to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int i = 0;
        while(i<n){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j+1,len));

            i= j+1+len;
        }
        return res;
    }
};
