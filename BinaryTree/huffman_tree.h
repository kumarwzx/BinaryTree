#pragma once

#include<vector>
#include<string>
#include<utility>

#include"config.h"

using namespace std;

// 定义Huffman树的结点格式
struct HFNode {
	unsigned int weight_;
	unsigned int parent_, lchild_, rchild_;
	HFNode(unsigned int weight=0, unsigned int parent = 0, 
		   unsigned int lchild = 0, unsigned int rchild = 0) : 
		weight_(weight), parent_(parent), lchild_(lchild), rchild_(rchild) {};
};

typedef HFNode* HuffTree;
typedef vector<pair<char, string>> HuffCode;
typedef vector<Freq> CharSet;
//typedef unsigned int uint;

class Huffman {
public:
	HuffTree hf_tree_;	// Huffman树
	HuffCode hf_code_;	// Huffman编码表

	// 无参构造函数
	Huffman();
	// 析构
	~Huffman();

	// 实现构建Huffman编码字典
	void HuffmanCoding(CharSet& charset);

	// 实现字符串编码
	void codeingThis(string& coding, string str);
	void getCode(string& coding, char cur_char);

	// 实现译码
	void decodingThis(string& str, string coding);
	
	// 选择父结点为空且权重最小和次小的结点 s1 保存最小
	void select(uint32_t end, uint32_t& s1, uint32_t& s2);

	// 显示编码字典
	void showHuffTree();

};