#include"huffman_tree.h"

#include<algorithm>
#include<iostream>

Huffman::Huffman():hf_tree_(nullptr){
	hf_code_.clear();
}

Huffman::~Huffman() {
	delete[] hf_tree_;
	hf_code_.clear();
}

void Huffman::decodingThis(string& str, string coding){
	str.clear();
	uint32_t n = hf_code_.size(); // ��ȡ�ַ����Ĵ�С
	uint32_t m = 2 * n - 1;	// ������ܵ�Huffman���Ľ����
	
	uint32_t index = m;
	for (auto& cur_code : coding) {
		if (cur_code == ' ') continue;
		// ����������Huffman��
		if (index > n) {
			if (cur_code == '0') {
				index = hf_tree_[index].lchild_;

			}
			else {
				index = hf_tree_[index].rchild_;
			}
		}
		// ���������Ҷ�ӽ��������һ���ַ�
		if(index <= n) {
			str = str + hf_code_[index - 1].first;	// �����ִ�
			index = m;	// ��һ�����´Ӹ���㿪ʼ
		}
		
	}
}

void Huffman::getCode(string& coding, char cur_char) {
	for (auto& cur_pair : hf_code_) {
		if (cur_pair.first == cur_char) {
			coding = coding + ' ' + cur_pair.second;	// �봮ƴ�� �Կո���� ע����Ȼ�������Կո�������������ǵĳ�����û�пո�Ҳ��������
			break;
		}
	}
}

void Huffman::codeingThis(string& coding, string str){
	cout << "---The string you want to coding is : " << str << endl;
	std::for_each(str.begin(), str.end(), [&](char cur_char) {getCode(coding, cur_char); });
	cout << "---The coding is : " << coding << endl;
}

void Huffman::select(uint32_t end, uint32_t& s1, uint32_t& s2) {
	uint32_t tmp1 = 0;
	uint32_t tmp2 = 0;
	for (uint32_t i = 1; i <= end; ++i) {
		if (hf_tree_[i].parent_ == 0 && (tmp1 == 0 || tmp1 >= hf_tree_[i].weight_)) {
			tmp2 = tmp1;
			s2 = s1;
			tmp1 = hf_tree_[i].weight_;
			s1 = i;
		} // ��С���ڴ�С���ұ�
		if (hf_tree_[i].parent_ == 0 && i != s1 && (tmp2 == 0 || tmp2 > hf_tree_[i].weight_ )) {
			s2 = i;
			tmp2 = hf_tree_[i].weight_;
		} // ��С���ڴ�С�����
	}
}

void Huffman::HuffmanCoding(CharSet& charset) {
	uint32_t n = charset.size(); // ��ȡ�ַ����Ĵ�С
	uint32_t m = 2 * n - 1;	// ������ܵ�Huffman���Ľ����
	hf_tree_ = new HFNode[m+1];	// ����HuffmanTree���ڴ沢����
	for (uint32_t i = 0; i < n; ++i) {
		hf_tree_[i+1].weight_ = charset[i].second;
	}
	// PPT����һ�������ʱ���Ѿ�����

	// ����Huffman��
	uint32_t s1(0), s2(0);
	for (uint32_t j = n + 1; j <= m; ++j) {
		select(j - 1, s1, s2);
		hf_tree_[s1].parent_ = j;
		hf_tree_[s2].parent_ = j;
		hf_tree_[j].lchild_ = s1;
		hf_tree_[j].rchild_ = s2;
		hf_tree_[j].weight_ = hf_tree_[s1].weight_ + hf_tree_[s2].weight_;
	}
	hf_code_.resize(n);
	// ����Huffman����
	for (uint32_t i = 1; i <= n; i++) {
		char char_key = charset[i - 1].first; // ��ǰ�ļ�ֵ
		string char_code;	// ��ǰ��ֵ�ı���
		for (uint32_t c = i, f = hf_tree_[i].parent_; f != 0; c = f, f = hf_tree_[f].parent_) {	// ��ʼ����
			if (hf_tree_[f].lchild_ == c)
				char_code = '0' + char_code;	// �����ǰ����Ǹ��ڵ�����Ӿ��������ײ����'0'
			else
				char_code = '1' + char_code;	// �����ǰ����Ǹ��ڵ���Һ��Ӿ��������ײ����'1'
		}
		hf_code_[i-1] = std::make_pair(char_key, char_code);	// ��ӽ�Huffman����������
	}
}