#define MAX_QUEUE_SIZE 20

typedef struct Queue
{
    int front;
    int rear;
    int queue[MAX_QUEUE_SIZE];
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q)
{
    if (q->front == q->rear && q->front == -1)
        return 1;
    else
        return 0;
}
int isFull(Queue *q)
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}
void enQueue(Queue *q, int n)
{
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
        q->queue[0] = n;
    }
    else if (!isFull(q))
        q->queue[++(q->rear)] = n;
}
int deQueue(Queue *q)
{
    int temp;
    if (q->front == q->rear)
    {
        temp = q->queue[q->front];
        q->front = q->rear = -1;
        return temp;
    }
    else if (!isEmpty(q))
        return q->queue[(q->front)++];
    else
        return -1;
}