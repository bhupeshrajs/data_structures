#include "Trie.h"
#include <iostream>
#include <queue>

Trie::Trie() {
    m_head = std::make_shared<TrieNode>();
}

std::shared_ptr<TrieNode> Trie::getHead() {
    return m_head;
}

void Trie::Insert(const std::string & _word ) {
    std::shared_ptr<TrieNode> currentNode = m_head;
    for( auto letter : _word ) {
        if( currentNode->getChild(letter) == nullptr ) {
            currentNode->addChild(letter);
        }
        currentNode = currentNode->getChild(letter);
    }
}

bool Trie::Find(const std::string & _word) {
    std::shared_ptr<TrieNode> currentNode = m_head;
    for( auto letter : _word ) {
        auto childNode = currentNode->getChild(letter);
        if( childNode == nullptr ) {
            return false;
        }
        currentNode = childNode;
    }
    return true;
}

/*TODO: Improve printing of the Trie */
void Trie::printTrie() {
    std::shared_ptr<TrieNode> currentNode = m_head;
    std::queue<std::shared_ptr<TrieNode>> visitedNodes;
    auto levelMarker = std::make_shared<TrieNode>('*');
    visitedNodes.push(currentNode);
    visitedNodes.push(levelMarker);
    while( !visitedNodes.empty() ) {
        // get the front of the queue
        currentNode = visitedNodes.front();
        visitedNodes.pop();
        // If the front of the queue belongs to the level marker, then
        // queue it again, to determine the next level.    
        if( currentNode->getValue() == '*' && !visitedNodes.empty() ) {
            std::cout << std::endl;
            visitedNodes.push(levelMarker);
            continue;
        }
        // Print the current children of the node 
        auto children = currentNode->getChildren();
        std::cout << "[ ";
        for( auto child : children ) {
            std::cout << child.first << " ";
            visitedNodes.push(child.second);
        }
        std::cout << "]\t";
    }
}