export ARCH = CYGNUS
CXX = g++
DEBUG = -Wall -g
CFLAGS = $(DEBUG)
Test: Trie.o TrieNode.o
	$(CXX) $(CFLAGS) -o Test TestProgram.cpp Trie.o TrieNode.o
Trie.o: Trie.cpp TrieNode.h Trie.h 
	$(CXX) $(CFLAGS) -c Trie.cpp
TrieNode.o: TrieNode.h TrieNode.cpp
	$(CXX) $(CFLAGS) -c TrieNode.cpp
clean:
	rm *.o Test