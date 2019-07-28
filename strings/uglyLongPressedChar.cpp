/*
 * Remove the long pressed chars typed in the 'typed' string.
 * Long pressed chars are those that are there in the input string but repeated
 * multpile times consecutively as if the key got stuck.
 * Long pressed chars are to be identified by looking at the input string.
 * https://leetcode.com/problems/long-pressed-name/
 * NOTE: This is an ugly solution!!
 */

class Solution {
    
public:

    bool isLongPressedName(string name, string typed) {
        
        int nLastCnt = 0;
        int tC = 0;
        int nC = 0;
        char lCh = typed[0];
        
        if (!typed.size())
            return false;
        
        while (nC < name.size()) {
            
            if (typed[tC] == name[nC]) {
				// update the last buffered char: lCh
				// and its count
                if (lCh != typed[tC]) {
                    
                    lCh = typed[tC];
                    nLastCnt = 0;
                }
                
                tC++;
				// increment the buffered char count
                nLastCnt++;

            }
			// if the actual named char matches the buffered char,
			// consume from the buffer char until there is sufficient # of
			// buffered chars
            else if ((lCh == name[nC]) && nLastCnt) {
                
				// consuming the buffered char
                nLastCnt--;
                nC++;

            }
            else
                return false;
        }
        
        return true;
    }
};
