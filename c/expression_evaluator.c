
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


#define MARK(x)  "\033[1;4;33m" x "\033[0m"


#define TYPE char
#define TYPEFMT "%c"
struct Stack {
  TYPE *data;
  size_t n;
  size_t capacity;
};
#define Stack struct Stack

Stack make_stack(){
  return (Stack){malloc(sizeof(int) * 8), -1 , 8};
}

void free_stack(Stack s){
  free(s.data);
}

void resize_stack(Stack *s, size_t newsize){
  s->data = realloc(s->data, newsize);
  s->capacity = newsize;
#ifdef VERBOSE
    printf("resizing! new size is %ld\n", s->capacity);
#endif
}

bool is_empty(Stack *s){
  return s->n == -1;
}

TYPE *top(Stack *s){
	return s->data + s->n;
}

void push(Stack *s, TYPE element){
  if(s->n == s->capacity) {
    resize_stack(s, s->capacity * 2);
  }
  s->data[++s->n] = element;
#ifdef VERBOSE
  printf("pushed %d\n", element);
#endif
}

TYPE pop(Stack *s){
  if(is_empty(s)) return 0;
#ifdef VERBOSE
  printf("popped!\n");
#endif
  if(s->n > 4 && s->n == s->capacity / 2) {
    resize_stack(s, s->capacity / 2);
  }
  return s->data[s->n--];
}


void print(Stack *s, char* delim){
  if(is_empty(s)) return;
  for(int i = 0; i <= s->n; i++)
    printf(TYPEFMT "%s", s->data[i], delim);
  printf("\n");
}
// Int stack
#define TYPE int
#define TYPEFMT "%d"
struct iStack {
  TYPE *data;
  size_t n;
  size_t capacity;
};
#define iStack struct iStack

iStack imake_stack(){
  return (iStack){malloc(sizeof(int) * 8), -1 , 8};
}

void ifree_stack(iStack s){
  free(s.data);
}

void iresize_stack(iStack *s, size_t newsize){
  s->data = realloc(s->data, newsize);
  s->capacity = newsize;
#ifdef VERBOSE
    printf("resizing! new size is %ld\n", s->capacity);
#endif
}

bool iis_empty(iStack *s){
  return s->n == -1;
}

TYPE *itop(iStack *s){
	return s->data + s->n;
}

void ipush(iStack *s, TYPE element){
  if(s->n == s->capacity) {
    iresize_stack(s, s->capacity * 2);
  }
  s->data[++s->n] = element;
#ifdef VERBOSE
  printf("pushed %d\n", element);
#endif
}

TYPE ipop(iStack *s){
  if(iis_empty(s)) return 0;
#ifdef VERBOSE
  printf("popped!\n");
#endif
  if(s->n > 4 && s->n == s->capacity / 2) {
    iresize_stack(s, s->capacity / 2);
  }
  return s->data[s->n--];
}


void iprint(iStack *s, char* delim){
  if(iis_empty(s)) return;
  for(int i = 0; i <= s->n; i++)
    printf(TYPEFMT "%s", s->data[i], delim);
  printf("\n");
}

// BODMAS
int priority(char op){
	if(op == '+' || op == '-') return 1;
	if(op == '*' || op == '/') return 2;
	return 0;
}

int main(){
	char expression[32];
	scanf("%[^\n]", expression);

	// Shunting Yard algo, infix to postfix
	Stack postfix = make_stack();
	Stack pending = make_stack();
	for(int i = 0; expression[i]; i++){
		if(isalpha(expression[i]))
				push(&postfix, expression[i]);
		else if(priority(expression[i]) != 0){
			while(priority(*top(&pending)) > priority(expression[i])){
				push(&postfix, *top(&pending));
				pop(&pending);
			}
			push(&pending, expression[i]);
		} 
		else if(expression[i] == '(')
			push(&pending, expression[i]);
		else if(expression[i] == ')'){
			while((pending.data[pending.n]) != '('){
				push(&postfix, *top(&pending));
				pop(&pending);
				if(is_empty(&pending))
					break;
			}
			pop(&pending);
		}
	}
	while(!is_empty(&pending)){
		push(&postfix, *top(&pending));
		pop(&pending);
	}
	printf("postfix: ");
	print(&postfix, " ");

	// Evaluating
	int value;
	iStack buffer = imake_stack();
	for(int i = 0; i <= postfix.n; i++){
		if(isalpha(postfix.data[i])) {
			printf("Whats %c? ", postfix.data[i]);
			scanf("%d", &value);
			ipush(&buffer, value);
		} else switch (postfix.data[i]){
			case '+': value = ipop(&buffer);printf("smashing %d\n", value);; *itop(&buffer) += value; break;
			case '-': value = ipop(&buffer);printf("smashing %d\n", value);; *itop(&buffer) -= value; break;
			case '*': value = ipop(&buffer);printf("smashing %d\n", value);; *itop(&buffer) *= value; break;
			case '/': value = ipop(&buffer);printf("smashing %d\n", value);; *itop(&buffer) /= value; break;
		}
		iprint(&buffer, " ");
	}
	printf("RESULT: %d", *itop(&buffer));
}

