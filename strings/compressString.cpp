/*
 * Compress a string in place by replacing repeating chars in the string with 
 * that char and the # times it repeat (if # > 1) and return the length of the
 * compressed string.
 * https://leetcode.com/problems/string-compression/
 */
class Solution {

public:
    
    void replaceCnt(vector<char>& chars, int rcnt, int& cInd) {
        string scnt = "";
        
        while (rcnt) {

            scnt.push_back('0' + rcnt%10);
            rcnt /= 10;
        }

        for (int i = scnt.size() - 1; i >= 0; --i)
            chars[++cInd] = scnt[i];
    }
    
    int compress(vector<char>& chars) {
        
        int advInd;
        int fInd = 0;
        int cInd = 0;
        
        for (advInd = 1; advInd < chars.size(); advInd++) {
            
            if (chars[advInd] != chars[advInd - 1]) {
                
                if (advInd - fInd > 1)
                    replaceCnt(chars, advInd - fInd, cInd);
                
                chars[++cInd] = chars[advInd];
                fInd = advInd;
            }
        }
       
        if (advInd - fInd > 1)
            replaceCnt(chars, advInd - fInd, cInd);
        
        return cInd+1;
    }
};
