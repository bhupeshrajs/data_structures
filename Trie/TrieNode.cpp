#include "TrieNode.h"

auto TrieNode::getChildren() -> std::map<char , std::shared_ptr<TrieNode>> {
    return m_children;
}

bool TrieNode::isEmpty() {
    return m_children.size() == 0;
}

std::shared_ptr<TrieNode> TrieNode::getChild(char _element) {
    if( m_children.find(_element) != m_children.end() )
        return m_children[_element];
    else
        return nullptr;
}

void TrieNode::addChild(char _element) {
    if( m_children.find(_element) == m_children.end() )
    {
        std::shared_ptr<TrieNode> emptyNode = std::make_shared<TrieNode>();
        m_children[_element] = emptyNode;
    }
}