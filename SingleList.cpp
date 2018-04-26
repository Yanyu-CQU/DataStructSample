#include <iostream>

template <typename T>
class SingleList
{
private:
	struct Node
	{
		T val;
		Node* next;
		Node(const T& v = T(), Node* n = nullptr) : val(v), next(n) {}
	};
	int size;
	Node* head;
	Node* tail;
public:
	SingleList();
	~SingleList();
	int Size();
	bool isEmpty();
	void insert(int pos, const T& v);
	void erase(int pos);
	void clear();
	void pushHead(const T& v);
	void popHead();
	void pushTail(const T& v);
	void popTail();
	void print();
	T&   rGetKthNode(unsigned int k);
};

template <typename T>
SingleList<T>::SingleList()
{
	size = 0;
	head = new Node();
	tail = new Node();
	head->next = tail;
}

template <typename T>
SingleList<T>::~SingleList()
{
	clear();
	delete head;
	delete tail;
}

template <typename T>
int SingleList<T>::Size()
{
	return this->size;
}

template <typename T>
bool SingleList<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
void SingleList<T>::insert(int pos, const T& v)
{
	if (pos < 0 || pos > this->size) return;//非法位置
	
	Node* tempNode = this->head;
	for (int  i = 0; i < pos; ++i)
		tempNode = tempNode->next;
	Node* newNode = new Node(v);
	newNode->next = tempNode->next;
	tempNode->next = newNode;
	size++;
}

template <typename T>
void SingleList<T>::erase(int pos)
{
	if (pos < 0 || pos >= this->size) return;//非法位置，以及尾不允许 
	
	Node* tempNode = this->head;
	for (int  i = 0; i < pos; ++i)
		tempNode = tempNode->next;
	
	Node* delNode = tempNode->next;
	tempNode->next = delNode->next;
	delete delNode;
	size--;
}

template <typename T>
void SingleList<T>::clear()
{
	/*Node* delNode = this->head->next;
	Node* tempNode = nullptr;
	while (delNode != this->tail)
	{
		tempNode = delNode;
		delNode = delNode->next;
		delete tempNode;
	}
	this->head->next = this->tail;
	size = 0;*/
	int count = this->size;
	for (int i = 0; i < count; ++i)
		this->popHead();
	
}

template <typename T>
void SingleList<T>::pushHead(const T& v)
{
	this->insert(0, v);
}

template <typename T>
void SingleList<T>::popHead()
{
	this->erase(0);
}

template <typename T>
void SingleList<T>::pushTail(const T& v)
{
	/*Node* tempNode = this->head;
	while (tempNode->next != this->tail)
	{
		tempNode = tempNode->next;
	}
	Node* newNode = new Node(v);
	newNode->next = this->tail;
	tempNode->next = newNode;
	size++;*/
	this->insert(this->size - 1, v);
}

template <typename T>
void SingleList<T>::popTail()
{
	this->erase(this->size - 1);
}

template <typename T>
void SingleList<T>::print()
{
	Node* temp = this->head->next;
	while (temp != this->tail)
	{
		std::cout << temp->val << "\t";
		temp = temp->next;
	}
	std::cout << std::endl;
}

// 查找单链表中倒数第K个结点
template <typename T>
T& SingleList<T>::rGetKthNode(unsigned int k) // 函数名前面的R代表反向
{
	
	if(k == 0 ) // 这里k的计数是从1开始的，若k为0或链表为空返回NULL
		return head->val;

	Node * pAhead = head;
	Node * pBehind = head;
	while(k > 1 && pAhead != NULL) // 前面的指针先走到正向第k个结点
	{
		pAhead = pAhead->next;
		k--;
	}
	if(k > 1 || pAhead == NULL)     // 结点个数小于k，返回NULL
		return head->val;
	while(pAhead->next != NULL)  // 前后两个指针一起向前走，直到前面的指针指向最后一个结点
	{
		pBehind = pBehind->next;
		pAhead = pAhead->next;
	}
	
	
	return pBehind->val;  // 后面的指针所指结点就是倒数第k个结点
}



int main()
{
	SingleList<int> list;
	list.pushHead(10);
	std::cout << "push head 10:" << std::endl;
	list.print();
	
	list.pushHead(20);
	std::cout << "push head 20:" << std::endl;
	list.print();
	
	list.popHead();
	std::cout << "pop head:" << std::endl;
	list.print();
	
	list.pushTail(30);
	std::cout << "push tail 30:" << std::endl;
	list.print();
	
	list.insert(0,40);
	std::cout << "insert 40 at 0:" << std::endl;
	list.print();
	
	list.insert(2,50);
	std::cout << "insert 50 at 2:" << std::endl;
	list.print();
	
	std::cout << "3th from tail: ";
	std::cout << list.rGetKthNode(3) << std::endl;
	
	list.popTail();
	std::cout << "pop tail:" << std::endl;
	list.print();
	
	list.erase(1);
	std::cout << "erase pop 1:" << std::endl;
	list.print();
	
	list.clear();
	std::cout << "clear:" << std::endl;
	list.print();
	
	
	
	return 0;
}
