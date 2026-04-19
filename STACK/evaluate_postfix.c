#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

float stack[100];
int top=-1;

void push(float x){
	stack[++top]=x;
}

float pop(){
	return stack[top--];
}

float eval(float opd1, float opd2, char symb){
	switch(symb){
		case '+': return opd1+opd2;
		case '-': return opd1-opd2;
		case '*': return opd1*opd2;
		case '/': return opd1/opd2;
		case '^':
		case '$': return pow(opd1,opd2);
	}
	return 0;
}

float calculate(char postfix[]){
	int i,len;
	char symb;
	float opd1, opd2,result;

	len=strlen(postfix);

	for(i=0;i<len;i++){
		symb=postfix[i];

		if(isdigit(symb))
			push(symb - 48);
		else{
			opd2 = pop();
			opd1 = pop();
			result = eval(opd1,opd2,symb);
			push(result);
		}
	}
	return pop();
}

int main(){
	float result;
	char postfix[80];

	printf("Enter the postfix expression:");
	gets(postfix);

	result = calculate(postfix);
	printf("Result=%f\n",result);

	return 0;
}