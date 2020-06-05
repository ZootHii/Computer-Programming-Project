//----------QUEUE - APPLICATION TYPE----------
#define QUEUE_SIZE 100

typedef application_t QType;

typedef struct{ 
	int front, rear;
	QType data[QUEUE_SIZE];
} queue_t;

//Functions in this file...
void initialize_q(queue_t *q);
int is_empty_q(queue_t *q);
int is_full_q(queue_t *q);
void insert(queue_t *q, QType item);
QType remove(queue_t *q);
//------------------------------------------------------------------------------

void initialize_q(queue_t *q){ 
	q->front = 0; 
	q->rear = -1; 
}
//------------------------------------------------------------------------------

int is_empty_q(queue_t *q){ 
	if (q->front > q->rear) 
		return 1; 
	return 0; 
}
//------------------------------------------------------------------------------

int is_full_q(queue_t *q){ 
	if (q->rear == QUEUE_SIZE - 1) 
		return 1; 
	return 0; 
}
//------------------------------------------------------------------------------

void insert(queue_t *q, QType item){ 
	if (is_full_q(q))
		printf("Error : Queue is full!\n");
	else{ 
		q->rear = q->rear + 1; 
		q->data[q->rear] = item;
	} 
}
//------------------------------------------------------------------------------

QType remove(queue_t *q){ 
	QType item;
	if (is_empty_q(q))
		printf("Error : Queue is empty!\n");
	else{
		item = q->data[q->front];
		q->front = q->front + 1;
	}
	return (item);
}
//------------------------------------------------------------------------------
