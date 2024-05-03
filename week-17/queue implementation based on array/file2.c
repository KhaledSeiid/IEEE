#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
void init_qu(queue *pq)
{
    pq->fr=pq->rear=-1;
}
bool is_empty(queue *pq)
{
    if(pq->rear==-1)return 1;
    else
        return 0;
}
bool is_full(queue *pq)
{
    if(pq->fr==((pq->rear+1)%MAXQUEUE))return 1;
    else
        return 0;
}
void push(queueentry ele ,queue *pq)
{
    if(is_full(pq))return;
    else if(pq->rear==-1)
    {
        pq->rear=(pq->rear+1)%MAXQUEUE;
        pq->fr=(pq->fr+1)%MAXQUEUE;
    }
    else
    {
      pq->rear=(pq->rear+1)%MAXQUEUE;
    }
    pq->entry[pq->rear]=ele;
}
void pop(queueentry *ele, queue *pq)
{
     if(is_empty(pq))return;
	 else if(pq->fr==pq->rear)pq->fr=-1,pq->rear=-1;
     else
      pq->fr=((pq->fr+1)%MAXQUEUE);
}
void front(queueentry *ele, queue *pq)
{
    if(is_empty(pq))return;
    else

      {
          *ele=pq->entry[pq->fr];
      }
}
void clearqueue(queue *pq)
{
    pq->fr=pq->rear=-1;
}
void traversequeue(queue *pq,void (*pf)(queueentry ele))
{
    if(is_empty(pq))return;
    for(int i=pq->fr  ; i!=(pq->rear)%MAXQUEUE ; i=((i+1)%MAXQUEUE))
        (*pf)(pq->entry[i]);
        (*pf)(pq->entry[pq->rear]);

}
