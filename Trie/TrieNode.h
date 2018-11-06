#ifndef _TRIE_NODE_H
#define _TRIE_NODE_H

#include <memory>
#include <map>

class TrieNode 
{
public:
    TrieNode() = default;
    virtual ~TrieNode() = default;
    std::shared_ptr<TrieNode> getChild(char _element);
    std::map<char, std::shared_ptr<TrieNode>> getChildren();
    void addChild(char _element);
    bool isEmpty();
private:
    std::map<char, std::shared_ptr<TrieNode>> m_children;
};

#endif