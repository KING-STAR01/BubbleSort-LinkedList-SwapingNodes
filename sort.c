#include<stdio.h>

#include<stdlib.h>


void printlist();

struct node {
	int data;
	struct node *next;
};

struct node *head;
int count=0;

void create()
{
	int x;
	printf("enter -1 to stop taking input\n");
	struct node *temp,*temp1,*temp2;
	temp=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&x);
	if(x!=-1)
	{
		temp->data=x;
		temp->next=NULL;
		head=temp;
		temp1=temp;
		count++;
	}
	else{
		return;
	}
	while(1)
	{
		scanf("%d",&x);
		if(x!=-1)
		{
			temp2=(struct node *)malloc(sizeof(struct node));
			temp2->data=x;
			temp2->next=NULL;
			temp1->next=temp2;
			temp1=temp1->next;
			count++;
		}
		else
		{
			return;
		}
	}
}

void swap(int a,int b)
{
	//printf("in swap\n");
	struct node *px,*py,*prevx=NULL,*prevy=NULL,*temp;
	temp=head;
	while(temp!=NULL && temp->data!=a)
	{
		prevx=temp;
		temp=temp->next;
	}
	px=temp;
	temp=head;
	while(temp!=NULL && temp->data!=b)
	{
		prevy=temp;
		temp=temp->next;
	}
	py=temp;

	
	if(prevx!=NULL)
	{
		prevx->next=py;
	}
	else
	{
		head=py;
	}
	if(prevy!=NULL)
	{
		prevy->next=px;
	}
	else
	{
		head=px;
	}
	temp=py->next;
	py->next=px->next;
	px->next=temp;
	

}



void partition()
{
	struct node *temp,*temp1,*temp2;
	temp=head;

	for(int i=0;i<count;i++)
	{
		temp1=head;
		while(temp1->next!=NULL)
		{
			if(temp1->data > temp1->next->data)
			{
				temp2=temp1;
				swap(temp2->data,temp2->next->data);
			}
			else
			{
				temp1=temp1->next;
			}
		}

	}
}


void printlist()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}



int main()
{
	create();
	printlist();
	printf("enter a value to partition the list\n");
	int x;
	scanf("%d",&x);
	partition();
	//swap(3,4);
	printlist();
}


