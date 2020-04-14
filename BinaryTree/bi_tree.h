#pragma once
#include<iostream>
#include<stack>

using namespace std;

// ��������־
#define END_FLAG '$'

// ���Ķ���������Ķ���
template <typename ElemType>
struct BiTNode
{
	ElemType data_;	// ������
	BiTNode* lchild_; // ָ��������
	BiTNode* rchild_;	// ָ��������

	// �޲ι���
	BiTNode():lchild_(nullptr), rchild_(nullptr) {};	

	// �ý����������
	BiTNode(ElemType data) :data_(data), lchild_(nullptr), rchild_(nullptr) {};	

	// �ý������������Һ���ָ�빹��
	BiTNode(ElemType data, BiTNode* lchild, BiTNode* rchild) :data_(data), lchild_(lchild), rchild_(rchild) {};

	// ���ƹ���
	BiTNode(BiTNode& copy) : data_(copy.data_), lchild_(copy.lchild_), rchild_(copy.rchild_) {};

	// �������� �ͷ�֮ǰ�Ȱ�ָ���ÿ�
	~BiTNode() {
		if (lchild_ != nullptr || rchild_ != nullptr) {
			cerr << " Current node point to other node !" << endl;
			exit(-1);
		}
	};
};

enum class TraverseType
{
	RECUR_DLR,		// �ݹ�����
	RECUR_LDR,		// �ݹ�����
	RECUR_LRD,		// �ݹ����
	NO_RECUR_DLR,	// �ǵݹ�����
	NO_RECUR_LDR,	// �ǵݹ�����
	NO_RECUR_LRD	// �ǵݹ����
};
enum class LR {
	LEFT,	// ��Ϊ���Ӳ���
	RIGHT	// ��Ϊ���Ӳ���
};

template <typename ElemType>
class BiTree {

public:
	typedef BiTNode<ElemType> BiNode, * BiNodePtr;

	// ���ڵ��ȷ����һ����
	BiNodePtr root_;

	// ��ǰ�������
	int node_num_;	
	
	BiTree():root_(nullptr), node_num_(0) {};	// Ĭ����Ϊ��

	// �ø�������������
	BiTree(ElemType root) :node_num_(1){
		root_ = (new BiNode(root));
		if (root_ == nullptr)
		{
			cerr << "Can't new memory !" << endl;
			exit(-1);
		}
	}

	// ��ָ����ڵ��ָ�빹��
	BiTree(BiNodePtr root, int node_num) :root_(root), node_num_(node_num) {};

	~BiTree();

	// ��ʼ�� �޲ι��캯�����Ѿ�ʵ��
	void initBiTree() {
		destoryThisBiTree();
	};

	// ����������
	void createBiTree();

	// �����������д���
	void createDLR(stringstream& elemstring, BiNodePtr& nodeptr);

	// ����������ٱ�
	void destoryThisBiTree();
	void destoryBiTree(BiNodePtr& nodeptr);

	// ��ӡ������
	void printThisBiTree();
	void printBiTree(const BiNodePtr& nodeptr, int nlayer = 0);

	// ����������
	int thisBiTreeDepth();
	int biTreeDepth(const BiNodePtr& nodeptr);

	//// ���뺢�ӽ��
	//void insertChild()

	// ����������
	// ������ǰ������
	void traverse(TraverseType type);

	// ���ʽ�������� ��ϣ���޸�
	void visitNode(const ElemType& data);
	// �ݹ����
	// 1.����ݹ����
	void rePreOrder(const BiNodePtr& nodeptr);
	// 2.����ݹ����
	void reInOrder(const BiNodePtr& nodeptr);
	// 3.����ݹ����
	void rePostOrder(const BiNodePtr& nodeptr);
	// �ǵݹ����
	// 1.����ǵݹ����
	void preOrder(const BiNodePtr& nodeptr);
	// 2.����ǵݹ����
	void inOrder(const BiNodePtr& nodeptr);
	// 3.����ǵݹ����
	void postOrder(const BiNodePtr& nodeptr);

	// ��������Ԫ��
	template <typename _Elem, typename _CMP>
	bool insertChild(_Elem p, LR type, BiNode c, _CMP cmp);

	// ��������Ѱ�ҽ��
	//bool findNode(ElemType p, BiNodePtr& pos, );
	template <typename _Elem, typename _CMP>
	bool findNode(BiNodePtr& pos, _Elem p, _CMP cmp);

	// ������������Ľ��
	template <typename _CONDITION>
	void printCondNode(_CONDITION condition);

	// �������н������Һ��ӽ��
	void exchangeThisTreeChild();
	void exchangeChild(BiNodePtr& nodeptr);
};
