#pragma once
#include<iostream>
#include"HuffMan.h"
#include<Windows.h>

#define ESCAPE 27

struct NodeTrieTree {
	char character;
	bool endWord;
	NodeTrieTree* children[26];
};

class TrieTree {
private:
	NodeTrieTree* root;
	NodeTrieTree* tempNode;
	int suggestedWords;
	HuffMan objHuffMan;
	std::string inputData;
public:
	TrieTree();
	~TrieTree();

	void mainMenu();

	NodeTrieTree* insertInTrieTree(NodeTrieTree* rootNode, char ch, bool endOfWord);

	void readFromFile();
	void typingText();

	void findSuggestions(NodeTrieTree* rootNode, std::string input, std::string* suggestions);
	void find(NodeTrieTree* rootNode, std::string* suggestions, std::string input);

	void displaySuggestions(std::string* suggestions, int currSuggestion);
};
