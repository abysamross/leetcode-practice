/*
 * Find GCD of 2 strings
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/
 */
class Solution {
    
public:
    
    int stringGCD(string& A, int i, string& B, int j) {
        
        int ai = i;
        int bj = j;
        
        // compare substrings A[i...sizeof(B)] && B[j...sizeof(B)]
        while (bj < B.size()) {
			/*
			 * return -1 indicating, GCD == ""
			 * i.e. if A[i...sizeof(B)] contains a char not
			 * in B[j...sizeof(B)]
			 */
            if (A[ai] != B[bj])
                return -1;
            
            ++ai; ++bj;
        }
        
		/* if A[i...sizeof(B)] == B[j...sizeof(B)]
		 * and both A & B are at their ends then
		 * B[j...sizeof(B)] is the GCD
		 */
        if (ai == A.size() && bj == B.size())
            return j;
		/*
		 * else
		 * recurse with A = longer of ( A[ai...sizeof(A)], B[j...sizeof(B)])
		 * and B = shorter of ( A[ai...sizeof(A)], B[j...sizeof(B)])
		 *
		 * A[ai...sizeof(A)] == rest of the previous longer string
		 */
		 if (A.size() - ai > B.size() - j)
			 return stringGCD(A, ai, B, j);
		 else
			 return stringGCD(B, j, A, ai);
		 
    } 
    
    string gcdOfStrings(string str1, string str2) {
        
        // if either is "" return the other
        if (!str1.size() || !str2.size())
            return !str1.size() ? str2 : str1;
		/*
		 * get the shorter of two, keep its reference in B and
		 * longer's reference in A
		 */
        string& A = (str1.size() >= str2.size()) ? str1 : str2;
        string& B = (A == str1) ? str2 : str1;
        int ret  = -1;
		/* 
		 * call recursive GCD function modified for strings.
		 * it returns the index to the beggining of the substring that is the GCD
		 */
        if ((ret = stringGCD(A, 0, B, 0)) == -1)
            return "";
		/*
		 * we were expecting the GCD to be in the shorter of 2 strings, B, if the
		 * returned index is greater than sizeof(B) it implies we had swapped the
		 * strings and the GCD is in A.
		 */
        return ret >= B.size() ? A.substr(ret): B.substr(ret);
    }
};
