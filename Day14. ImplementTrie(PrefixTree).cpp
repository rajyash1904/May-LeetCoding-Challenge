/*

Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:
1. You may assume that all inputs are consist of lowercase letters a-z.
2. All inputs are guaranteed to be non-empty strings.
*/


struct TrieNode{
    bool isword;
    vector<TrieNode*> next;
    TrieNode(): isword(false){ next=vector<TrieNode*>(26,NULL);}
    
};
class Trie {

          
public:
    
    /** Initialize your data structure here. */
    Trie() {
       root= new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
         TrieNode* t=root;
        
        for(int i=0;i<word.size();i++){
            char c=word[i];
            int idx=c-'a';
            
            if(t->next[idx]==NULL){
                t->next[idx]=new TrieNode();
            }
            t=t->next[idx];
        }
        t->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* t=find(word);
        if(t!=NULL && t->isword==true) return true;
        return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(find(prefix)==NULL) return false;
        
        return true;
    }

    
private : 
    TrieNode* root;
    TrieNode* find(string s){
        TrieNode* t=root;
        for(auto c:s){
            if(t->next[c-'a']==NULL) return NULL;
            t=t->next[c-'a'];
        }
        return t;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
