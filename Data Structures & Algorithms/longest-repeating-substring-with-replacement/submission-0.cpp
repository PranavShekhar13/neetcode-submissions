class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, maxFreq = 0, maxLength = 0;

        int freqMap[26] = {0};

        for(int end = 0; end<s.size(); end++){
            freqMap[s[end] - 'A']++;
            maxFreq = max(maxFreq, freqMap[s[end] - 'A']);

            if( (end-start+1) - maxFreq > k){
                freqMap[s[start] - 'A']--;
                start++;
            }
            maxLength = max(maxLength, (end-start+1));
        }

        return maxLength;
    }
};
