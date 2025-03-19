#include<iostream>
#include<Windows.h>
#include"TrieTree.h"

int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 13);
	TrieTree objTrie;
	objTrie.readFromFile();
	objTrie.mainMenu();
}