#include"TrieTree.h"
#include<conio.h>
#include<fstream>
#include<iostream>
#include<Windows.h>

TrieTree::TrieTree() {
	root = new NodeTrieTree();
	root->endWord = false;
	for (int i = 0; i < 26; i++)
		root->children[i] = nullptr;
	tempNode = nullptr;
	suggestedWords = 0;
}

TrieTree::~TrieTree() {
	delete root;
	root = tempNode = nullptr;
}

NodeTrieTree* TrieTree::insertInTrieTree(NodeTrieTree* rootNode, char ch, bool endOfWord) {
	int index = ch - 97;
	if (index < 0 || index > 25)
		return rootNode;
	if (!rootNode->children[index]) {
		NodeTrieTree* newNode;
		newNode = new NodeTrieTree();
		newNode->character = ch;
		newNode->endWord = endOfWord;

		rootNode->children[index] = newNode;
		for (int i = 0; i < 26; i++)
			rootNode->children[index]->children[i] = nullptr;
		return rootNode->children[index];
	}

	if (endOfWord == true)
		rootNode->children[index]->endWord = endOfWord;
	return rootNode->children[index];
}

void TrieTree::readFromFile() {
	std::ifstream in;
	std::string str;
	in.open("outfile.txt");
	while (!in.eof()) {
		tempNode = root;
		in >> str;
		for (int i = 0; i < str.length(); i++) {
			if (i == str.length() - 1)
				tempNode = insertInTrieTree(tempNode, str[i], true);
			else
				tempNode = insertInTrieTree(tempNode, str[i], false);
		}
		tempNode = nullptr;
	}
	in.close();
}

void TrieTree::find(NodeTrieTree* rootNode, std::string* suggestions, std::string input) {
	if (suggestedWords == 9)
		return;
	for (int i = 0; (i < 26) && suggestedWords < 9; i++) {
		if (rootNode->children[i]) {
			rootNode = rootNode->children[i];
			suggestions[suggestedWords] += rootNode->character;
			if (rootNode->endWord == true) {
				suggestedWords++;
				bool check = false;
				for (int j = 0; j < 26; j++) {
					if (rootNode->children[j]) {
						check = true;
						break;
					}
				}
				if (!check)
					suggestions[suggestedWords] = input;
				else
					suggestions[suggestedWords] = suggestions[suggestedWords - 1];
			}
			find(rootNode, suggestions, input);
		}
	}
}


void TrieTree::findSuggestions(NodeTrieTree* rootNode, std::string input, std::string* suggestions) {
	if (input.length() == 0) 
		return;
	suggestedWords = 0;
	tempNode = root;
	for (int i = 0; i < input.length(); i++) {
		int index = input[i] - 97;
		if (tempNode->children[index]) 
			tempNode = tempNode->children[index];
	}
	suggestions[suggestedWords] = input;
	find(tempNode, suggestions, input);
}

void TrieTree::typingText() {
	std::string* suggestions = new std::string[10];
	int currSuggestion = -1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	std::cout << "Enter: " << inputData;
	if (inputData.length() != 0) {
		findSuggestions(root, inputData, suggestions);
		displaySuggestions(suggestions, currSuggestion);
	}
	while (true) {
		char getChar = 0;
		getChar = _getch();
		system("cls");
		if (getChar >= 'a' && getChar <= 'z') {
			inputData += getChar;
			findSuggestions(root, inputData, suggestions);
			std::cout << "Enter: " << inputData;
			displaySuggestions(suggestions, currSuggestion);
		}
		else if (getChar == '/') {
			currSuggestion++;
			if (currSuggestion > suggestedWords - 1)
				currSuggestion--;
			std::cout << "Enter: " << inputData;
			displaySuggestions(suggestions, currSuggestion);
		}
		else if (getChar == ';') {
			inputData = suggestions[currSuggestion];
			findSuggestions(root, inputData, suggestions);
			currSuggestion = -1;
			std::cout << "Enter: " << inputData;
			displaySuggestions(suggestions, currSuggestion);
		}
		else if (getChar == '=') {
			objHuffMan.compressString(inputData);
			std::cout << "Enter: " << inputData;
			displaySuggestions(suggestions, currSuggestion);
		}
		else if (getChar == '\b') {
			if (inputData.length() != 0) {
				std::string tempStr;
				for (int i = 0; i < inputData.length() - 1; i++)
					tempStr += inputData[i];
				inputData = tempStr;
			}
			findSuggestions(root, inputData, suggestions);
			std::cout << "Enter: " << inputData;
			displaySuggestions(suggestions, currSuggestion);
		}
		else if (getChar == ESCAPE) {
			mainMenu();
		}
		else {
			std::cout << "Enter: " << inputData;
			displaySuggestions(suggestions, currSuggestion);
		}
	}
}

void TrieTree::mainMenu() {
	char input;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((time(0)));
	while (true) {
		std::cout << "\t\t\t\t\t\t\t\t\t\tCreated By:";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t1. 21F-9088\n\t\t\t\t\t\t\t\t\t\t2. 21F-9087\n\t\t\t\t\t\t\t\t\t\t3. 21F-9308.";
		std::cout << "\n\n\n\t\t\t\t\t ---------------\n";
		std::cout << "\t\t\t\t\t>| TEXT EDITOR |<\n";
		std::cout << "\t\t\t\t\t ---------------\n\n";
		std::cout << "\t\t\t ---------------------------------------------\n";
		std::cout << "\t\t\t>| BETTER COMMUNICATION FOR BETTER FUTURE :) |<\n";
		std::cout << "\t\t\t ---------------------------------------------\n\n";
		std::cout << "\t -------------\n";
		std::cout << "\t>| MAIN MENU |<\n";
		std::cout << "\t -------------\n\n";
		std::cout << "\t1. Start Typing.\n\t2. Reload Previously Saved Text.\n\tPress any key to exit.\n\tInput: ";
		std::cin >> input;
		switch (input) {
		case '1':
			system("cls");
			typingText();
			break;
		case '2':
			inputData = objHuffMan.readFromFile();
			if (inputData != "") {
				system("cls");
				typingText();
			}
			break;
		default:
			std::cout << "\tSystem will shut down in 5 seconds\n";
			Sleep(5*1000);
			exit(0);
		}
		system("pause");
		system("cls");
	}
}

void TrieTree::displaySuggestions(std::string* suggestions, int currSuggestion) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 6);
	std::cout << "\nSuggestions:\n";
	SetConsoleTextAttribute(h, 4);
	if (suggestedWords == 0)
		std::cout << "\tNo Suggestions Available.\n";
	for (int i = 0; i < suggestedWords; i++) {
		if (i == currSuggestion)
			std::cout << "    --->";
		else 
			std::cout << "\t";
		std::cout << i + 1 << ". " << suggestions[i] << "\n";
	}
	SetConsoleTextAttribute(h, 2);
}
