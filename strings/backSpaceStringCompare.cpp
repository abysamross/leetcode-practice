/*
 * Remove chars according to the no. of '#' (backspaces) in input string and
 * compare the 2 strings.
 * https://leetcode.com/problems/backspace-string-compare/ 
 */
class Solution {
    
public:
    
    void pushStack(stack<char>& st, string& s) {
        
        for (auto c : s) {
            
            if (c != '#')
                st.push(c);
            else if (!st.empty())
                st.pop();
        }
        
        s.clear();
        
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
    }

    bool backspaceCompare(string S, string T) {
        stack<char> s;
        
        pushStack(s, S);
        pushStack(s, T);
        
        return S == T;
    }
};
