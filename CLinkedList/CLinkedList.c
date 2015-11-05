#include <stdio.h>
#include <stdlib.h>

typedef struct ns
{
	int id;
	char* name;
	struct ns* next;
}node;

node* create_node(int,char*);
void insert_node(node*,node*);
node* remove_node(node*,node*);
int getlistlength(node*);
int main(void)
{
	node* lists = create_node(1,"wayne");
	node* tom = create_node(2,"tom");
	node* wang = create_node(3,"wang");
	printf("C Linked List Test \r\n");
	printf("Declare three node :\r\n %d,%s\r\n",lists->id,lists->name);
	printf(" %d,%s\r\n",tom->id,tom->name);
	printf(" %d,%s\r\n",wang->id,wang->name);

	printf("Insert tom and wang to lists:\r\n");
	insert_node(lists,wang);
	insert_node(lists,tom);	

        node* tmp = lists;
	while(tmp!=NULL)
	{
		printf(" %d,%s\r\n",tmp->id,tmp->name);
		tmp = tmp->next;
	}
	printf("lists len = %d\r\n",(getlistlength(lists)));
        printf("Remove wayne : \r\n");
	lists = remove_node(lists,lists);
	tmp = lists;
	while(tmp!=NULL)
	{
		printf(" %d,%s\r\n",tmp->id,tmp->name);
		tmp = tmp->next;
	}
	printf("lists len = %d\r\n",(getlistlength(lists)));
        return 0;	
}

node* create_node(int id,char* name)
{
	node* n = (node*)malloc(sizeof(node));
	n->id = id;
	n->name = name;
	n->next = NULL;
	return n;
}
	
void insert_node(node* node1,node* node2)
{     
	node2->next = node1->next;   // give node1 next node to node2
	node1->next = node2;         // node1 pointer to node2
} 

node* remove_node(node* n1,node* n2)
{
	node* pre;
	if(n2 == n1)   // first node 
	{
		n1 = n1->next;
		return n1;
	}
}
int getlistlength(node* len)
{
	int num = 0;
	while(len!=NULL)
	{
		num++;
		len = len->next;
	}
	return num;
}
