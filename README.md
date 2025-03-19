# Smart Text Editor - Data Structures Project

## Introduction
The **Smart Text Editor** is a console-based text editing tool developed in C++. It provides users with word completion suggestions, text compression, and the ability to save/load text files. The project demonstrates the practical application of data structures such as Trie trees and Huffman encoding.

## Features
- **Typing Text**: Users can type text in a forward-only manner without backward editing.
- **Word Completion Suggestions**: The system provides real-time word completion suggestions based on a predefined dictionary.
- **Text Compression**: Utilizes Huffman encoding to reduce text size while maintaining readability.
- **Secure Storage**: Stores compressed text along with the Huffman tree to enable decompression.
- **File Handling**: Allows users to save and load compressed text files.
- **Text Decompression**: Recovers original text from compressed data.
- **Resume Editing**: Users can continue editing text from previously saved files.

## Implementation Details
- **Word Completion**: Implemented using a Trie or B-tree to efficiently store and retrieve word suggestions.
- **Text Compression**: Utilizes Huffman encoding to convert text into a compressed format.
- **File Storage**: Compressed text and Huffman tree are stored separately for accurate recovery.
- **Text Recovery**: Huffman decoding is used to restore the original text from compressed data.

## How to Run
1. Compile the C++ project using a compatible compiler (e.g., GCC or MSVC).
2. Run the executable and follow the on-screen instructions.
3. Type words, and observe the suggested word completions.
4. Save your text to a file in compressed form.
5. Load and decompress a previously saved file to continue editing.

## Requirements
- C++ compiler (GCC, MSVC, or Clang)
- Basic understanding of file handling and data structures (Trie, Huffman Encoding)

## File Structure
- `main.cpp` - Entry point of the program
- `Trie.cpp/.h` - Implementation of Trie for word suggestions
- `Huffman.cpp/.h` - Implementation of Huffman compression
- `FileHandler.cpp/.h` - Manages file operations (saving/loading text)
- `dictionary.txt` - Predefined list of words for word completion


## Conclusion
This project demonstrates the application of data structures to a real-world problem by implementing a smart text editor. It provides a functional use case for Trie trees and Huffman encoding, ensuring efficient text storage and retrieval.
