#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class stk_link
{
public:
	node *top;
	void push(int);
	void pop();
	void display();
	stk_link()
	{
		 top=NULL;
	}

};

void stk_link :: push(int n)
{
	node *tmp = new node;   //create new node
	tmp->data=n;
	if(top==NULL)
		tmp->next=NULL;
	else
		tmp ->next = top;

	top=tmp;
	cout <<"Element inserted ";
}
void stk_link :: pop()
{
	if(top==NULL)
		cout<<"stack is empty";
	else
	{
		node *tmp =top;
		cout<<"deleted node: "<<tmp->data;
		top=tmp->next;
		delete(tmp);
	}
}
void stk_link :: display()
{
	node *tmp=top;
	if(top==NULL)
		cout<<"Linked list is empty";
	else
	{
		//cout<<tmp->data<<" ";
		while(tmp!=NULL)
		{
			cout<<tmp->data<<" ";

			tmp=tmp->next;

		}
	}


}
int main()
{
	int choice,value;
	stk_link sl;
	while(1)
	{

		cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl<<"4. exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"enter value:  ";
				cin>>value;
				sl.push(value);
				break;
			case 2:
				sl.pop();
				break;
			case 3:
				sl.display();
				break;
			default:
				exit(0);
		}
	}

}
