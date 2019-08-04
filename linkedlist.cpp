#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* reverseBetween(Node* head,int l,int r)
{
	int countl=1;
	int countr=1;
	if(l==r || head==NULL || head->next==NULL)
		return head;
	Node* temp=head;
	Node* refu=head;
	Node* prev1=head;
	Node* curr1=head;
	Node* prev2=head;
	Node* curr2=head;
	Node* curr2n=head;
	Node* temp2,*ref;
	stack<Node*>s;
	if(l==1)
	{
		while(countr!=r)
		{
		countr++;
		prev2=curr2;
		curr2=curr2->next;
		}
		curr2n=curr2->next;
		refu=curr2;
		
		while(temp!=curr2)
		{	
			s.push(temp);
			temp=temp->next;
		}
		temp=refu;
		while(!s.empty())
		{
			temp->next=s.top();
			temp2=s.top();
			s.pop();
			temp=temp2;
		}
		temp->next=curr2n;
		return refu;
	}	
	while(countl!=l)
	{
		countl++;
		prev1=curr1;
		curr1=curr1->next;
	}
	while(countr!=r)
	{
		countr++;
		prev2=curr2;
		curr2=curr2->next;
	}
	curr2n=curr2->next;
	//stack<Node*>s;
	temp=curr1;
	while(temp!=curr2)
	{
		s.push(temp);
		temp=temp->next;
	}
	ref=temp;
	while(!s.empty())
	{
		temp->next=s.top();
		temp2=s.top();
		s.pop();
			
		temp=temp2;
	}
	temp->next=curr2n;
	prev1->next=ref;

	return refu;

}
Node* partitionList(Node* head,int x)
{
	if(head==NULL || head->next==NULL)
		return head;
	Node* temp=head;
	Node* header,*tail;
	int countp=0;
	queue <int > q;
	while(temp!=NULL)
	{	if(temp->data<x)
		{
			Node* new_node=new Node;
			new_node->data=temp->data;
			new_node->next=NULL;

			if(countp==0)
				{
					header=new_node;
					countp++;
					tail=header;
				}
			else
				{
					tail->next=new_node;
					tail=new_node;
				}
		}
		else if(temp->data>=x)
		{
			q.push(temp->data);
		}
		temp=temp->next;
	}

	while(!q.empty())
	{
		Node* new_node=new Node;
		new_node->data=q.front();
		q.pop();
		new_node->next=NULL;
		if(countp==0)
		{
			header=new_node;
			tail=header;
			countp++;
		}
		else 
		{
			tail->next=new_node;
			tail=new_node;	
		}
		
	}
	return header;
	
}
Node* addTwoNumbers(Node* A,Node* B)
{
	Node* temp1,*temp2;
	temp1=A;
	temp2=B;
	if(temp2==NULL) return A;
	if(temp1==NULL) return B;
	int upr=0;
	Node* temp,*soon;
	Node* header=NULL;
	int countp=0;
	while(temp1!=NULL || temp2!=NULL)
	{	
		Node* new_node=new Node;
		cout<<"h2"<<endl;
		if(temp1!=NULL && temp2!=NULL)
		{
			new_node->data=(temp1->data+temp2->data+upr)%10;
			cout<<new_node->data<<endl;
			upr=(temp1->data+temp2->data+upr)/10;	
			cout<<upr<<endl;
		}
		else if(temp1==NULL)
		{
			new_node->data=(temp2->data+upr)%10;
			upr=(temp2->data+upr)/10;
		}
		else if(temp2==NULL)
		{	cout<<"h3"<<endl;
			new_node->data=(temp1->data+upr)%10;
			upr=(temp1->data+upr)/10;
		}
		if(temp1!=NULL)
		temp1=temp1->next;
		if(temp2!=NULL)
		temp2=temp2->next;
		new_node->next=NULL;
		if(countp!=0)
		{
			while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=new_node;	
		}
			
		
		if(header==NULL)
		{
			header=new_node;
			countp++;
		}
		temp=header;
	
		
		soon=new_node;
		cout<<"hmm"<<endl;
	}
	if(upr!=0)
	{	Node* new_node=new Node;
		new_node->data=upr;
		new_node->next=NULL;
		soon->next=new_node;
	}
	return header;
}
Node* reverseList(Node* head,int k)
{
	if(head==NULL || k==1)
	{
		return head;
	}
	stack<Node*> s;
	Node* temp=head,*last,*cool,*ref,*land;
	int countp=0;
	while(temp!=NULL)
	{	if(countp!=0)
			temp=land;
		int count=k;
		while(count!=1)
		{
			s.push(temp);
			//prev=temp;
			temp=temp->next;
			count--;
		}
		land=temp->next;

		ref=temp;
		if(countp!=0)
		last->next=ref;

		if(countp==0)
		{
			head=temp;
			countp++;
		}
		
		while (!s.empty()) 
		{ 
        	temp->next = s.top(); 
  	   		temp = temp->next; 
        	s.pop(); 
    	}
    	last=temp; 
      
    
		
		
	}
	last->next=NULL;
	return head;
}
Node* removeNthFromEnd(Node* head,int n)
{
	
	if(head==NULL)
		return head;
	int c=0;
	Node* temp=head;
	while(temp!=NULL)
	{	c++;
		temp=temp->next;
		//cout<<s.top()->data<<" ";
	}
	cout<<c<<endl;
	Node* prev;
	prev=head;
	temp=head;
	if(c==n)
	{
		head=head->next;
		delete prev;
		return head;
	}
	else
	{
		for(int i=0;i<c-n;i++)
		{
			prev=temp;
			temp=temp->next;
		}
		//cout<<endl;
		cout<<temp->data;
		prev->next=temp->next;
		delete temp;
		return head;
	}
	
}

