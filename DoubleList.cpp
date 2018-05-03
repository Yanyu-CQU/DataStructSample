#include <iostream>

template <typename T>
class DoubleList
{
private:
	struct Node
	{
		T val;
		Node* next;
		Node* pre;
		Node(const T& v = T(), Node* n = nullptr, Node* p = nullptr) : val(v), next(n), pre(p) {}
	};
	int size;
	Node* head;
	Node* tail;
public:
	DoubleList();
	~DoubleList();
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
	T& getIndex(int pos);
};

template <typename T>
DoubleList<T>::DoubleList()
{
	size = 0;
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->pre = head;
}

template <typename T>
DoubleList<T>::~DoubleList()
{
	clear();
	delete head;
	delete tail;
}

template <typename T>
int DoubleList<T>::Size()
{
	return this->size;
}

template <typename T>
bool DoubleList<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
void DoubleList<T>::insert(int pos, const T& v)
{
	if (pos < 0 || pos > this->size) return;//非法位置
	
	Node* tempNode = this->head;
	for (int  i = 0; i < pos; ++i)
		tempNode = tempNode->next;

	Node* newNode = new Node(v);
	newNode->next = tempNode->next;
	newNode->pre = tempNode;
	
	tempNode->next->pre = newNode;
	
	tempNode->next = newNode;
	size++;
}

template <typename T>
void DoubleList<T>::erase(int pos)
{
	if (pos < 0 || pos >= this->size) return;//非法位置，以及尾不允许 
	
	Node* tempNode = this->head;
	for (int  i = 0; i < pos; ++i)
		tempNode = tempNode->next;
	
	Node* delNode = tempNode->next;
	tempNode->next = delNode->next;
	delNode->next->pre = tempNode;
	delete delNode;
	size--;
}

template <typename T>
void DoubleList<T>::clear()
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
void DoubleList<T>::pushHead(const T& v)
{
	this->insert(0, v);
}

template <typename T>
void DoubleList<T>::popHead()
{
	this->erase(0);
}

template <typename T>
void DoubleList<T>::pushTail(const T& v)
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
	this->insert(this->size, v);
}

template <typename T>
void DoubleList<T>::popTail()
{
	this->erase(this->size - 1);
}

template <typename T>
void DoubleList<T>::print()
{
	Node* temp = this->head->next;
	while (temp != this->tail)
	{
		std::cout << temp->val << "\t";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <typename T>
T& DoubleList<T>::getIndex(int pos)//验证一下双向链接是否有错 
{
	Node* temp = this->head->next;
	for (int i = 0; i < pos; ++i)
		temp = temp->next;
	
	Node* temp2 = this->tail->pre;
	for (int i = 0; i < this->size - 1 - pos; ++i)
		temp2 = temp2->pre;
	
	if (temp->val == temp2->val)
		return temp->val;
	else
		return temp2->val;
}



int main()
{
	DoubleList<int> list;
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
	
	list.popTail();
	std::cout << "pop tail:" << std::endl;
	list.print();
	
	list.erase(1);
	std::cout << "erase pop 1:" << std::endl;
	list.print();
	
	list.pushHead(60);
	std::cout << "push head 60:" << std::endl;
	list.print();
	
	list.pushHead(70);
	std::cout << "push head 70:" << std::endl;
	list.print();
	
	std::cout << "get index 2:" << std::endl;
	std::cout << list.getIndex(2) << std::endl;
	
	
	list.clear();
	std::cout << "clear:" << std::endl;
	list.print();
	return 0;
}
