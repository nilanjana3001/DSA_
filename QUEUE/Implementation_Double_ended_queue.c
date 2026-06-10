// Implementation of Deque (Double ended queue) using array and function //

#include<stdio.h>
#define SIZE 6

int front=-1,rear=-1;
int deque[SIZE];
 
 
 void enqueue_rear(int x){
 	deque[++rear]=x;
 }
 void enqueue_front(int x){
 	deque[front--]=x;
 }
 int dequeue_rear(){
 	return deque[rear--];
 }
 int dequeue_front(){
 	return deque[++front];
 }

 void display(){
 	int i;
 	printf("The content of Double Ended Queue is:\n");
 	for(i=front+1;i<=rear;i++)
 	printf("%d",deque[i]);
 	printf("\n");
 }
 void main(){
 	int ch,x;
 	do{
 	printf("\n 1.Enqueue rear 2.Enqueue front 3.Dequeue rear 4.Dequeue front 5. Display 6.Exit\n");
 	printf("Enter your choice:");
 	scanf("%d",&ch);
 	switch(ch){
 		
 		case 1:
 			if(rear==SIZE-1)
 			printf("Dequeue rear is overflow\n");
 			else{
 				printf("Enter a number:");
 				scanf("%d",&x);
 				enqueue_rear(x);
			 }
			 break;
			 
			 case 2:
 			if(front==-1)
 				printf("Dequeue front is overflow\n");
 			else{
 				printf("Enter a number:");
 				scanf("%d",&x);
 				enqueue_front(x);
 			}
 			break;
 			
 			case 3:
 				if(rear==front)
 				printf("Dequeue underflow\n");
 				else{
 					x=dequeue_rear();
 					printf("Item deleted =%d",x);
				 }
				 break;
				 
				 case 4:
 				if(rear==front)
 				printf("Dequeue underflow\n");
 				else{
 					x=dequeue_front();
 					printf("Item deleted =%d",x);
				 }
				 break;
				 
				 case 5:
				 	display();
				 	break;
				 	
				 	case 6:
				 		break;
				 		default:
				 			printf("Invalid choice.");
				 		}
					} while(ch!=6);
				 	}
  
