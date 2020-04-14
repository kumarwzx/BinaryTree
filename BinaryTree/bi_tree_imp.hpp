#pragma once

#include"bi_tree.h"

#include<string>
#include<sstream>

// ����
template <typename ElemType>
BiTree<ElemType>::~BiTree() {
	destoryThisBiTree();
}

// �����������Һ��ӽ��
template <typename ElemType>
void BiTree<ElemType>::exchangeThisTreeChild() {
	exchangeChild(this->root_);
}

template <typename ElemType>
void BiTree<ElemType>::exchangeChild(BiNodePtr& nodeptr) {
	if (nodeptr != nullptr) {
		BiNodePtr tmp = nodeptr->lchild_;
		nodeptr->lchild_ = nodeptr->rchild_;
		nodeptr->rchild_ = tmp;
		exchangeChild(nodeptr->lchild_);
		exchangeChild(nodeptr->rchild_);
	}
}

// ������������Ľ��
template <typename ElemType>
template <typename _CONDITION>
void BiTree<ElemType>::printCondNode(_CONDITION condition) {
	std::stack<BiNodePtr> S;
	BiNodePtr ptr = this->root_;
	while (ptr != nullptr || !S.empty()) {
		if (ptr != nullptr) {
			S.push(ptr);
			ptr = ptr->lchild_;
		}
		else {
			ptr = S.top();
			S.pop();
			if (condition(ptr)) {
				cout << ptr->data_ << " ";
			}
			ptr = ptr->rchild_;
		}
	}
	cout << endl;
}

// ��������Ԫ��
template <typename ElemType>
template <typename _Elem, typename _CMP>
bool BiTree<ElemType>::insertChild(_Elem p, LR type, BiNode c, _CMP cmp) {
	BiNodePtr pos = nullptr;
	if (!findNode<_Elem, _CMP>(pos, p, cmp)) {
		cout << "Can't locate this Node" << endl;
		return false;
	}
	if (type == LR::LEFT && pos->lchild_ == nullptr) {
		pos->lchild_ = new BiNode(c);
		++node_num_;
		cout << "Successfully insert the left child." << endl;
		return true;
	}
	if (type == LR::RIGHT && pos->rchild_ == nullptr) {
		pos->rchild_ = new BiNode(c);
		++node_num_;
		cout << "Successfully insert the right child." << endl;
		return true;
	}
	cout<<"Can't insert this node"<<endl;
	return false;
}

// ��������Ѱ�ҽ��
template <typename ElemType>
template <typename _Elem, typename _CMP>
bool BiTree<ElemType>::findNode(BiNodePtr& pos, _Elem p, _CMP cmp) {
	std::stack<BiNodePtr> S;
	BiNodePtr ptr = this->root_;
	bool retflag = false;
	// �������������Ѱ�ҷ��������Ľ��
	while (ptr != nullptr || !S.empty()) {
		if (ptr != nullptr) {
			S.push(ptr);
			ptr = ptr->lchild_;
		}
		else {
			ptr = S.top();
			S.pop();
			if (cmp(ptr->data_, p)) {
				pos = ptr;
				retflag = true;
				break;
			}
			ptr = ptr->rchild_;
		}
	}
	while (!S.empty()) {
		S.pop();
	}
	return retflag;
}

// ���������ⲿ�ӿ� Ĭ��ִ������ݹ����
template <typename ElemType>
void BiTree<ElemType>::traverse(TraverseType type) {
	switch (type)
	{
	case TraverseType::RECUR_DLR:
		rePreOrder(this->root_);
		cout << endl;
		break;
	case TraverseType::RECUR_LDR:
		reInOrder(this->root_);
		cout << endl;
		break;
	case TraverseType::RECUR_LRD:
		rePostOrder(this->root_);
		cout << endl;
		break;
	case TraverseType::NO_RECUR_DLR:
		preOrder(this->root_);
		cout << endl;
		break;
	case TraverseType::NO_RECUR_LDR:
		inOrder(this->root_);
		cout << endl;
		break;
	case TraverseType::NO_RECUR_LRD:
		postOrder(this->root_);
		cout << endl;
		break;
	default:
		rePreOrder(this->root_);
		cout << endl;
		break;
	}
}

// ����ǵݹ����������
template <typename ElemType>
void BiTree<ElemType>::postOrder(const BiNodePtr& nodeptr) {
	std::stack<BiNodePtr> S;
	BiNodePtr ptr = nodeptr;
	BiNodePtr preptr = nullptr;
	while (ptr != nullptr || !S.empty()) {
		if (ptr != nullptr) {
			S.push(ptr);
			ptr = ptr->lchild_;	//�������ǿվ���ջ
		}
		else {
			ptr = S.top();	//��ȡ��ǰ���ָ��
			if ((ptr->rchild_ == nullptr) || (ptr->rchild_ == preptr)) { //������Ϊ�� �� ������Ϊ�ջ����������Ѿ����������͵��������ʵ�ǰ�ڵ�
				S.pop();
				visitNode(ptr->data_);
				preptr = ptr;
				ptr = nullptr;
			}
			else {
				ptr = ptr->rchild_;	//�����������Ϊ����û�б�����������ջ
			}
		}
	}
}

