#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct node{
   int val;
   node* next;
}node;

node* creat(){
   node *head,*now,*s;
   int x,flag=1;
   head=new node();
   now=head;
   while(flag){
   	cin>>x;
   	if(x!=0){
   	  s=(node*)malloc(sizeof(node));
   	  s->val=x;
   	  now->next=s;
   	  now=s;
   	}
   	else flag=0;
   }
   head=head->next;
   now->next=nullptr;
   return head;
}

int length(node* head){
	int len=0;
	node *now=head;
	while(now!=nullptr){
		++len;
		now=now->next;
	}
	return len;
}

void print(node* head){
   node *now=head;
   while(now!=nullptr){
   	 cout<<now->val<<' ';
   	 now=now->next;
   }
   cout<<endl;
}

node* del(node* head,int num){
   node *now=head,*pre;
   while(now!=nullptr&&num!=now->val){
   	 pre=now;
   	 now=now->next;
   }
   if(now==nullptr) cout<<"delete error!!!"<<endl;
   else{
   	 if(now==head)
   	  head=now->next;
   	 else
   	  pre->next=now->next;
   }
   return head;
}

node* insert(node *head,int place,int num){
	node *now=head,*s;
	if(place<1||length(head)+1<place) cout<<"insert error!!!"<<endl;
	else if(place==1){
	  s=(node*)malloc(sizeof(node));
	  s->val=num;
	  s->next=now;
	  head=s;
	}
	else{
	  while(place-1>1){
	    --place;
	  	now=now->next;
	  }
	  s=(node*)malloc(sizeof(node));
	  s->val=num;
	  s->next=now->next;
	  now->next=s;
	}
	return head;
}

node* sort(node* head){
	node *p;
	int len=length(head);
	if(head==nullptr||head->next==nullptr)
		return head;
	p=head;
	for(int j=0;j<len-1;++j){
		p=head;
		for(int i=0;i<len-1-j;++i){
          if(p->val>p->next->val)
          	swap(p->val,p->next->val);
          p=p->next;
		}
	}
    return head;
}

node* reverse(node* head){
	node *p,*p2,*p3;
	if(head==nullptr||head->next==nullptr)
		return head;
	p=head; p2=p->next;
	while(p2){
		p3=p2->next;
		p2->next=p;
		p=p2;
		p2=p3;
	}
	head->next=nullptr;
	head=p;
	return head;
}

int main(){
  node* head=creat();
  int len=length(head);
  cout<<len<<endl;
  print(head);
  head=del(head,5);
  print(head);
  head=insert(head,5,5);
  print(head);
  head=sort(head);
  print(head);
  head=reverse(head);
  print(head);
	return 0;
}