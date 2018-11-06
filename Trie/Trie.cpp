#include "Trie.h"

std::shared_ptr<TrieNode> Trie::getHead() {
    return m_head;
}

void Trie::Insert(const std::string & _word ) {
    std::shared_ptr<TrieNode> currentNode = m_head;
    for( auto letter : _word ) {
        if( currentNode->isEmpty() ) {
            currentNode->addChild(letter);
        }
        currentNode = currentNode->getChild(letter);
    }
}

bool Trie::Find(const std::string & _word) {
    std::shared_ptr<TrieNode> currentNode = m_head;
    for( auto letter : _word ) {
        if( currentNode->getChild(letter) == nullptr ) {
            return false;
        }
    }
    return true;
}