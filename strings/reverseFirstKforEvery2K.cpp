/*
 * Reverse the first K chars for every 2K chars.
 * If k chars are not available in the current 2K window,
 * reverse whatever is available.
 * https://leetcode.com/problems/reverse-string-ii/
 */
class Solution {
    
public:
    
    void rev(string& s, int i, int j) {
        
        while (i < j) {
            
            s[i] = s[i] ^ s[j];
            s[j] = s[i] ^ s[j];
            s[i] = s[i] ^ s[j];
            i++;
            --j;
        }
    }
    
    string reverseStr(string s, int k) {
        
        int advInd = 0;

        while (advInd < s.size()) {
            
            if ((advInd + k)%(2*k)) {

                int st = advInd;
                int en = advInd + k;

                if (en > s.size())
                    en = s.size();

                rev(s, st, en-1);

                if (en > s.size())
                    break;
            }
            
            advInd += k;
        }
        
        return s;
    }
};