/*ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* temp,*prev;
	
	prev=head;
	if(head==NULL || (head)->next==NULL)
		return	head ;
	temp=(head)->next;
	while(temp!=NULL)
	{
		if(temp->val==prev->val)
		{
			prev->next=temp->next;
			delete temp;
			temp=prev->next;
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
			
	}
	return head;
}*/
void printLast(Node* head,int& count,int k)
{
	if(head==NULL) return;
	printLast(head->next,count,k);

	count++;
	if(count<=k)
	{
		cout<<head->data<<" " ;
	}
}
int peak(Node *head_ref)
{
	if(head_ref==NULL) return -1;
	if(head_ref->next==NULL)
		return head_ref->data;
	Node* curr;
	int prev=head_ref->data;
	for(curr=head_ref->next;curr->next!=NULL;curr=curr->next)
	{
		if(curr->data>=prev && curr->data>=curr->next->data)
		{
			return curr->data;

		}
		prev=curr->data;
	}
	if(curr->data>prev)
		return curr->data;
	else 
		return -1;
}
void motha(Node* head1)
{	cout<<"call aaaya bc"<<endl;
	if(head1==NULL)
		{cout<<"a";
		return ;
		}
	if(head1->next==NULL)
		{cout<<"b";
		return ;}
	Node* temp=head1;
	int maxima=head1->data;
	for(temp=head1->next;temp!=NULL;temp=temp->next)
	{
		if(temp->data>maxima)
			maxima=temp->data;
		cout<<maxima<<" ";
		cout<<temp->data<<endl;
	}
	
}
int product(Node* head_ref)
{	if (head_ref==NULL)
		return 0;
	int pro=1;
	while(head_ref!=NULL)
	{
		pro*=head_ref->data;
		head_ref=head_ref->next;
	}
	return pro;
}
void swapNodes(Node** head_ref,int x,int y)
{	if(x==y) return;
	Node* temp1=*head_ref;
	Node* temp2=*head_ref;
	Node* prev1=NULL;
	Node* prev2=NULL;
	while(temp1->data!=x && temp1!=NULL)
	{	prev1=temp1;
		temp1=temp1->next;
	}
	while(temp2->data!=y && temp2!=NULL)
	{	prev2=temp2;
		temp2=temp2->next;
	}
	if(temp1==NULL || temp2==NULL) return;
	
	if(prev1!=NULL)
		prev1->next=temp2;
	else
		*head_ref=temp2;
	if(prev2!=NULL)
		prev2->next=temp1;
	else 
		*head_ref=temp1;

	Node *temp=temp1->next;
	temp1->next=temp2->next;
	temp2->next=temp;

}
void deletePosition(Node** head_ref,int pos)
{
	Node* temp=*head_ref;
	Node* prev;
	if(temp==NULL) return;
	int count=0;
	if(pos==0)
	{
		*head_ref=temp->next;
		delete temp;
		return;
	}
	while(count!=pos)
	{	prev=temp;
		temp=temp->next;
		if(temp==NULL) return;
		count++;
	}
	prev->next=temp->next;
	delete temp;

}
void deleteNode(Node** head_ref,int x)
{
	Node* temp=*head_ref;
	Node* prev;
	if(temp==NULL) return;
	if(temp->data==x)
	{
		*head_ref=temp->next;
		delete temp;
		return;
	}
	while(temp->data!=x)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	delete temp;
}

