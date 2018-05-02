#include <iostream>

using namespace std;

struct Pod1
{
	int val;
	void print()
	{
		cout << "val is : " << val << endl;
	}
};

struct nonPod1
{
	int val;
	void print()
	{
		cout << "val is : " << val << endl;
	}
	nonPod1() {
		val = 1;
	}
	nonPod1(int m) : val(m) {}
};

struct nonPod2
{
	int val;
	void print()
	{
		cout << "val is : " << val << endl;
	}
	~nonPod2(){}
};

int main()
{
	Pod1 *p1 = new Pod1; 
	Pod1 *p2 = new Pod1();
	p1->print();
	p2->print();
	
	nonPod1 *nP1 = new nonPod1;
	nonPod1 *nP2 = new nonPod1();
	nP1->print();
	nP2->print();
	
	nonPod2 *nP3 = new nonPod2;
	nonPod2 *nP4 = new nonPod2();
	nP3->print();
	nP4->print();
	return 0;
}
