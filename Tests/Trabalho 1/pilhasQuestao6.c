/*
 * 6. Dada uma determinada expressão, verificar se os parênteses estão 
 * devidamente agrupados e os fechamentos condizem com as aberturas.
(( X * (( X + Y) I ( J - 3) ) + Y) I ( 4 - 2.5) )
 */

#include<stdio.h>
#include<stdbool.h>
#define STACKSIZE 30

struct stack {
	int top;
	int itens[STACKSIZE];
};

void printStack(struct stack *s){
	printf("Top: %d\n", s->top);
	printf("Itens: ");
	for(int i=0; i<=s->top; i++){
		printf("%d ", s->itens[i]);
	}
	printf("\n");
}

bool fullFunction(struct stack *s){
	if(((s->top)+1)==STACKSIZE){
		return true;
	}
	else{
		return false;
	}
}

void pushFunction(struct stack *s, int valor){
	if(fullFunction(s)){
		printf("Pilha cheia!\n");
		}
	else{
		s->top++;	
		s->itens[s->top] = valor;
		printf("Parênteses aberto com sucesso!\n");
	}
}

bool emptyFunction(struct stack *s){
	if((s->top)<0){
		return true;
	}
	else{
		return false;
	}
}

void popFunction(struct stack *s){
	if(emptyFunction(s)){
		printf("OPERAÇÃO INVÁLIDA! Sem parenteses abertos para fechar!\n");
		}
	else{
		printf("Parenteses fechado com sucesso!\n");
		s->top--;		
		}
}

int sizeFunction(struct stack *s){
	return s->top+1;
}

int stacktopFuncion(struct stack *s){
	return s->itens[s->top];
}

int main(){

	struct stack s;
	s.top = -1;

	char entrada[50];
	//O exemplo do exercício tem 49 caracteres
	gets(entrada);
	
	for(int i=0; i<50; i++){
		if(entrada[i]=='('){
			pushFunction(&s, 1);			
			}
		if(entrada[i]==')'){
			popFunction(&s);
			}
		}
	
	return 0;
}
