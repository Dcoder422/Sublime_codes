//arya.haldar.cse17@itbhu.ac.in
#include <bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	node *next;
};
class QUEUE
{
public:
	node *front;
	int size;
	QUEUE()
	{
		front = NULL;
		size = 0;
	}

	void push(int data)
	{
		

	}
	void pop()
	{
		if(!size)
		{
			cout<<"cannot delete..empty stack!!";
			return;
		}

		
	}
	void print()
	{
		node *tmp= front;
		while(tmp!=NULL)
		{
			cout<<tmp->data<<" ";
			tmp=tmp->next;
		}
		cout<<endl;

	}
};


int main()
{
 // stack<int> s;
	QUEUE s;
	s.push(1);
	s.push(2);
oee-cmjp-xzj