#pragma once
#include<iostream>
#include<stack>

using namespace std;

// 结点结束标志
#define END_FLAG '$'

// 树的二叉链表结点的定义
template <typename ElemType>
struct BiTNode
{
	ElemType data_;	// 数据域
	BiTNode* lchild_; // 指向左子树
	BiTNode* rchild_;	// 指向右子树

	// 无参构造
	BiTNode():lchild_(nullptr), rchild_(nullptr) {};	

	// 用结点数据域构造
	BiTNode(ElemType data) :data_(data), lchild_(nullptr), rchild_(nullptr) {};	

	// 用结点数据域和左右孩子指针构造
	BiTNode(ElemType data, BiTNode* lchild, BiTNode* rchild) :data_(data), lchild_(lchild), rchild_(rchild) {};

	// 复制构造
	BiTNode(BiTNode& copy) : data_(copy.data_), lchild_(copy.lchild_), rchild_(copy.rchild_) {};

	// 析构函数 释放之前先把指针置空
	~BiTNode() {
		if (lchild_ != nullptr || rchild_ != nullptr) {
			cerr << " Current node point to other node !" << endl;
			exit(-1);
		}
	};
};

enum class TraverseType
{
	RECUR_DLR,		// 递归先序
	RECUR_LDR,		// 递归中序
	RECUR_LRD,		// 递归后序
	NO_RECUR_DLR,	// 非递归先序
	NO_RECUR_LDR,	// 非递归中序
	NO_RECUR_LRD	// 非递归后序
};
enum class LR {
	LEFT,	// 作为左孩子插入
	RIGHT	// 作为左孩子插入
};

template <typename ElemType>
class BiTree {

public:
	typedef BiTNode<ElemType> BiNode, * BiNodePtr;

	// 根节点就确定了一棵树
	BiNodePtr root_;

	// 当前结点总数
	int node_num_;	
	
	BiTree():root_(nullptr), node_num_(0) {};	// 默认树为空

	// 用根结点的数据域构造
	BiTree(ElemType root) :node_num_(1){
		root_ = (new BiNode(root));
		if (root_ == nullptr)
		{
			cerr << "Can't new memory !" << endl;
			exit(-1);
		}
	}

	// 用指向根节点的指针构造
	BiTree(BiNodePtr root, int node_num) :root_(root), node_num_(node_num) {};

	// 初始化 无参构造函数中已经实现
	void initBiTree() {};

	// 创建二叉树
	void createBiTree();

	// 从先序序列中创建
	void createDLR(stringstream& elemstring, BiNodePtr& nodeptr);

	// 后序遍历销毁表
	void destoryThisBiTree();
	void destoryBiTree(BiNodePtr& nodeptr);

	// 打印二叉树
	void printThisBiTree();
	void printBiTree(const BiNodePtr& nodeptr, int nlayer = 0);

	// 求二叉树深度
	int thisBiTreeDepth();
	int biTreeDepth(const BiNodePtr& nodeptr);

	//// 插入孩子结点
	//void insertChild()

	// 遍历二叉树
	// 遍历当前二叉树
	void traverse(TraverseType type);

	// 访问结点数据域 不希望修改
	void visitNode(const ElemType& data);
	// 递归遍历
	// 1.先序递归遍历
	void rePreOrder(const BiNodePtr& nodeptr);
	// 2.中序递归遍历
	void reInOrder(const BiNodePtr& nodeptr);
	// 3.后序递归遍历
	void rePostOrder(const BiNodePtr& nodeptr);
	// 非递归遍历
	// 1.先序非递归遍历
	void preOrder(const BiNodePtr& nodeptr);
	// 2.中序非递归遍历
	void inOrder(const BiNodePtr& nodeptr);
	// 3.后序非递归遍历
	void postOrder(const BiNodePtr& nodeptr);

	// 插入数据元素
	template <typename _Elem, typename _CMP>
	bool insertChild(_Elem p, LR type, BiNode c, _CMP cmp);

	// 按数据域寻找结点
	//bool findNode(ElemType p, BiNodePtr& pos, );
	template <typename _Elem, typename _CMP>
	bool findNode(BiNodePtr& pos, _Elem p, _CMP&& cmp);
};
