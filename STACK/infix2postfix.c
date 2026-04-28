// Infix to postfix expression//

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

int i, top=-1;
char stack[SIZE];

void push(char x){
	stack[++top]=x;
}

char pop(){
	return stack[top--];
}

int priority(char op){
	if(op=='^' || op=='$')
	 return 3;
	else if(op=='*' || op=='/')
    	return 2;
	else if(op=='+' || op=='-')
		return 1;
	else 
		return 0;
}

void convert(char infix[], char postfix[]){
	char symb;
	int i,len,j=0;

	len=strlen(infix);

	for(i=0;i<len;i++){              

		symb = infix[i];            

		

		if(isalpha(symb) || isdigit(symb))
			postfix[j++]= symb;

		else if(symb=='(')
			push(symb);

		else if(symb==')'){
			while(top!=-1 && stack[top]!='(')
				postfix[j++]=pop();
			pop();
		}

		else{
			while(top!=-1 && priority(stack[top])>= priority(symb))
				postfix[j++]=pop();
			push(symb);
		}
	}

	while (top!=-1)                
		postfix[j++]=pop();

	postfix[j]='\0';
}

void main(){
	char infix[80], postfix[80];

	printf("Enter a infix expression:");
	gets(infix);

	convert(infix, postfix);

	printf("The postfix exprression is=%s",postfix);
}
