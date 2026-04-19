// Convert infix expression to prefix expression //

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

int prcd(char op)
{
if (op=='$'|| op=='^')
return 3;
else if (op=='*'|| op=='/')
return 2;
else if (op=='+'||op=='-')
return 1;
else 
return 0;
}

void convert(char infix[], char prefix[])
{
	int i,len,j=0;
	char symb;

	len=strlen(infix);

	for(i=len-1;i>=0;i--)
	{
	symb=infix[i];

	if(isdigit(symb)||isalpha(symb))
	prefix[j++]=symb;

	else if (symb==')')
	stack[++top]=symb;

	else if (symb=='(')
	{
		while(top!=-1&&stack[top]!=')')
		prefix[j++]=stack[top--];

		top--;   // corrected
	}

	else
	{
		while (top!=-1&&prcd(stack[top])>prcd(symb))   // corrected
		prefix[j++]=stack[top--];

		stack[++top]=symb;   // corrected
	}
	}

	while(top!=-1)
	prefix[j++]=stack[top--];   // corrected

	prefix[j]='\0';

	strrev(prefix);   // keep as you wrote
}

void main(){
	char infix[SIZE], prefix[SIZE];   // corrected

	printf("Enter any infix expression:");
	gets(infix);   // added missing input

	convert(infix,prefix);

	printf("prefix expression =%s\n",prefix);
}
