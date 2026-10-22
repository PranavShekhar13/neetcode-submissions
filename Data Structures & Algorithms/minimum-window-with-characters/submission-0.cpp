class Solution {
private:
    bool containsFreq(int mapS[], int mapT[]){
        for(int i=0; i<52; i++){
            if(mapT[i] > mapS[i]){
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int mapS[52] = {0};
        int mapT[52] = {0};

        for(char &ch:t){
            if(ch >= 'A' && ch <= 'Z'){
                mapT[ch-'A']++;
            } 
            else if (ch >= 'a' && ch <= 'z'){
                mapT[ch-'a'+26]++;
            }
        }

        int left = 0, minLen = INT_MAX, startIndex = -1;

        for(int right = 0; right<s.length(); right++){

             if(s[right]>= 'A' && s[right] <= 'Z'){
                mapS[s[right]-'A']++;
             }
             else if(s[right] >= 'a' && s[right] <= 'z'){
                mapS[s[right]-'a'+26]++;
             }
            

            while(containsFreq(mapS, mapT)){
                
                if((right-left+1) < minLen){
                    minLen = right-left+1;
                    startIndex = left;
                }
                
                if(s[left]>= 'A' && s[left] <= 'Z'){
                mapS[s[left]-'A']--;
                }
                else if(s[left] >= 'a' && s[left] <= 'z'){
                mapS[s[left]-'a'+26]--;
                }

                left++;
            }
        }

         return (startIndex == -1) ? "" : s.substr(startIndex, minLen); 

    }
};
