//----------STACK - INTEGER TYPE----------
#define STACK_SIZE  10

typedef  int  SType1;

typedef struct{
	int	top;
	SType1 data[STACK_SIZE];
} stack_t1;

//Functions in this file...
void initialize_s1 (stack_t1 *s);
int is_empty_s1 (stack_t1 *s);
int is_full_s1 (stack_t1 *s);
void push1 (stack_t1 *s, SType1 item);
SType1 pop1 (stack_t1 *s);
//------------------------------------------------------------------------------

void initialize_s1 (stack_t1 *s){
	s->top = -1;
}
//------------------------------------------------------------------------------

int is_empty_s1 (stack_t1 *s){
	if (s->top == -1)
		return 1;
	return 0;
}
//------------------------------------------------------------------------------

int is_full_s1 (stack_t1 *s){
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}
//------------------------------------------------------------------------------

void push1 (stack_t1 *s, SType1 item){
	if (is_full_s1 (s))
		return;
	else{
		(s->top)++;
		s->data[s->top] = item;
	}
}
//------------------------------------------------------------------------------

SType1 pop1 (stack_t1 *s){
	SType1 item;
	if (is_empty_s1 (s)){
		printf("\nWARNING THERE IS NO NUMBER CAN BE USED.\n");
		printf("TERMINATING THE TELEPHONE INSTALLATION PROGRAM...\n\n");
		return -1;
	}
	else{	
		item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}
