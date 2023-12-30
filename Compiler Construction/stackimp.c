#include<stdio.h>
#include<stdlib.h>
//Today, we are implementing stack
//Stack is Last in, first out
//Operations that we have: push, pop, empty, full, peek:get value of top element w/o removing it

#define MAX 20
int count = 0;
 //Creating a stack
 struct stack
{
    int arr[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top = -1;
}
//check if stack is empty

int isEmpty( st *s)
{
    if(s->top ==-1)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }

}

int isFull( st *s)
{
    if(s->top == MAX-1)
    {
        return 1;

    }
    
    else
    {
        return 0;
    }
    
}

//add elements to stack
void push( st *s, int new)
{
    if(isFull(s))
    {
        printf("Stack is Full");
    }
    else
    { 
        s->top++;
        s->arr[s->top] = new;
        
    }
    
  count++;
}

//Remove an element from Stack

void pop( st *s)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Item popped: %d\n",s->arr[s->top]);
        s-> top--;
    }
   count--;
}

void printstack( st *s)
{
    printf("Stack:");

    for(int i=0;i< count; i++)
    {
        printf("%d ", s->arr[i]);
    }

    printf("\n");
}


//Main function
int main()
{
    int ch, element;
    st *s = (st*) malloc(sizeof(st));

    createEmptyStack(s);

    do{
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print Stack");
        printf("\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the elements to push:");
                scanf("%d", &element);
                push(s, element);
                break;

            case 2:
                pop(s);
                break;

            case 3:
                printstack(s);
                break;
            
            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }
    } 

   while (ch=!4);
   return 0;

}    
