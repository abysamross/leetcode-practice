/*
 * Honor backspaces in the input strings and compare them
 * backSpaceStringCompare v.2
 * https://leetcode.com/problems/backspace-string-compare/
 */
class Solution {
    
public:
    
    int compressString(string& s) {
        
        int f = 0;
        int b = -1;
        
        for (; f < s.size(); ++f) {
            
            if (s[f] != '#')
                s[++b] = s[f];
            else if (b >= 0)
                --b;
        }
        
        return b;
    }
    
    bool backspaceCompare(string S, string T) {
        
        int ret1 = -1;
        int ret2 = -1;
        ret1 = compressString(S);
        ret2 = compressString(T);
        
        if (ret1 != ret2)
            return false;
        
        while ((ret1 >= 0) && (S[ret1] == T[ret1]))
            ret1--;
        
        return ret1 >= 0 ? false: true;
    }
};
