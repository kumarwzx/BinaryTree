#include "utils.h"

#include<iostream>

using namespace std;

namespace utils {

	void huffLaunch(Huffman& huff, string& coding, string& str, string& origstr, char choice, bool& qflag) {
		switch (choice) {
		case '1':
			cout << "-----���ڳ�ʼ��...   ";
			huff.HuffmanCoding(Config::getCharSet());
			cout << "�����!" << endl;
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
		cout << "-----��������Ҫ������ִ�(ֻ��Сд��ĸ���ո�):  ";
		std::getline(std::cin, str);
		cout << "-----��ʼ����...    ";
		huff.codeingThis(coding, str);
		cout << "-----����ɱ���!" << endl;
		str.clear();
	}

	void huffmanDecoding(Huffman& huff, string& coding, string& origstr) {
		cout << "-----��ʼ����...    ";
		huff.decodingThis(origstr, coding);
		cout << "-----The origin string is : " << origstr << endl;
		cout << "-----����ɽ���!" << endl;
		coding.clear();
		origstr.clear();
	}

	void huffDisplay(string& menustr) {
		cout << "\033[32m---1.��ʼ��Huffman��������" << endl;
		cout << "---2.Huffman����" << endl;
		cout << "---3.Huffman����" << endl;
		cout << "---q.�˳�\033[0m" << endl;
		cout << "---*.���������ѡ��(�س�����)";
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
		cout << "\033[32m-1.���Զ�������������" << endl;
		cout << "-2.����Huffman������" << endl;
		cout << "-q.�˳�\033[0m" << endl;
		cout << "-���������ѡ��(1 or 2): ";
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
		cout << "\033[32m---1.��ʼ��������" << endl;
		cout << "---2.���ٶ�����" << endl;
		cout << "---3.���������" << endl;
		cout << "---4.����������" << endl;
		cout << "---5.������" << endl;
		cout << "---6.������������Ľ��" << endl;
		cout << "---7.�����������Һ��ӽ��" << endl;
		cout << "---8.����" << endl;
		cout << "---9.��ӡ��ǰ������" << endl;
		cout << "---q.�˳�\033[0m" << endl;
		cout << "---*.���������ѡ��(�س�����)";
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
		cout << "-----��ѡ�����(8)�������." << endl;
		cout << "-----�ݹ������	 1. ���������2.���������3.�������" << endl;
		cout << "-----�ǵݹ������4. ���������5.���������6.�������" << endl;
		cout << "-----��ѡ���������:";
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
			cout << "-----���ѡ������Ĭ�ϰ��յݹ��������" << endl;
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
		cout << "-----��ѡ�����(5)������." << endl;
		cout << "-----������������������(char����)��";
		std::getline(std::cin, node_data_str);
		node_data = *node_data_str.c_str();
		cout << endl;
		cout << "-----����������λ��(ԭ������ĳһ����������)��";
		std::getline(std::cin, node_loc_str);
		node_loc = *node_loc_str.c_str();
		cout << endl;
		cout << "-----��Ϊ���Ӳ��뻹����Ϊ�Һ��Ӳ��룿(L or R)��";
		cin >> lrchoice;
		cout << endl;
		cout << "-----���ڲ���..." << endl;

		switch (*lrchoice.c_str())
		{
		case 'L':
			lr = LR::LEFT;
			break;
		case 'R':
			lr = LR::RIGHT;
			break;
		default:
			cout << "-----��������ַ����󣬰���Ĭ�����ã���Ϊ������롣";
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
		cout << "-----��ѡ�����(6)������������Ľ��." << endl;
		cout << "-----1.���Ҷ�ӽ�㣻2.�����Ϊ1�Ľ��" << endl;
		cout << "-----���������ѡ��(1 or 2)��";
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
			cout << "�����������Ĭ�����Ҷ�ӽ��" << endl;
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