#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
int main()
{
	int m,n;
	cin>>m>>n;
	Node* head=0;
	head=new Node;
	head->data=1;
	head->next=head;
	Node *p=0;
	Node *pre=head;
	for(int i=2;i<=m;i++){
		p=new Node;
		pre->next=p;
		p->data=i;
		p->next=head;
		pre=p;
	}
	p=head;
	do{
		int i=1;
		for(;i<n;i++){
			pre=p;
			p=p->next;	
		}
		cout<<p->data<<' ';
		pre->next=p->next;
		delete p;
		p=pre->next;
	}while(--m);
	cout<<endl;
	return 0;
}

