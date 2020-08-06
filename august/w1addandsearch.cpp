#include <vector>
#include <iostream>

using namespace std;

struct TrieNode {
    bool isWord;
    char ch;
    vector<TrieNode *> children;
    TrieNode(char chr) : ch(chr) { 
        isWord = false;
        children = vector<TrieNode *>(26, nullptr); 
    }
    ~TrieNode() {
        for (auto *ch : children)
            if (ch)
                delete ch;
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode(0);
    }
    
    void addWord(string word) {
        auto t = root;
        for (char c : word) {
            if (!t->children[c - 'a'])
                t->children[c - 'a'] = new TrieNode(c);
            t = t->children[c - 'a'];
        }
        t->isWord = true;
    }
    
    bool search(string word, TrieNode *r = nullptr) {
        TrieNode *t = r ? r : root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto child : t->children)
                    if (child && search(word.substr(i + 1), child))
                        return true;
                return false;
            }
            if (!t->children[c - 'a'])
                return false;
            t = t->children[c - 'a'];
        }
        return t->isWord;
    }
};


int main() {
    WordDictionary w;
    w.addWord("a");
    w.addWord("a");
    // w.search(".");
    // w.search("a");
    //  w.search("aa");
    // w.search("a");
    // w.search(".a");
    w.search("a.");
    return 0;
}
