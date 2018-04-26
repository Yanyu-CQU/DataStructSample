#include <iostream>
#include <set>

template <typename T>
struct Node 
{
	Node* next;
	T val;
	Node(const T& v = T(),Node* n = nullptr) : val(v), next(n) {};
};

template <typename T>
class SingleList
{

public:

	SingleList();
	~SingleList();
	int  getSize();
	Node<T>* getHead();
	bool isEmpty();
	void insert(int pos, const T& v);
	void erase(int pos);
	void clear();
	void print();
	void rPrint(Node<T>* pNode);
	Node<T>*   getPos(int pos);
	Node<T>*   rGetKthNode(int k);
	void reverse(); 
	void selectSort();
	void bubbleSort();
	void mergeSortedList(SingleList<T>& listMerge);
	bool isCircle();
	Node<T>* getCircleNode();
	bool isHaveInts(SingleList<T>& cmp);
	Node<T>* setHead(Node<T>* h){
		if(h != nullptr)
			head = h;
	};
	void deleteNode(Node<T>* pNode);
private:
	Node<T>* head;
	int size;
};

template <typename T>
SingleList<T>::SingleList() : head(nullptr), size(0)
{
}

template <typename T>
SingleList<T>::~SingleList()
{
	clear();
}

template <typename T>
int SingleList<T>::getSize()
{
	return size;
}

template <typename T>
bool SingleList<T>::isEmpty()
{
	return (size == 0);
}

template <typename T>
void SingleList<T>::insert(int pos, const T& v)
{
	if (pos < 0 || pos > size) return;
	if (head == nullptr) {
		head = new Node<T>(v);
		head->next = nullptr;
	} else if(pos == 0) {
		Node<T>* newNode = new Node<T>(v);
		newNode->next = head;
		head = newNode;
	} else {
		Node<T>* newNode = new Node<T>(v);
		Node<T>* tempNode = head;
		for (int i = 0; i < pos - 1; ++i) {
			tempNode = tempNode->next;
		}
		newNode->next = tempNode->next;
		tempNode->next = newNode;
	}
	++size;
	return;
}

template <typename T>
void SingleList<T>::erase(int pos)
{
	if (pos < 0 || pos >= size) return;
	if (pos == 0) {
		Node<T>* delNode = head;
		head = head->next;
		delete delNode;
	} else {
		Node<T>* tempNode = head;
		Node<T>* delNode = nullptr;
		for (int i = 0; i < pos - 1; ++i) {
			tempNode = tempNode->next;
		}
		delNode = tempNode->next;
		tempNode->next = delNode->next;
		delete delNode;
	}

	--size;
}

template <typename T>
void SingleList<T>::clear()
{
	Node<T>* tempNode = head;
	Node<T>* delNode = nullptr;
	while (tempNode != nullptr) {
		delNode = tempNode;
		tempNode = tempNode->next;
		delete delNode;
	}
	size = 0;
	head = nullptr;
	return;
}

template <typename T>
void SingleList<T>::print()
{
	Node<T>* printNode = head;
	while (printNode != nullptr) {
		std::cout << printNode->val << "\t";
		printNode = printNode->next;
	}
	std::cout << "\n";
	return;
}

template <typename T>
Node<T>* SingleList<T>:: getPos(int pos)
{
	if (pos < 0 || pos >= size) return nullptr;
	Node<T>* node = head;
	for (int i = 0; i < pos; ++i) {
		node = node->next;
	}
	return node;
}

template <typename T>
Node<T>* SingleList<T>::rGetKthNode(int k)//不知道链表size的写法。。。。。 
{
	//if (k >= size) return nullptr;
	Node<T>* fir = head;
	Node<T>* sec = head; 
	while (k != 0 && fir != nullptr)
	{
		fir = fir->next;
		--k;
	}
	if (k > 0 || fir == nullptr) return nullptr;
	while(fir->next != nullptr)
	{
		fir = fir->next;
		sec = sec->next;
	}
	return sec;
}

template <typename T>
void SingleList<T>::reverse()
{
	if (head == nullptr) return;
	Node<T>* pre = head;
	Node<T>* cur = head->next;
	Node<T>* tempNext = nullptr;
	while (cur != nullptr)
	{
		tempNext = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tempNext;
	}
	head->next = nullptr;
	head = pre;
	return;
}

template <typename T>
Node<T>* SingleList<T>::getHead()
{
	return this->head;
}

template <typename T>
void SingleList<T>::rPrint(Node<T>* pNode)
{
	if (pNode == nullptr) return;
	else rPrint(pNode->next);
	std::cout << pNode->val << "\t";
	if (pNode == head) std::cout << "\n";
}

