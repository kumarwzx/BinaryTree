#pragma once

#include<vector>
#include<string>
#include<utility>

#include"config.h"

using namespace std;

// ����Huffman���Ľ���ʽ
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
	HuffTree hf_tree_;	// Huffman��
	HuffCode hf_code_;	// Huffman�����

	// �޲ι��캯��
	Huffman();
	// ����
	~Huffman();

	// ʵ�ֹ���Huffman�����ֵ�
	void HuffmanCoding(CharSet& charset);

	// ʵ���ַ�������
	void codeingThis(string& coding, string str);
	void getCode(string& coding, char cur_char);

	// ʵ������
	void decodingThis(string& str, string coding);
	
	// ѡ�񸸽��Ϊ����Ȩ����С�ʹ�С�Ľ�� s1 ������С
	void select(uint32_t end, uint32_t& s1, uint32_t& s2);

};