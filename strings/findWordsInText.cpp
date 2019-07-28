/* Retrieve all the starting and ending indices of all the words, from a vector, in
 * the given text.
 * The words can repeat in the text.
 * https://leetcode.com/problems/index-pairs-of-a-string/
 */
class TrieNode {
    
public:
    
    bool isWord;
    map<char, TrieNode*> m;
};

class Trie {
    
    TrieNode* root;
    
public:
    
    Trie () {
        
        root = new TrieNode();
    }
    
    void insertTri(string& s) {
        
        TrieNode* node = root;
        
        for (auto c: s) {
            
            if (node->m.count(c) <= 0)
                node->m.insert({c, new TrieNode()}); 
            
            node = node->m[c];
        }
        
        node->isWord = true;
    }
    
    bool searchTri(string& s, int ind, vector<int>& idx) {
        
        TrieNode* node = root;
        
        while (node->m.count(s[ind]) > 0) {
            
            node = node->m[s[ind]];
            if (node->isWord == true)
                idx.push_back(ind);
            
            ind++;
        }
        
        return !idx.empty()?true:false;
    }
    
};

class Solution {
    
public:
    
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        
        vector<vector<int>> ans;
        Trie* tri = new Trie();
        
        for (auto word: words)
            tri->insertTri(word);
        
        for (int i = 0; i < text.size(); ++i) {
            
            vector<int> idx;
            
            if (tri->searchTri(text, i, idx)) {
                
                for (auto ind: idx)
                    ans.push_back({i, ind});
            }
        }
            
        return ans;
    }
};
