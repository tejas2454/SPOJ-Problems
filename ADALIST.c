#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct to_do_list
{
    int data;
    struct to_do_list* next;
};

struct to_do_list *head = NULL, *print_head = NULL;
void insertElementAtIndex(struct to_do_list*, int, int);
int pritable_task[500000];
int printable_count = 0;

int main()
{
    struct to_do_list* CreateToDoList(int);
    void DeleteNumberAtIndex(int);
    void printElementAtIndex(int);

    int N, Q, i, operation, index, num;
    int to_do_list[100000];

    scanf("%d", &N);
    scanf("%d" , &Q);
    /*to do list of number*/
    CreateToDoList(N);
    /*Input operation queries*/
    for(i = 0; i < Q; i++)
    {
        scanf("%d", &operation);
        if(operation == 1)
        {
            scanf("%d", &index);
            scanf("%d", &num);
            insertElementAtIndex(head, index, num);
        }
        else if(operation == 2)
        {
            scanf("%d", &index);
            DeleteNumberAtIndex(index);
        }
        else if(operation == 3)
        {
            scanf("%d", &index);
            printElementAtIndex(index);
        }
    }
    for(i = 0; i < printable_count; i++)
    {
        printf("%d\n", pritable_task[i]);
    }
    return(0);
}

struct to_do_list* CreateToDoList(int n)
{
    int i, ch;
	struct to_do_list *prev = NULL;
	struct to_do_list *new = NULL; 

    if(head == NULL)   
    {
        for (i = 0; i < n; i++)
		{
			new = (struct to_do_list*)malloc(sizeof(struct to_do_list));
			scanf("%d", &new->data);
			new->next = NULL;
			if(head == NULL)
				head = new;
			else
				 prev->next = new;
		
			prev = new;
		}	
    }

    return(head);
}

void insertElementAtIndex(struct to_do_list* Head, int index, int data)
{
    struct to_do_list *temp = Head;
	struct to_do_list *temp1 = temp;
	struct to_do_list *new = NULL;
	int count = 1;
    /*If Element to be inserted in first position*/
    new = (struct to_do_list *)malloc(sizeof(struct to_do_list));
	if(new == NULL)
	{
		printf("Error: Failed to allocate memeory!!!\n");
		exit(0);
	}
	memset(new, 0, sizeof(struct to_do_list));
	new->next = NULL;
    new->data = data;
    
    if(index == 1)
	{
		new->next = temp;
        head = new;
	}
	else
	{
    	while(temp != NULL)
	    {
			if(count != index)
			{
				temp1 = temp;
				temp = temp->next;
				count++;
			}
			else
			{
				new->next = temp;
				temp1->next = new;
				break;	
			}
		}
        if(temp1 != NULL)
        {
            temp1->next = new;
            temp1 = temp1->next;
        }
	}
}

void DeleteNumberAtIndex(int index)
{
    struct to_do_list *temp1 = head; 
	struct to_do_list *temp2 = head;
	int count = 1;

    if(index == 1)
    {
        head = head->next;
		free(temp1);	
    }
	else
    {
        while(temp1 != NULL)
		{	
			if(index != count)
			{
				temp2 = temp1;
				temp1 = temp1->next;
				count++;
			}
			else
			{
				temp2->next = temp1->next;
				free(temp1);
				break;
			}
		}
    }
	
}

void printElementAtIndex(int index)
{
    struct to_do_list *temp = head;   
    int count = 1;

    if(!head)
        printf("head NULL\n");
    while(temp != NULL)
    {
        if(count != index)
        {
            temp = temp->next;
            count++;
        }
        else
        { 
            pritable_task[printable_count] = temp->data;
            printable_count++;
            break;         
        }
    }
}
