#include<iostream>
#include<vector>
#include<algorithm>
#include"bi_tree_imp.hpp"


using namespace std;

int main() {
	//BiTree<int> bitree1;
	//cout << "Successfully init the empty binary tree" << endl;
	//BiTree<double> bitree2(5);
	//cout << "Successfully init the binary with only root node" << endl;
	//BiTNode<char>* binode1 = new BiTNode<char>('a');
	////BiTree<char> bitree3(binode1,1);
	//BiTNode<int> binode2(3);
	BiTNode<int> binode3;
	cout << "Successfully init the binary with only root node" << endl;
	BiTree<char> bitree3;
	bitree3.createBiTree();
	bitree3.printThisBiTree();
	//cout << "dsada" << endl;
	
	int depth = bitree3.thisBiTreeDepth();
	cout << "the depth of this tree is " << depth << "." << endl;

	bitree3.traverse(TraverseType::NO_RECUR_DLR);
	bitree3.traverse(TraverseType::NO_RECUR_LDR);
	bitree3.traverse(TraverseType::NO_RECUR_LRD);
	bitree3.traverse(TraverseType::RECUR_DLR);
	bitree3.traverse(TraverseType::RECUR_LDR);
	bitree3.traverse(TraverseType::RECUR_LRD);

	bitree3.destoryThisBiTree();

	// vector<int> a(10);
	// sort(a.begin(), a.end(), [&](int a, int b) {return a > b; });

	BiTNode<int> *binode4 = new BiTNode<int>(10);
	BiTNode<int>* binode5 = new BiTNode<int>(11);
	binode4->lchild_ = binode5;
	binode4->lchild_ = nullptr;
	delete(binode4);
	delete(binode5);
	return 0;
}