template <typename T>
void SingleList<T>::selectSort()
{ 
	if (head == nullptr) return;
	Node<T>* cur = head;
	Node<T>* cmp = nullptr;
	while (cur != nullptr)
	{
		cmp = cur->next;
		while (cmp != nullptr)
		{
			if (cmp->val < cur->val)
			{
				T t = cur->val;
				cur->val = cmp->val;
				cmp->val = t;
			}
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return;
}

template <typename T>
void SingleList<T>::mergeSortedList(SingleList<T>& listMerge)
{
	if (head == nullptr || listMerge.getHead() == nullptr) return;
	Node<T>* cur = head;
	Node<T>* cmp = listMerge.getHead();
	int pos = 0;//cur的位置 
	while (cur != nullptr && cmp != nullptr)
	{
		if (cur->val > cmp->val)
		{
			insert(pos,cmp->val);//插入cur前面 
			pos++;
			cmp = cmp->next;
		}
		else if (cur->val <= cmp->val && cur->next != nullptr && cur->next->val >= cmp->val)//插入cur后面 
		{
			insert(pos + 1, cmp->val);
			cmp = cmp->next;
		}
		else
		{
			cur = cur->next;
		} 
	}
	while (cmp != nullptr)
	{
		insert(size,cmp->val);
		cmp = cmp->next;
	}
	return;
}

template <typename T>
bool SingleList<T>::isCircle()
{
	Node<T>* fir = head;
	Node<T>* sec = head;
	while (fir != nullptr && fir->next != nullptr)
	{
		fir = fir->next->next;
		sec = sec->next;
		if (fir == sec) return true;
	}
	return false;
}

template <typename T>
Node<T>* SingleList<T>::getCircleNode()
{
	if (head == nullptr) return nullptr;
	std::set<Node<T>*> count;
	count.insert(head);
	Node<T>* temp = head->next;
	Node<T>* pre = head;
	while (temp != nullptr)
	{
		if (count.insert(temp).second == 0) return pre;
		pre = temp;
		temp = temp->next;
	}
	return nullptr;
}

template <typename T>
bool SingleList<T>::isHaveInts(SingleList<T>& cmp)
{
	if (head == nullptr || cmp.getHead() == nullptr) 
		return false;
	Node<T>* end1 = head;
	Node<T>* end2 = cmp.getHead();
	while (end1->next != nullptr)
	{
		end1 = end1->next;
	}
	while (end2->next != nullptr)
	{
		end2 = end2->next;
	}
	return (end1 == end2);
}

template <typename T>
void SingleList<T>::deleteNode(Node<T>* pNode)
{
	if(head == nullptr) return;
	else if (head == pNode) erase(0);
	else
	{
		if (pNode->next != nullptr)
		{
			Node<T>* pNext = pNode->next;
			pNode->val = pNext->val;
			pNode->next = pNext->next;
			delete pNext;
			--size;
		}
		else
		{
			Node<T>* temp = head;
			while (temp->next->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = nullptr;
			delete pNode;
			--size;
		}
	}
	return;
}


template <typename T>
void SingleList<T>::bubbleSort()
{
	for (Node<T>* q = head; q->next != nullptr; q = q->next)
	{
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			if (p->val > p->next->val)
			{
				T temp = p->val;
				p->val = p->next->val;
				p->next->val = temp;
			}
			p = p->next;
		}
	}
}

int main()
{
	SingleList<int> list;
	list.insert(0,1);
	std::cout << "insert 1:" << std::endl;
	list.print();

	list.insert(1,2);
	std::cout << "insert 2:" << std::endl;
	list.print();

	list.insert(2,3);
	std::cout << "insert 3:" << std::endl;
	list.print();

	list.erase(1);
	std::cout << "erase pos 1:" << std::endl;
	list.print();

	list.insert(1,4);
	std::cout << "insert 4:" << std::endl;
	list.print();

	list.erase(0);
	std::cout << "erase pos 0:" << std::endl;
	list.print();

	list.erase(list.getSize() - 1);
	std::cout << "erase pos tail:" << std::endl;
	list.print();

	list.insert(0,5);
	std::cout << "insert 5:" << std::endl;
	list.print();
	
	list.insert(0,6);
	std::cout << "insert 6:" << std::endl;
	list.print();

	std::cout << "get pos 0: " << list.getPos(0)->val << std::endl;
	std::cout << "get pos 1: " << list.getPos(1)->val << std::endl;
	std::cout << "get pos tail: " << list.getPos(list.getSize() - 1)->val << std::endl;
	
	std::cout << "get rpos 1: " << list.rGetKthNode(1)->val << std::endl; 
	
	
	list.reverse();
	std::cout << "reverse:" << std::endl;
	list.print();
	
	std::cout << "reverse print:" << std::endl;
	list.rPrint(list.getHead());
	
	/*list.selectSort();
	std::cout << "select sort:" << std::endl;
	list.print();*/
	
	list.bubbleSort();
	std::cout << "bubble sort:" << std::endl;
	list.print();
	
	SingleList<int> listMerge;
	listMerge.insert(0,5);
	listMerge.insert(0,7);
	listMerge.insert(0,1);
	listMerge.insert(0,8);
	listMerge.insert(0,7);
	listMerge.selectSort();
	std::cout << "listMerge after select sort:" << std::endl;
	listMerge.print();
	
	list.mergeSortedList(listMerge);
	std::cout << "after merge:" << std::endl;
	list.print();
	
	list.getPos(list.getSize() - 1)->next = list.getHead();//强行制造一个环 
	std::cout << "is have circle:" << list.isCircle() << std::endl;
	//list.print();//无限循环打印 
	
	Node<int>* end = list.getCircleNode();
	end->next = nullptr;
	std::cout << "solute the cirle:" << std::endl;
	list.print();
	
	/*listMerge.clear();
	listMerge.setHead(list.getHead());
	std::cout << "make listMerge same as list:" << std::endl;
	listMerge.print();*///强行制造相同节点 
	
	std::cout << "is have same node:" << list.isHaveInts(listMerge) << std::endl;
	
	list.deleteNode(list.getHead()->next);
	std::cout << "delete pos 1 with O(1) time:" << std::endl;
	list.print();
	
	list.clear();
	std::cout << "clear:" << std::endl;
	list.print();

	return 1;
}







