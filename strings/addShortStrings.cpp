/*
 * Add 2 short enough strings made only of chars 0-9.
 */
class Solution {
    
public:  
    
    void swap(string& s, int i, int j) {
        
        s[i] = s[i] ^ s[j];
        s[j] = s[i] ^ s[j];
        s[i] = s[i] ^ s[j];
    }
    
    int getNum(string& s) {
        
        int num = 0;
        for (auto c: s)
            num = num*10 + c - '0';
        
        return num;
    }
    
    string addStrings(string num1, string num2) {
        
        int n1 = 0;
        int n2 = 0;
        int sum = 0;
        string ans;
        
        if (num1 == "" && num2 == "")
            return "";
        
        n1 = getNum(num1);
        n2 = getNum(num2);
        sum = n1 + n2;
        
        if (!sum)
            return "0";
        
        while (sum) {
            ans.push_back('0' + sum%10);
            sum /= 10;
        }
        
        for (int i = 0, j = ans.size() - 1; i < j; ++i, --j)
            swap(ans, i, j);
        
        return ans;
    }
};
