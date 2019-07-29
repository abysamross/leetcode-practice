/*
 * Get the number of lines and chars in last line
 * occupied by the string following certain conditions
 * https://leetcode.com/problems/number-of-lines-to-write-string/
 */
class Solution {
    
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        
        int cc = 0;
        int lc = 0;
        int n = 0;
        for (auto c: S) {
            
            n = widths[c - 'a'];
            if (cc + n > 100) {
                cc = n;
                lc++;
            }
            else
                cc += n;
        }
        
        if (cc)
            lc++;
            
        return {lc, cc};
    }
};
