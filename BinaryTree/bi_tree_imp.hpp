#pragma once

#include"bi_tree.h"

#include<string>
#include<sstream>

// 析构
template <typename ElemType>
BiTree<ElemType>::~BiTree() {
	destoryThisBiTree();
}

// 交换所有左右孩子结点
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

// 输出符合条件的结点
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

// 插入数据元素
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

// 按数据域寻找结点
template <typename ElemType>
template <typename _Elem, typename _CMP>
bool BiTree<ElemType>::findNode(BiNodePtr& pos, _Elem p, _CMP cmp) {
	std::stack<BiNodePtr> S;
	BiNodePtr ptr = this->root_;
	bool retflag = false;
	// 后序遍历二叉树寻找符合条件的结点
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

// 遍历函数外部接口 默认执行先序递归遍历
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

// 后序非递归遍历二叉树
template <typename ElemType>
void BiTree<ElemType>::postOrder(const BiNodePtr& nodeptr) {
	std::stack<BiNodePtr> S;
	BiNodePtr ptr = nodeptr;
	BiNodePtr preptr = nullptr;
	while (ptr != nullptr || !S.empty()) {
		if (ptr != nullptr) {
			S.push(ptr);
			ptr = ptr->lchild_;	//左子树非空就入栈
		}
		else {
			ptr = S.top();	//获取当前结点指针
			if ((ptr->rchild_ == nullptr) || (ptr->rchild_ == preptr)) { //左子树为空 且 右子树为空或者右子树已经被遍历过就弹出并访问当前节点
				S.pop();
				visitNode(ptr->data_);
				preptr = ptr;
				ptr = nullptr;
			}
			else {
				ptr = ptr->rchild_;	//如果右子树不为空且没有被遍历过就入栈
			}
		}
	}
}

// 中序非递归遍历二叉树
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

// 先序非递归遍历二叉树
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

//后序递归遍历二叉树
template <typename ElemType>
void BiTree<ElemType>::rePostOrder(const BiNodePtr& nodeptr) {
	if (nodeptr != nullptr) {
		rePostOrder(nodeptr->lchild_);
		rePostOrder(nodeptr->rchild_);
		visitNode(nodeptr->data_);
	}
}

// 中序递归遍历二叉树
template <typename ElemType>
void BiTree<ElemType>::reInOrder(const BiNodePtr& nodeptr) {
	if (nodeptr != nullptr) {
		reInOrder(nodeptr->lchild_);
		visitNode(nodeptr->data_);
		reInOrder(nodeptr->rchild_);
	}
}

// 先序递归遍历二叉树
template <typename ElemType>
void BiTree<ElemType>::rePreOrder(const BiNodePtr& nodeptr) {
	if (nodeptr != nullptr) {
		visitNode(nodeptr->data_);
		rePreOrder(nodeptr->lchild_);
		rePreOrder(nodeptr->rchild_);
	}
}

// 访问结点数据域
template <typename ElemType>
void BiTree<ElemType>::visitNode(const ElemType& data) {
	cout << data;
}

// 求当前二叉树的深度
template <typename ElemType>
int BiTree<ElemType>::thisBiTreeDepth() {
	return biTreeDepth(this->root_);
}

// 后序遍历求二叉树的深度 参考教材示例
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


// 销毁当前二叉树
template <typename ElemType>
void BiTree<ElemType>::destoryThisBiTree() {
	destoryBiTree(root_);
}

// LRD 销毁二叉树
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

// 打印当前二叉树
template <typename ElemType>
void BiTree<ElemType>::printThisBiTree() {
	printBiTree(root_, 0);
}

// RDL 遍历二叉树打印 参考教材上的示例
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

// 从先序序列创建二叉树
template <typename ElemType>
void BiTree<ElemType>::createDLR(stringstream& elemstring, BiNodePtr& nodeptr) {
	// 用来承接结点数据元素
	ElemType node_elem;
	// 当前的游标
	string cur;
	// 解析流
	elemstring >> cur;
	if (*cur.c_str() == END_FLAG) {
		// 每个结点在构造的时候就左右孩子指针被初始化为 nullptr, 所以这里只要返回即可
		return;
	}
	else {
		istringstream node_stream(cur);
		node_stream >> node_elem;
		// 创建一个结点并初始化数据域
		nodeptr = new BiNode(node_elem);
		// 计数器加一
		++node_num_;
		// 递归创建左子树和右子树
		createDLR(elemstring, nodeptr->lchild_);
		createDLR(elemstring, nodeptr->rchild_);
	}
}

// 创建二叉树
template <typename ElemType>
void BiTree<ElemType>::createBiTree() {
	// 先接受输入
	std::cout << "请输入二叉树的先序序列，每个结点用空格隔开， " << END_FLAG << " 代表结点为空:" << std::endl;
	string elemstr;
	// 输入先序序列 以空格隔开 用特殊标记 END_FLAG 代表结点为空 回车结束
	std::getline(std::cin, elemstr);
	stringstream elemstring;
	// 将字串读入流
	elemstring << elemstr;
	createDLR(elemstring, root_);
}


		

