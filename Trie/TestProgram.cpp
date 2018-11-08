
#include "Trie.h"

#include <iostream>

using namespace std;

void printMenu() {
    cout << "--------------------" << endl;
    cout << "1. Insert into the Trie " << endl;
    cout << "2. Find element in the Trie " << endl;
    cout << "3. Print the current Trie " << endl;
    cout << "Enter your choice [1-3] : ";
}

int main() {
    shared_ptr<Trie> trie = make_shared<Trie>();
    int choice;
    while( true ) {
        printMenu();
        string word;
        cin >> choice;
        if( choice == 1 ) {
            cout << "Enter a word : ";
            cin >> word;
            trie->Insert(word);
        }
        else if( choice == 2 ) {
            cout << "Enter query word : ";
            cin >> word;
            string isFound = trie->Find(word) ? " Found " : " Not Found ";
            cout << "The word " << word << isFound << " in Trie " << endl;
        }
        else if( choice == 3 ) {
            cout << "The Trie is " << endl;
            trie->printTrie();
        }
        else {
            break;
        }
    }
    return 0;

}