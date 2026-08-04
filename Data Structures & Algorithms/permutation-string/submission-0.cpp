class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> freqS1(26,0);
        vector<int> freqS2(26,0);
        int left = 0;
        int n = s2.length();

        for(char &ch:s1){
            freqS1[ch-'a']++;
        }

        for(int right =0; right<n; right++){

            freqS2[s2[right] - 'a']++;

            if( (right-left+1) > s1.length()){
                freqS2[s2[left]-'a']--;
                left++;
            }
            if(freqS1 == freqS2) return true;
        }

        return false;
    }
};
