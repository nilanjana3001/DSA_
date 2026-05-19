// Implmentation of Queue using Array /

#include<stdio.h>
#define SIZE 6

int front=-1, rear=-1;
int queue [SIZE];

int isfull(){
	return (rear == SIZE-1);   
}

int isempty(){
	return (front == rear);  
}

void enqueue(int x){
	queue[++rear]=x;           
}

int dequeue(){              
	return queue[++front]; 
}

void display(){
	int i;
	printf("The content of queue is:");
	for(i=front+1;i<=rear;i++)
	printf("%d\t",queue[i]);
}

void main(){
	int ch,x;
	do{
		printf("\n1.Enqueue(Insert) 2. Dequeue(Deletation) 3.Display 4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);

		switch(ch){   

		case 1:
			if(isfull())
				printf("The Queue is overflow");
			else{
				printf("Enter a number:");
				scanf("%d",&x);
				enqueue(x);
			}
			break;
			
		case 2:
			if(isempty())
				printf("The queue is underflow.");
			else{
				x=dequeue();   
				printf("Item removed :%d", x);
			}
			break;
				
		case 3:
			display();   
			break;
		}

	}while(ch!=4);
}
