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
	uint32_t n = hf_code_.size(); // 获取字符集的大小
	uint32_t m = 2 * n - 1;	// 计算出总的Huffman数的结点数
	
	uint32_t index = m;
	for (auto& cur_code : coding) {
		if (cur_code == ' ') continue;
		// 按编码搜索Huffman树
		if (index > n) {
			if (cur_code == '0') {
				index = hf_tree_[index].lchild_;

			}
			else {
				index = hf_tree_[index].rchild_;
			}
		}
		// 如果搜索到叶子结点就译出了一个字符
		if(index <= n) {
			str = str + hf_code_[index - 1].first;	// 更新字串
			index = m;	// 下一次重新从根结点开始
		}
		
	}
}

void Huffman::getCode(string& coding, char cur_char) {
	for (auto& cur_pair : hf_code_) {
		if (cur_pair.first == cur_char) {
			coding = coding + ' ' + cur_pair.second;	// 码串拼接 以空格隔开 注意虽然这里是以空格隔开，但是我们的程序在没有空格也是正常的
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
		} // 最小的在次小的右边
		if (hf_tree_[i].parent_ == 0 && i != s1 && (tmp2 == 0 || tmp2 > hf_tree_[i].weight_ )) {
			s2 = i;
			tmp2 = hf_tree_[i].weight_;
		} // 最小的在次小的左边
	}
}

void Huffman::HuffmanCoding(CharSet& charset) {
	uint32_t n = charset.size(); // 获取字符集的大小
	uint32_t m = 2 * n - 1;	// 计算出总的Huffman数的结点数
	hf_tree_ = new HFNode[m+1];	// 分配HuffmanTree的内存并构造
	for (uint32_t i = 0; i < n; ++i) {
		hf_tree_[i+1].weight_ = charset[i].second;
	}
	// PPT上这一步构造的时候已经做了

	// 构造Huffman树
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
	// 计算Huffman编码
	for (uint32_t i = 1; i <= n; i++) {
		char char_key = charset[i - 1].first; // 当前的键值
		string char_code;	// 当前键值的编码
		for (uint32_t c = i, f = hf_tree_[i].parent_; f != 0; c = f, f = hf_tree_[f].parent_) {	// 开始回溯
			if (hf_tree_[f].lchild_ == c)
				char_code = '0' + char_code;	// 如果当前结点是父节点的左孩子就往编码首部添加'0'
			else
				char_code = '1' + char_code;	// 如果当前结点是父节点的右孩子就往编码首部添加'1'
		}
		hf_code_[i-1] = std::make_pair(char_key, char_code);	// 添加进Huffman编码向量中
	}
}