void removeFirstNode(Node** head)
{
	Node* temp=(*head);
	(*head)=(*head)->next;
	delete temp;
	
}

void push(Node** head_ref,int x)
{
	Node* new_node=new Node;
	new_node->data=x;
	if((*head_ref)==NULL)
	{
		new_node->next=NULL;
		(*head_ref)=new_node;
		return;
	}
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}

void append(Node** head_ref,int x)
{
	
		Node* new_node=new Node;
		new_node->data=x;
		new_node->next=NULL;
		Node* temp2=(*head_ref);
		if (*head_ref == NULL) 
	    { 
	       *head_ref = new_node; 
	       return; 
	    }
		while(temp2->next!=NULL)
		{
			temp2=temp2->next;
		}
		temp2->next=new_node;
	
}

Node* reverseList(Node* A) 
{
    if(A->next==NULL)
    {
    	Node* new_head=A;
    	return new_head;
    }
    Node* p=reverseList(A->next);
    A->next->next=A;
    A->next=NULL;
    return p;
}
int Mod(int A, int B, int C) 
{	static int i=0;
	static int j=0;
	i++;
	
	if(i==1)
	{
		if(B==0 || B==1){
			cout<<"dfs"<<endl;
			return A%C;
		}
	}
	if(B==1)
		return A;
	int n=A*Mod(A,B-1,C);
	j++;
	
	if(j==B-1){
		
		return n%C;
	}
    
}

/*static int i=0;
    if(B==1)
        return A;
    int n=A*Mod(A,B-1,C);
    i++;
    if(i==B-1)
        return n%C;*/




int main()
{	Node* head=NULL;
	push(&head,8);
	push(&head,7);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<Mod(2,3,3)<<endl;
	//push(&head,5);
	//push(&head,2);
	//push(&head,3);
	//push(&head,4);
	//push(&head,1);
	//Node* head2=NULL;
	//push(&head2,1);
	//push(&head2,5);
	//append(&head,6);
	//push(&head2,6);
	//append(&head,8);
	//
	//cout<<peak(head)<<endl;
	//deleteDuplicates(&head);
	//deleteNode(&head,50);
	//removeFirstNode(&head);
	//deletePosition(&head,10);
	//swapNodes(&head,42,13);
	//cout<<product(head)<<endl;
	//head=removeNthFromEnd(head,1);
	//head=reverseList(head,3);
	//Node* head4=partitionList(head,14); 
	//Node* head3=addTwoNumbers(head,head2);
	//Node *head2=reverseList(head);
	/*for(Node* temp=head2;temp!=NULL;temp=temp->next)
	{
		cout<<temp->data<<" ";
	}
	cout<<endl;*/
	//motha(head);
	//int count=0;
	//int k=2;
	//printLast(head,count,k);
	

	return 0;
}