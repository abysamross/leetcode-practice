/*
 * remove long pressed keys (keys that are present in the actual name but
 * repeated consecutively) from the typed string by comparing it with the actual
 * name string.
 * This is better version of the uglyLongPressedChar.cpp 
 * https://leetcode.com/problems/long-pressed-name/
 */

class Solution {
    
public:

    bool isLongPressedName(string name, string typed) {
        
        int nN = 0;
        int nT = 0; 
        int size1 = typed.size();
        int size2 = name.size();
        
        while (nT < size1) {
            
            if (name[nN] == typed[nT]) {
                
				// we are at the end of input and matched everthing successfully
                if ((nT == size1 - 1) && (nN == size2 - 1))
                    return true;
                
				// ADVANCE ACTUAL NAME INDEX if we don't need it for matching 
				// the next typed char OR even if we need for matching the next
				// typed char advance it anyway if we have the next actual name
				// char same as the current one (i.e we have the liberty to use
				// the next actual name char to match the next typed char)
                if ((typed[nT] != typed[nT + 1]) || name[nN] == name[nN + 1])
                    nN++;
                
                nT++;
            }
            else
                return false;
        }
        
        return false; 
    }
};
