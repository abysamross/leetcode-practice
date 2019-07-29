/*
 * Remove all Adjascent duplicates from a string
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 */
class Solution {
    
public:
    
    string removeDuplicates(string S) {
		/*
		 * Setup 4 indices:
		 * st		= 	star of prefix w/o adjascent duplicates
		 * b		= 	end of prefix w/o adjascent duplicates
		 * f		= 	start of suffix yet to be scanned
		 * en - 1 	= 	end of suffix yet to be scanned
		 *
		 * NOTE: S[b+1...f] is char that have been eliminated from string
		 */
		int st = -1;
        int en = S.size();
        int b = st;
        int f = 0;
        
        while (f < en - 2) {
			// Append to prexif current char if it is not repeating.
            if (S[f] != S[f + 1])
                S[++b] = S[f++];

            else {
				// if current char is repeating, skip the repeating char...
                f += 2;
				/*
				 * and remove possible matches from the end of the already 
				 * scanned prefix and the beginning of the yet to be scanned
				 * suffix
				 */
                while ((b > st) && (S[b] == S[f])) {
                        --b; ++f;
                }
				/*
				 * and in the process if we consumed the entire prefix
				 * reset the st and b to f - 1, indicating that we need to 
				 * consider only S[f...en-1] now on and start afresh. 
				 */
                if (b <= st)
                    st = b = f - 1;
            }
        }
		// construct the solution string in place. 
        int i = 0;
		/*
		 * if there is no prefix part, check only the last 2 chars.
		 * else, move the prefix part S[st+1...b] to the begnning of S...
		 */
        while (st < b) 
            S[i++] = S[++st];
		/*
		 * check the last 2 chars as well, if they are different, move them to
		 * the end of the solution
		 */
        if (S[f] != S[f + 1])
            while (f < en)
                S[i++] = S[f++];

		/*
		 * erase rest of string S and 
		 * return S
		 */
        S.erase(i,  en - i);
        return S;
    }
};
