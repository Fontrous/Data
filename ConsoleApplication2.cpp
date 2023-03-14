#include<stack>
#include<iostream>
using namespace std;
typedef struct BiTNode {
	char data;
	BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T)
{
	char ch;
	ch = getchar();
	if (ch == '^')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void PreOrder(BiTree T) {
	stack<BiTree> S;
	BiTree p = T;
	while (p || !S.empty()) {
		while (p) {
			cout << p->data << " ";
			S.push(p);
			p = p->lchild;
		}
		if (!S.empty())
		{
			p = S.top();
			S.pop();
			p = p->rchild;
		}
	}
	cout << endl;
}
void InOrder(BiTree T) {
	stack<BiTree> S;
	BiTree p = T;
	while (p || !S.empty()) {
		if (p) {
			S.push(p);
			p = p->lchild;
		}
		else {
			p = S.top();
			S.pop();
			cout << p->data << " ";
			p = p->rchild;
		}
	}
	cout << endl;
}
void PostOrder(BiTree T) {
	stack<BiTree> S;
	BiTree cur;
	BiTree pre = NULL;
	S.push(T);
	while (!S.empty()) {
		cur = S.top();		
		if ((cur->lchild == NULL && cur->rchild == NULL) ||
			(pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
		{
			cout << cur->data << " ";
			S.pop();
			pre = cur;
		}
		else {
			if (cur->rchild != NULL)
				S.push(cur->rchild);
			if (cur->lchild != NULL)
				S.push(cur->lchild);
		}
	}
	cout << endl;
}
int main() {
	BiTree T;
	T = NULL;
	CreateBiTree(T);
	cout << "先序遍历：" << endl;
	PreOrder(T);
	cout << "中序遍历:" << endl;
	InOrder(T);
	cout << "后序遍历：" << endl;
	PostOrder(T);
	return 0;
}

