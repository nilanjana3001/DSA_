//Implement of Priority Queue //

#include<stdio.h>
#define SIZE 7

int front=-1, rear=-1;
int pqueue[SIZE], priority[SIZE];

void enqueue(int x, int p){
	pqueue[++rear]=x;
	priority[rear]=p;
}
int dequeue(){
	int i,min,min_index,x;
	min=priority[front+1];
	min_index=front+1;
	for(i=front+2;i<=rear;i++)
	{
		if(priority[i]<min)
		{
			min=priority[i];
			min_index=i;
		}
	}
	x=pqueue[min_index];
	for(i=min_index;i<rear;i++)
	{
		pqueue[i]=pqueue[i+1];
		priority[i]=priority[i+1];
	}
	rear--;
	return x;
}
int isempty(){
	return(front==rear);
}
int isfull(){
	return (rear==SIZE-1);
}
void display(){
	int i;
	printf("The content of priority queue is:");
	for(i=front+1;i<=rear;i++)
	printf("%d %d\n",pqueue[i],priority[i]);
	printf("\n");
}

int main(){
	int ch,x,p;
	do{
		printf("\n1.enqueue 2.Dequeue 3.Display 4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			
			case 1:
				if(isfull())
					printf("Queue Overflow.");
					else{
						printf("Enter the number and its priority:");
						scanf("%d %d",&x,&p);
						enqueue(x,p);
					}
					break;
					
					case 2:
						if(isempty())
							printf("Queue Underflow");
							else{
								x=dequeue();
								printf("Item deleted:%d\n",x);
							}
							break;
							
							case 3:
								display();
								break;
								default:
									printf("Invalid choice");
							
						
				}
		}
		while(ch!=4);
	}
