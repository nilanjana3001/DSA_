// WAP fpr checking validity of an expression containing nested parenthesis //
#include<stdio.h>
#define SIZE 100
int isvalid(char exp [0]){
	int top=-1, i;
	char stack[SIZE];
	for(i=0; exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		stack[++top]=exp[i];
		else if (exp[i]==')')
		{
			if(top==-1)
			return 0;
			stack[top--];
		}
	}
		return top--;
}
void main(){
char exp[SIZE];
printf("Enter a expression:");
gets(exp);
if (isvalid(exp))
	printf("The Expression is correct.");
else
printf("THe Expression is wrong.");
}