// ����ǵݹ����������
template <typename ElemType>
void BiTree<ElemType>::inOrder(const BiNodePtr& nodeptr) {
	std::stack<BiNodePtr> S;
	BiNodePtr ptr = nodeptr;
	while (ptr != nullptr || !S.empty()) {
		if (ptr != nullptr) {
			S.push(ptr);
			ptr = ptr->lchild_;
		}
		else {
			ptr = S.top();
			S.pop();
			visitNode(ptr->data_);
			ptr = ptr->rchild_;
		}
	}
}

// ����ǵݹ����������
template <typename ElemType>
void BiTree<ElemType>::preOrder(const BiNodePtr& nodeptr) {
	std::stack<BiNodePtr> S;
	BiNodePtr ptr = nodeptr;
	while (ptr != nullptr || !S.empty()) {
		if (ptr !=nullptr) {
			visitNode(ptr->data_);
			S.push(ptr);
			ptr = ptr->lchild_;
		}
		else {
			ptr = S.top();
			S.pop();
			ptr = ptr->rchild_;
		}
	}
}

//����ݹ����������
template <typename ElemType>
void BiTree<ElemType>::rePostOrder(const BiNodePtr& nodeptr) {
	if (nodeptr != nullptr) {
		rePostOrder(nodeptr->lchild_);
		rePostOrder(nodeptr->rchild_);
		visitNode(nodeptr->data_);
	}
}

// ����ݹ����������
template <typename ElemType>
void BiTree<ElemType>::reInOrder(const BiNodePtr& nodeptr) {
	if (nodeptr != nullptr) {
		reInOrder(nodeptr->lchild_);
		visitNode(nodeptr->data_);
		reInOrder(nodeptr->rchild_);
	}
}

// ����ݹ����������
template <typename ElemType>
void BiTree<ElemType>::rePreOrder(const BiNodePtr& nodeptr) {
	if (nodeptr != nullptr) {
		visitNode(nodeptr->data_);
		rePreOrder(nodeptr->lchild_);
		rePreOrder(nodeptr->rchild_);
	}
}

// ���ʽ��������
template <typename ElemType>
void BiTree<ElemType>::visitNode(const ElemType& data) {
	cout << data;
}

// ��ǰ�����������
template <typename ElemType>
int BiTree<ElemType>::thisBiTreeDepth() {
	return biTreeDepth(this->root_);
}

// ������������������� �ο��̲�ʾ��
template <typename ElemType>
int BiTree<ElemType>::biTreeDepth(const BiNodePtr& nodeptr) {
	int hl(0),hr(0),max_(0);
	if (nodeptr != nullptr) {
		hl = biTreeDepth(nodeptr->lchild_);
		hr = biTreeDepth(nodeptr->rchild_);
		max_ = hl > hr ? hl : hr;
		return max_ + 1;
	}
	else
		return 0;
}


// ���ٵ�ǰ������
template <typename ElemType>
void BiTree<ElemType>::destoryThisBiTree() {
	destoryBiTree(root_);
}

// LRD ���ٶ�����
template <typename ElemType>
void BiTree<ElemType>::destoryBiTree(BiNodePtr& nodeptr ) {
	if (nodeptr == nullptr)
		return;
	if (nodeptr->lchild_ != nullptr) 
		destoryBiTree(nodeptr->lchild_);
	if(nodeptr->rchild_ != nullptr)
		destoryBiTree(nodeptr->rchild_);
	delete nodeptr;
	nodeptr = nullptr;
	--node_num_;
	return;
}

// ��ӡ��ǰ������
template <typename ElemType>
void BiTree<ElemType>::printThisBiTree() {
	printBiTree(root_, 0);
}

// RDL ������������ӡ �ο��̲��ϵ�ʾ��
template <typename ElemType>
void BiTree<ElemType>::printBiTree(const BiNodePtr& nodeptr, int nlayer) {
	if (nodeptr == nullptr) return;
	printBiTree(nodeptr->rchild_, nlayer + 1);
	for (int i = 0; i < nlayer; ++i) {
		cout << "  ";
	}
	cout << nodeptr->data_ << endl;
	printBiTree(nodeptr->lchild_, nlayer + 1);
}

// ���������д���������
template <typename ElemType>
void BiTree<ElemType>::createDLR(stringstream& elemstring, BiNodePtr& nodeptr) {
	// �����нӽ������Ԫ��
	ElemType node_elem;
	// ��ǰ���α�
	string cur;
	// ������
	elemstring >> cur;
	if (*cur.c_str() == END_FLAG) {
		// ÿ������ڹ����ʱ������Һ���ָ�뱻��ʼ��Ϊ nullptr, ��������ֻҪ���ؼ���
		return;
	}
	else {
		istringstream node_stream(cur);
		node_stream >> node_elem;
		// ����һ����㲢��ʼ��������
		nodeptr = new BiNode(node_elem);
		// ��������һ
		++node_num_;
		// �ݹ鴴����������������
		createDLR(elemstring, nodeptr->lchild_);
		createDLR(elemstring, nodeptr->rchild_);
	}
}

// ����������
template <typename ElemType>
void BiTree<ElemType>::createBiTree() {
	// �Ƚ�������
	std::cout << "��������������������У�ÿ������ÿո������ " << END_FLAG << " ������Ϊ��:" << std::endl;
	string elemstr;
	// ������������ �Կո���� �������� END_FLAG ������Ϊ�� �س�����
	std::getline(std::cin, elemstr);
	stringstream elemstring;
	// ���ִ�������
	elemstring << elemstr;
	createDLR(elemstring, root_);
}


		

