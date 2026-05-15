// Implementation Circular queue //

#include<stdio.h>
#define SIZE 6

int front=-1, rear=-1;
int cqueue [SIZE];

int isfull(){
	return ((rear - front) == SIZE-1);   
}

int isempty(){
	return (rear == front);   
}

void enqueue(int x){
	cqueue[++rear % SIZE] = x;   
}

int dequeue (){
	return cqueue[++front % SIZE];   
}

void display()
{
	int i;   
	printf("The Content of Circular queue is:\n");

	for(i = front+1; i <= rear; i++)
	printf("%d\t", cqueue[i % SIZE]);   

	printf("\n");
}

void main(){
	int x,ch;
	do{
		printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);

		switch (ch){
			
			case 1:
				if(isfull())
					printf("Circular Queue is Overflow.");
				else{
					printf("Enter the number: ");   
					scanf("%d",&x);               
					enqueue(x);
				}
				break;
				
			case 2:
				if(isempty())
					printf("Circular Queue is underflow.");
				else{
					x = dequeue();   
					printf("The content deleted: %d\n",x);
				}
				break;
				
			case 3:
				display();
				break;	
		}

	}while(ch!=4);   
}
