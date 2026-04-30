// elvaluate prefix expression //
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SIZE 100
float stack[SIZE];
int top=-1;
void push(float x){   
	stack[++top]=x;
}

float pop(){
	return stack[top--];
}
float eval(float opd1, float  opd2, char op){
	switch (op){
		case'+': return opd1+opd2;
			case'-': return opd1-opd2;
				case'*': return opd1*opd2;
					case'/': return opd1/opd2;
						case'^': 
							case'$': return pow(opd1,opd2);
	}
}
float calculate(char prefix[]){
	float stack[SIZE],opd1,opd2,res;
	int top=-1,len,i;
	char symb;
	len=strlen(prefix);
for(i=len-1;i>=0;i--)
	symb=prefix[i];
	if(isdigit(symb)){
		push(symb-'\0');
	}
	
	else{
		opd2=pop();
		opd1=pop();
		res=eval(opd1,opd2,symb);
		push(res);
	}
	return pop();
}

void main(){
	char prefix[SIZE];
	float result;
	printf("Enter any prefix expression:");
	gets(prefix);
	result=calculate(prefix);
	printf("Result=%f",result);
}
