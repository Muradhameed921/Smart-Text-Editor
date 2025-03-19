#pragma once
#include<iostream>
#include<Windows.h>

struct NodeHuffMan {
	int frequency;
	char character;
	NodeHuffMan* left = nullptr;
	NodeHuffMan* right = nullptr;
};

struct NodeList {
	char character;
	std::string binaryCode;
};

class HuffMan {
private:
	NodeHuffMan** list;
	NodeHuffMan* rootTree;
	NodeList* charsList;
	int size;
	std::string compressedText;
	std::string deCompressedText;
public:
	HuffMan();

	void compressString(std::string input);
	void deCompress();

	std::string noRepeatChars(std::string input);
	void createPointerArray(std::string input, std::string uniqueCharacts);
	void sortPointerArray(int start);
	void binaryCodes(NodeHuffMan* root, NodeList*& characterNodes, int index, int arr[]);

	std::string readFromFile();
	void saveToFile(std::string uniqueCharacts);
};