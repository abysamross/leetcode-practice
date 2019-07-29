/*
 * Remove all Adjascent duplicates from a string
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 */
class Solution {
    
public:
    
    string removeDuplicates(string S) {
		/*
		 * Setup 4 indices:
		 * st		= 	start of subseq w/o adjascent duplicates
		 * b		= 	end of subseq w/o adjascent duplicates
		 * f		= 	start of suffix yet to be scanned
		 * en - 1 	= 	end of suffix yet to be scanned
		 *
		 * NOTE: S[0...b] is the subseq that w/o adj dups
		 * 		 s[b+1...f-1] is the dups that have been removed
		 * 		 s[f...en-1] is the suffix yet to be scanned
		 */
		int st = -1;
        int en = S.size();
        int b = st;
        int f = 0;
        
        while (f < en - 2) {
			// Append to subseq current char if it is not repeating.
            if (S[f] != S[f + 1])
                S[++b] = S[f++];

            else {
				// if current char is repeating, skip the repeating char...
                f += 2;
				/*
				 * and remove possible matches from the end of the 
				 * subseq and the beginning of the yet to be scanned
				 * suffix
				 */
                while ((b > st) && (S[b] == S[f])) {
                        --b; ++f;
                }
				/*
				 * and in the process if we consumed the entire subseq 
				 * we need to consider only S[f...en-1] now on and start afresh. 
				 */
            }
        }
		/* construct the solution string in place. 
		 * check the last 2 chars as well, if they are different, move them to
		 * the end of the solution
		 */
        if (S[f] != S[f + 1])
            while (f < en)
                S[++b] = S[f++];

		/*
		 * erase rest of string S and 
		 * return S
		 */
        S.erase(b + 1,  en - b);
        return S;
    }
};
