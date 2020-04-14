#include "utils.h"

#include<iostream>

using namespace std;

namespace utils {

	void huffLaunch(Huffman& huff, string& coding, string& str, string& origstr, char choice, bool& qflag) {
		switch (choice) {
		case '1':
			cout << "-----正在初始化...   ";
			huff.HuffmanCoding(Config::getCharSet());
			cout << "已完成!" << endl;
			break;
		case '2':
			huffmanCodeing(huff, coding, str);
			break;
		case '3':
			huffmanDecoding(huff, coding, origstr);
			break;
		case 'q':
			qflag = true;
			break;
		}
	}

	void huffmanCodeing(Huffman& huff, string& coding, string& str) {
		cout << "-----请输入需要编码的字串(只大小写字母、空格):  ";
		std::getline(std::cin, str);
		cout << "-----开始编码...    ";
		huff.codeingThis(coding, str);
		cout << "-----已完成编码!" << endl;
		str.clear();
	}

	void huffmanDecoding(Huffman& huff, string& coding, string& origstr) {
		cout << "-----开始解码...    ";
		huff.decodingThis(origstr, coding);
		cout << "-----The origin string is : " << origstr << endl;
		cout << "-----已完成解码!" << endl;
		coding.clear();
		origstr.clear();
	}

	void huffDisplay(string& menustr) {
		cout << "---1.初始化Huffman编译码器" << endl;
		cout << "---2.Huffman编码" << endl;
		cout << "---3.Huffman译码" << endl;
		cout << "---q.退出" << endl;
		cout << "---*.请输入你的选择：(回车结束)";
		std::getline(std::cin, menustr);
		cout << endl;
	}

	void huffParse(string& menustr, char& choice) {
		switch (*menustr.c_str())
		{
		case '1':
			choice = '1';
			break;
		case '2':
			choice = '2';
			break;
		case '3':
			choice = '3';
			break;
		case 'q':
			choice = 'q';
			break;
		default:
			choice = ' ';
			break;
		}
	}


	void startDisplayParse(char& choice) {
		string choice_str;
		cout << "-1.测试二叉树基本操作" << endl;
		cout << "-2.测试Huffman编译码" << endl;
		cout << "-q.退出" << endl;
		cout << "-请输入你的选择(1 or 2): ";
		std::getline(std::cin, choice_str);
		switch (*choice_str.c_str())
		{
		case '1':
			choice = '1';
			break;
		case '2':
			choice = '2';
			break;
		case 'q':
			choice = 'q';
			break;
		default:
			choice = '1';
			break;
		}
	}

	void display(string& menustr) {
		cout << "---1.初始化二叉树" << endl;
		cout << "---2.销毁二叉树" << endl;
		cout << "---3.构造二叉树" << endl;
		cout << "---4.求二叉树深度" << endl;
		cout << "---5.插入结点" << endl;
		cout << "---6.输出满足条件的结点" << endl;
		cout << "---7.交换所有左右孩子结点" << endl;
		cout << "---8.遍历" << endl;
		cout << "---9.打印当前二叉树" << endl;
		cout << "---q.退出" << endl;
		cout << "---*.请输入你的选择：(回车结束)";
		std::getline(std::cin, menustr);
		cout << endl;
	}

	void parse(string& menustr, char& choice) {
		switch (*menustr.c_str())
		{
		case '1':
			choice = '1';
			break;
		case '2':
			choice = '2';
			break;
		case '3':
			choice = '3';
			break;
		case '4':
			choice = '4';
			break;
		case '5':
			choice = '5';
			break;
		case '6':
			choice = '6';
			break;
		case '7':
			choice = '7';
			break;
		case '8':
			choice = '8';
			break;
		case '9':
			choice = '9';
			break;
		case 'q':
			choice = 'q';
			break;
		default:
			choice = ' ';
			break;
		}
	}

	void launch(BiTree<char>& bitree, char choice, bool& qflag) {
		int depth = 0;
		switch (choice)
		{
		case '1':
			bitree.initBiTree();
			break;
		case '2':
			bitree.destoryThisBiTree();
			break;
		case '3':
			bitree.createBiTree();
			break;
		case '4':
			depth = bitree.thisBiTreeDepth();
			cout << "-----the depth of this tree is " << depth << "." << endl;
			break;
		case '5':
			insertNode(bitree);
			break;
		case '6':
			condNode(bitree);
			break;
		case '7':
			bitree.exchangeThisTreeChild();
			break;
		case '8':
			traverseNode(bitree);
			break;
		case '9':
			bitree.printThisBiTree();
			break;
		case 'q':
			qflag = true;
			break;
		}
	}

