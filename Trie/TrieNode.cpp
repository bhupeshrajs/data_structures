#include "TrieNode.h"

TrieNode::TrieNode(char _value) {
    m_value = _value;
}

auto TrieNode::getChildren() -> std::map<char , std::shared_ptr<TrieNode>> {
    return m_children;
}

bool TrieNode::isEmpty() {
    return m_children.size() == 0;
}

char TrieNode::getValue() {
    return m_value;
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
       m_children[_element] = std::make_shared<TrieNode>(_element);
    }
}