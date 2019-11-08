#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<process.h>
/ / Structure is created a node
struct node
{
int info;
struct node *link;/ / A link to the next node
};
/ / A variable named NODE is been defined for the structure
typedef struct node *NODE;
/ / This function is to perform the push operation
NODE push(NODE top)
{
NODE NewNode;
int pushed_item;
/ / A new node is created dynamically
NewNode = (NODE)malloc(sizeof(struct node));
printf(“\ nInput the new value to be pushed on the stack:”);
scanf(“%d”,&pushed_item);
NewNode->info=pushed_item;/ / Data is pushed to the stack
NewNode->link=top;/ / Link pointer is set to the next node
top=NewNode;/ / Top pointer is set
return(top);
}/ *End of push()*/
/ / Following function will implement the pop operation
NODE pop(NODE top)
{
NODE tmp;
if(top == NULL)/ / checking whether the stack is empty or not
printf (“\ nStack is empty\ n”);
else
{
tmp=top;/ / popping the element
printf(“\ nPopped item is %d\ n”,tmp->info);
top=top->link;/ / resetting the top pointer
tmp->link=NULL
free(tmp);/ / freeing the popped node
}
return(top);
}/ *End of pop()*/
/ / This is to display the entire element in the stack
void display(NODE top)
{
if(top==NULL)
printf(“\ nStack is empty\ n”);
else
{
printf(“\ nStack elements:\ n”);
while(top != NULL)
{
printf(“%d\ n”,top->info);
top = top->link;
}/ *End of while */
}/ *End of else*/
}/ *End of display()*/
void main()
{
char opt;
int choice;
NODE Top=NULL;
do
{
clrscr();
printf(“\ n1.PUSH\ n”);
printf(“2.POP\ n”);
printf(“3.DISPLAY\ n”);
printf(“4.EXIT\ n”);
printf(“\ nEnter your choice:”);
scanf(“%d”, &choice);
switch(choice)
{
case 1:
Top=push(Top);
break;
case 2:
Top=pop(Top);
break;
case 3:
display(Top);
break;
case 4:
exit(1);
default:
printf(“\ nWrong choice\ n”);
}/ *End of switch*/
printf (“\ n\ nDo you want to continue (Y/ y) = ”);
fflush(stdin);
scanf(“%c”,&opt);
}while((opt == ‘Y’) | | (opt == ‘y’));
}/ *End of main() */