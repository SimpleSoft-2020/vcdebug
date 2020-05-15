// section_7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <malloc.h>
struct Member
{
	int  ID;
	char Name[40];	
	int age;
	Member* prev;
	Member *next;
};
Member *node_head = NULL;
int member_id = 0;

void add_member()
{
	Member *new_node = (Member*)malloc(sizeof(Member));	
	new_node->next = NULL;
	Member* prev_node = node_head->prev;
	if(prev_node)
	{
		prev_node->next = new_node;
		new_node->prev = prev_node;
		node_head->prev = new_node;

	}
	else
	{
		node_head->next = new_node;
		new_node->prev = node_head;
		node_head->prev = new_node;
	}
	new_node->ID = member_id++;
	printf("Input the Name\n");
	scanf("%s",new_node->Name);	
	printf("Input the age\n");
	scanf("%d",&new_node->age);	
	printf("add member successfully\n");

}
void view_member()
{
	Member *node = node_head->next;
	while(node)
	{
		printf("Name:%s age: %d\n",node->Name,node->age);
		node = node->next;
	}
}
int main(int argc, char* argv[])
{
	printf("Member management system\n");
	printf("\n");
	printf("1.Record the member\n");
	printf("2.View Members\n");
	printf("q.Quit the system\n");

	node_head = (Member*)malloc(sizeof(Member));
	node_head->next = node_head->prev = NULL;
	for(int i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}
	while(true)
	{
		char c=getchar();
		switch(c)
		{
		case '1':		
			add_member();
			break;
		case '2':
			view_member();
			break;
		case 'q':
			return 0;
		case '\n':
			break;
		default:
			printf("try again\n");
			break;
		}
		
	}
	return 0;
}

