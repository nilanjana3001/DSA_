//WAP for checking validity of an expression of nested brackets//

#include<stdio.h>
#define SIZE 100
int isvalid(char exp[]){
int top=-1, i;
char stack[SIZE],pop;
for(i=0;exp[i]!='\0';i++)
if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
stack[++top]=exp[i];
else if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
{
	if(top==-1)
	return 0;
	pop=stack[top--];
	if(exp[i]==']'&& pop!='[')
	return 0;
	if(exp[i]=='}'&& pop!='{')
	return 0;
	if(exp[i]==')'&& pop!='(')
	return 0;
}
return top--;
}
void main(){
	char exp[SIZE];
	printf("Enter a expression:");
	gets(exp);
	if(isvalid(exp))
	printf("Expresion is correct.");
	else
	printf("Expression is wrong.");
}
