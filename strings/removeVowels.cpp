/*
 * Remove vowels from a string and compress the string
 * https://leetcode.com/problems/remove-vowels-from-a-string/
 */
class Solution {

public:
    string removeVowels(string S) {
        int cInd = 0;
        int advInd = 0;
        
        for (; advInd < S.size(); ++advInd) {
            
            switch (S[advInd]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    break;
                default:
                    S[cInd] = S[advInd];
                    cInd++;
                    break;
            }
        }
        
        S.erase(cInd, advInd - cInd);
        return S;
        
    }
};
