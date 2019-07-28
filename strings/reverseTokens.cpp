/*
 * Reverse space separated tokens in a string
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/
 */
class Solution {
    
public:
    
    string reverseWords(string s) {
        
        int sInd = 0;
        int advInd = 0;
        
        for (; advInd <= s.size(); ++advInd) {
            
            if (advInd == s.size() || s[advInd] == ' ') {
                
                int st = sInd;
                int en = advInd - 1;
                // reverse the token
                while (st < en) {

                    s[st] = s[st] ^ s[en];
                    s[en] = s[st] ^ s[en];
                    s[st] = s[st] ^ s[en];

                    st++;
                    en--;
                }
                
                sInd = advInd+1;
            }
        }
        
        return s;
    }
};
