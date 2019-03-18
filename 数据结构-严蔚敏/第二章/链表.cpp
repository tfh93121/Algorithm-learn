#include<iostream>

/*
 * 预定义常量 
 */
// 函数结果状态代码

#define OK 1
#define ERROR 0
#define OVERFLOW -2 

// 表最大长度 
#define MAXSIZE 100

using namespace std;

/*
 * 线性表的链式存储实现 
 */


// 元素结构 
struct LNode {
	int data;
	LNode* next;
};

struct LinkList {
	//  
	LNode* head;
	int length;
	
	
	// function 
	int InitList ();
	int GetElem(int i, LNode &e);
	LNode* LocateElem(LNode e);
	int Insert(int i, LNode *e);
	int PushBack(LNode *e);
	int Delete(int i);
	void Reverse();
	void Traverse();
};

// initiate LinkList 
int LinkList::InitList() {
	head = new LNode;
	head->next = NULL;
	length = 0;
	
	return OK;
}

// get i-th LNode
int LinkList::GetElem (int i, LNode &e) {
	LNode *p = head;
	int curPos = 0;
	while(p->next && curPos <= i) {
		p = p->next;
		curPos++;
	}
	if (!p || curPos <= i) return ERROR;
	
	e.data = p->data;
	
	return OK;
}

// get LNode in LinkList
LNode* LinkList::LocateElem(LNode e) {
	LNode *p = head;
	
	while (p->next) {
		p = p->next;
		if (p->data == e.data) return p;
	}
	return p;
}

// insert e to i-th in LinkList
int LinkList::Insert(int i, LNode *e) {
	LNode *p = head;
	LNode *tmp;
	int curPos = 0;
	
	while (p->next && curPos < i) {
		p = p->next;
		curPos++;
	}
	
	if (curPos < i) return OVERFLOW;
	
	cout << p->data << endl;
	e->next = p->next;
	p->next = e;
	
	return OK;
}

// push e to LinkList back
int LinkList::PushBack(LNode *e) {
	LNode *p = head;
	
	while (p->next) {
		p = p->next;
	}
	
	p->next= e;
	e->next = NULL;
	
	return OK;
}

// delete i-th LNode
int LinkList::Delete(int i) {
	LNode *p = head;
	int curPos = 0;
	
	while (p->next && curPos < i) {
		p = p->next;
		curPos++;
	}
	
	if (!p->next) return OVERFLOW;
	
	p->next = p->next->next;
	
	return OK;
}

// reverse LinkList
void LinkList::Reverse() {
	head = head->next;
	LNode *prev = head;
	LNode *next = head->next;

	prev->next = NULL;
	while (next) {
		head = next;
		next = head->next;
		head->next = prev;
		prev = head;
	}
	
	head = new LNode;
	head->next = prev;
}

// traverse LinkList
void LinkList::Traverse() {
	LNode *p = head;
	int cnt = 0;
	while (p->next) {
		p = p->next;
		if (cnt != 0)
			cout << " ";
		cnt = 1;
		
		cout << p->data;
	}
	cout << endl;
}






int main () {
	LinkList List;
	
	List.InitList();
	int A[6] = {1, 3, 4, 6, 7, 9};
	LNode *tmp;
	// 后插 
	for (int i = 0; i < 6; i++) {
		tmp = new LNode;
		tmp->data = A[i];
		List.PushBack(tmp);
	}
	List.Traverse();
	
	// 获取指定位置的元素 
	LNode e1;
	List.GetElem(3, e1);
	cout << e1.data << endl;
	
	// 查找元素 
	LNode *res = List.LocateElem(e1);
	cout << res->data << endl;
	
	// 将元素插入到指定位置 
	LNode *e2 = new LNode;
	e2->data = 12;
	List.Insert(4, e2);
	List.Traverse();
	
	// 删除指定位置元素 
	List.Delete(5);
	List.Traverse();
	
	// 反转
	List.Reverse();
	List.Traverse(); 
	return 0;
}








































