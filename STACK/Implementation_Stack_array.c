//Implementation of Stack using array.

#include<stdio.h>

#define SIZE 5

void main()
{
    int stack[SIZE];
    int top=-1;
    int ch, x, i;

    do
    {
        printf("\n1. Push 2. Pop 3. Peek 4. Display 5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                if(top==SIZE-1)
                    printf("Stack is overflow");
                else
                {
                    printf("Enter a number: ");
                    scanf("%d",&x);
                    top=top+1;
                    stack[top]=x;
                }
            }
            break;

            case 2:
            {
                if(top==-1)
                    printf("Stack is underflow");
                else
                {
                    x=stack[top];
                    top=top-1;
                    printf("Pop = %d",x);
                }
            }
            break;

            case 3:
            {
                if(top==-1)
                    printf("Stack is underflow");
                else
                    printf("Peeked = %d",stack[top]);
            }
            break;

            case 4:
            {
                if(top==-1)
                    printf("Stack is empty");
                else
                {
                    printf("Content of stack: ");
                    for(i=top;i>=0;i--)
                        printf("%d\t",stack[i]);
                }
            }
            break;
        }

    } while(ch!=5);
}
