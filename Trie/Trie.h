#ifndef _TRIE_
#define _TRIE_

#include "TrieNode.h"
class Trie 
{
public:
    Trie();
    virtual ~Trie() = default;
    void Insert(const std::string & _word);
    bool Find(const std::string & _query);
    void printTrie();
protected:
    std::shared_ptr<TrieNode> getHead();        
private:
    std::shared_ptr<TrieNode> m_head;
};

#endif