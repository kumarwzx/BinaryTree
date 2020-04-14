#include<iostream>
#include<vector>
#include<algorithm>
#include<signal.h>

#include"bi_tree_imp.hpp"
#include"huffman_tree.h"
#include"config.h"
#include"utils.h"

using namespace std;

void test_bi_tree(BiTree<char>& bitree) {
	string menustr;
	char choice;
	bool qflag = false;

	while (!qflag) {
		utils::display(menustr);
		utils::parse(menustr, choice);
		if (choice == ' ') {
			cout << "***Your choice is wrong!!!***" << endl;
			continue;
		}
		utils::launch(bitree, choice, qflag);
		cout << "-----------------------------------------" << endl;
	}
}

void test_huffman_code_decode(Huffman& huff) {
	string menustr;
	char choice;
	bool qflag = false;

	string coding, str, origstr;

	while (!qflag) {
		utils::huffDisplay(menustr);
		utils::huffParse(menustr, choice);
		if (choice == ' ') {
			cout << "***Your choice is wrong!!!***" << endl;
			continue;
		}
		utils::huffLaunch(huff, coding, str, origstr, choice, qflag);
		cout << "-----------------------------------------" << endl;
	}
}

int main() {
	BiTree<char> bitree;
	Huffman huff;
	bool qflag = false;
	while (!qflag)
	{
		char choice;
		utils::startDisplayParse(choice);
		switch (choice)
		{
		case '1':
			test_bi_tree(bitree);
			break;
		case '2':
			test_huffman_code_decode(huff);
			break;
		case 'q':
			qflag = true;
			break;
		}
	}
	
	return 0;
}