	void tarverseParse(TraverseType& ych) {
		string tratype;
		cout << endl;
		cout << "-----你选择的是(8)遍历结点." << endl;
		cout << "-----递归遍历：	 1. 先序遍历；2.中序遍历；3.后序遍历" << endl;
		cout << "-----非递归遍历：4. 先序遍历；5.中序遍历；6.后序遍历" << endl;
		cout << "-----请选择插入类型:";
		std::getline(std::cin, tratype);
		cout << endl;
		switch (*tratype.c_str())
		{
		case '1':
			ych = TraverseType::RECUR_DLR;
			break;
		case '2':
			ych = TraverseType::RECUR_LDR;
			break;
		case '3':
			ych = TraverseType::RECUR_LRD;
			break;
		case '4':
			ych = TraverseType::NO_RECUR_DLR;
			break;
		case '5':
			ych = TraverseType::NO_RECUR_LDR;
			break;
		case '6':
			ych = TraverseType::NO_RECUR_LRD;
			break;
		default:
			cout << "-----你的选择有误，默认按照递归先序遍历" << endl;
			ych = TraverseType::RECUR_DLR;
			break;
		}
	}

	void traverseNode(BiTree<char>& bitree) {
		TraverseType ych;
		tarverseParse(ych);

		bitree.traverse(ych);
	}

	void insertParse(char& node_data, char& node_loc, LR& lr) {

		string lrchoice;
		string node_data_str;
		string node_loc_str;

		cout << endl;
		cout << "-----你选择的是(5)插入结点." << endl;
		cout << "-----请输入待插结点的数据域(char类型)：";
		std::getline(std::cin, node_data_str);
		node_data = *node_data_str.c_str();
		cout << endl;
		cout << "-----请输入插入的位置(原二叉树某一结点的数据域)：";
		std::getline(std::cin, node_loc_str);
		node_loc = *node_loc_str.c_str();
		cout << endl;
		cout << "-----作为左孩子插入还是作为右孩子插入？(L or R)：";
		cin >> lrchoice;
		cout << endl;
		cout << "-----正在插入..." << endl;

		switch (*lrchoice.c_str())
		{
		case 'L':
			lr = LR::LEFT;
			break;
		case 'R':
			lr = LR::RIGHT;
			break;
		default:
			cout << "-----你输入的字符有误，按照默认设置，作为左结点插入。";
			lr = LR::LEFT;
			break;
		}
	}

	void insertNode(BiTree<char>& bitree) {
		char node_data;
		char node_loc;
		LR lr;
		insertParse(node_data, node_loc, lr);
		bitree.insertChild(node_loc, lr, node_data, [&](char a, char b) {return a == b; });
	}

	void condParse(char& cond) {
		string cond_str;
		cout << endl;
		cout << "-----你选择的是(6)输出满足条件的结点." << endl;
		cout << "-----1.输出叶子结点；2.输出度为1的结点" << endl;
		cout << "-----请输入你的选择(1 or 2)：";
		std::getline(std::cin, cond_str);
		cout << endl;

		cond = *cond_str.c_str();

		switch (cond)
		{
		case '1':
			break;
		case '2':
			break;
		default:
			cout << "你的输入有误，默认输出叶子结点" << endl;
			cond = '1';
			break;
		}
	}

	void condNode(BiTree<char>& bitree) {
		char cond;
		condParse(cond);
		switch (cond)
		{
		case '1':
			bitree.printCondNode([&](BiTNode<char>* ptr) {if (ptr->lchild_ == nullptr && ptr->rchild_ == nullptr)
				return true;
			else
				return false; });
			break;
		case '2':
			bitree.printCondNode([&](BiTNode<char>* ptr) {if ((ptr->lchild_ == nullptr || ptr->rchild_ == nullptr) && !(ptr->lchild_ == nullptr && ptr->rchild_ == nullptr))
				return true;
			else
				return false; });
			break;
		}
	}

} //! namespace utils