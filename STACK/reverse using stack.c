// Reverse a string using stack//

#include <stdio.h>
#define SIZE 100

void reverse(char str[]){
    char stack[SIZE];
    int top=-1, i;
    
//push into stack//

    for (i=0; str[i] != '\0'; i++)
        stack[++top]=str[i];
        
// pop from stack//

    for(i=0; top!=-1; i++)
        str[i]=stack[top--];
}

void main(){
    char str[SIZE];
    printf("Enter a string:");
    gets(str);

    reverse(str);

    printf("The reverse string is:%s\n",str);
}
