#pragma once

#include<string>

#include"bi_tree_imp.hpp"
#include"huffman_tree.h"

namespace utils{

void startDisplayParse(char& choice); 

// 链式二叉树相关
void display(string& menustr);
void parse(string& menustr, char& choice);
void launch(BiTree<char>& bitree, char choice, bool& qflag);
void tarverseParse(TraverseType& ych);
void traverseNode(BiTree<char>& bitree);
void insertParse(char& node_data, char& node_loc, LR& lr);
void insertNode(BiTree<char>& bitree);
void condNode(BiTree<char>& bitree);
void condParse(char& cond);

// Huffman编码相关
void huffDisplay(string& menustr);
void huffParse(string& menustr, char& choice);
void huffLaunch(Huffman& huff, string& coding, string& str, string& origstr, char choice, bool& qflag);
void huffmanCodeing(Huffman& huff, string& coding, string& str);
void huffmanDecoding(Huffman& huff, string& coding, string& origstr);

} // ! namespace utils