
// AHMET YILDIRIM - 17050111012 - DOUBLE STACK

#define DSTACK_SIZE 100 

typedef  int  SType;

SType DSTACK_EMPTY1 = -123456789;
SType DSTACK_EMPTY2 = -987654321;

typedef struct{
	int top1;
	int top2;
	SType data[DSTACK_SIZE];
} doublestack;

//Functions in this file...
void initialize_s1 (doublestack *s);
void initialize_s2 (doublestack *s);
int is_empty_s1 (doublestack *s);
int is_empty_s2 (doublestack *s);
int is_full_s1 (doublestack *s);
int is_full_s2 (doublestack *s);
void push1 (doublestack *s, SType item);
void push2 (doublestack *s, SType item);
SType pop1 (doublestack *s);
SType pop2 (doublestack *s);

//------------------------------------------------------------------------------

void initialize_s1(doublestack *s){
    s->top1 = -1;
}

void initialize_s2(doublestack *s){
    s->top2 = DSTACK_SIZE;
}
 
//------------------------------------------------------------------------------

int is_empty_s1(doublestack *s){
	if (s->top1 == -1) 
		return 1;
	return 0;
}

int is_empty_s2(doublestack *s){
	if (s->top2 == DSTACK_SIZE)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int is_full_s1(doublestack *s){
	if (s->top2 == s->top1 + 1)
		return 1;
	return 0;
}

int is_full_s2(doublestack *s){
	if (s->top2 == s->top1 + 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push1(doublestack *s, SType item){
    if(is_full_s1(s)){
        printf("\nError: Stack1 is full!\n");
        return;
    }

    s->top1++;
    s->data[s->top1] = item;
    
}

void push2(doublestack *s, SType item){
    if(is_full_s2(s)){
        printf("\nError: Stack2 is full!\n");
        return;
    }
 
    s->top2--;
    s->data[s->top2] = item;
}

//------------------------------------------------------------------------------

SType pop1(doublestack *s){
	SType item;
    if(is_empty_s1(s)){
		printf("\nError: Stack1 is empty!\n");
		item = DSTACK_EMPTY1;
    }
	else{
		item = s->data[s->top1];
    	(s->top1)--;
	}
    return (item);
}

SType pop2(doublestack *s){
	SType item;
    if(is_empty_s2(s)){
        printf("\nError: Stack2 is empty!\n");
        item = DSTACK_EMPTY2;
    }
	else{
		item = s->data[s->top2];
    	(s->top2)++;
	}
    return (item);
}

//------------------------------------------------------------------------------
