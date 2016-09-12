#pragma once

struct ListNode {
	int value;
	ListNode* next;
};


//判断链表是否为空
bool IsEmpty(ListNode* pHead) {
	return pHead->next == NULL;
}

//判断节点pNode是否是最后一个节点
bool IsLast(ListNode* pHead, ListNode* pNode) {
	
	return pNode->next == NULL;
}

//查找某一元素
ListNode* Find(ListNode* pHead, int x) { //pHead 不存储有效元素
	if (pHead == NULL)
		return NULL;
	ListNode* pNode = pHead->next;
	while (pNode != NULL && pNode->value != x)
		pNode = pNode->next;

	return pNode; //查找失败， 返回NULL
}

//查找前一元素
ListNode* FindPrevious(ListNode *pHead, int x) {
	if (pHead == NULL)
		return NULL;
	ListNode* pNode = pHead;
	while (pNode->next != NULL && pNode->next->value != x)
		pNode = pNode->next;
	return pNode; //查找失败，则返回NULL
}

//删除某一元素
void Delete(ListNode* pHead, int x) {
	if (pHead == NULL)
		return;
	ListNode* pNode;
	ListNode* tempNode;

	pNode = FindPrevious(pHead, x); //找到待删除节点的前一个节点
	//（最后一个节点的情况不存在，因为这就意味着x在最后一个节点上的下一个节点上）
	if (!IsLast(pHead, pNode)) { //如果pNode不是最后一个节点
		tempNode = pNode->next; //备份待删除节点
		pNode->next = tempNode->next;
		delete tempNode;
	}
	return;
}

//在链表尾部加入一个节点
void AddToTail(ListNode* pHead, int value) {
	
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->next = NULL;

	if (pHead->next == NULL) //当链表为空时
		pHead->next = pNew;

	else {
		ListNode* pNode = pHead;
		while (pNode->next != NULL)
			pNode = pNode->next;
		pNode->next = pNew;
	}
}

//将位置P向前推进一个节点
//ListNode* Advance(ListNode* pNode) {
//	return pNode->next;
//}

//返回位置P处的节点
ListNode* FindPosi(ListNode* pHead, int posi) { //我们称位置0为头结点的位置，头结点不存储有效的数据
	ListNode* pNode = pHead;
	for (int i = 0; i < posi; i++) {
		pNode = pNode->next;
	}
	return pNode;
}

//在位置Posi后插入元素元素x
void Insert(ListNode* pHead, int Posi, int x) { //有效数据从位置1处开始
	ListNode* tempNode = new ListNode();
	ListNode* PosiNode = FindPosi(pHead, Posi);

	tempNode->value = x;
	tempNode->next = PosiNode->next;
	PosiNode->next = tempNode;
}

//删除整个链表
void DeleteList(ListNode* pHead) {
	if (pHead == NULL)
		return;
	ListNode* pNode = pHead->next;
	pHead->next = NULL;
	ListNode* tempNode = NULL;
	
	while (pNode != NULL) {
		tempNode = pNode->next;
		delete pNode;
		pNode = tempNode;
	}

	return;
}

//遍历链表
void Traverse(ListNode* pHead) {
	if (pHead == NULL)
		return;
	ListNode* pNode = pHead->next;
	while (pNode != NULL) {
		printf("%d ", pNode->value);
		pNode = pNode->next;
	}
	printf("\n");
	return;
}