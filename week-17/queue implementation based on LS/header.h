#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAXQUEUE 4
typedef struct
{
    int x;
}queueentry;
typedef struct node
{
   queueentry data;
   struct node *next;
}queuenode;
typedef struct
{
    struct node *fr;
    struct node *rear;
}queue;
void init_qu(queue *pq);
bool is_empty(queue *pq);
bool is_full(queue *pq);
void push(queueentry ele ,queue *pq);
void pop(queueentry *ele, queue *pq);
void front(queueentry *ele, queue *pq);
void traversequeue(queue *pq,void (*pf)(queueentry ele));
void clearqueue(queue *pq);
#endif // HEADER_H_INCLUDED
