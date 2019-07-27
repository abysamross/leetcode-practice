/*
 * Add 2 long strings consisting only of chars 0-9.
 */
class Solution {
    
public:  
    
    void swap(string& s, int i, int j) {
        
        s[i] = s[i] ^ s[j];
        s[j] = s[i] ^ s[j];
        s[i] = s[i] ^ s[j];
    }
    
    void reverseString(string& s) {
        
        for (int i = 0, j = s.size()-1; i < j; ++i, --j)
            swap(s, i, j);
    }
    
    string addStrings(string num1, string num2) {
        
        int sum = 0;
        int carry = 0;
        
        reverseString(num1);
        reverseString(num2);
        
        string& ans = num1.size() > num2.size()?num1:num2;
        
        for (int i = 0; i < ans.size(); ++i) { 
            
            if (i < num1.size())
                sum += num1[i] - '0';
            
            if (i < num2.size())
                sum += num2[i] - '0';
            
            ans[i] = '0' + sum%10;
            sum /= 10; //carry
        }
        
        if (sum)
            ans.push_back('0' + sum);
        
        reverseString(ans);
        return ans;
    }
};
