#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
void init_qu(queue *pq)
{
    pq->fr=NULL;pq->rear=NULL;
}
bool is_empty(queue *pq)
{
    if(pq->rear==NULL)return 1;
    else
        return 0;
}
bool is_full(queue *pq)
{
        return 0;
}
void push(queueentry ele ,queue *pq)
{
    queuenode *pn=(queuenode *)malloc(sizeof(queuenode));
    pn->next=NULL;
    pn->data=ele;
    if(pq->rear==NULL)
    {
        pq->rear=pq->fr=pn;
    }
    else
    {
        pq->rear->next=pn;
      pq->rear=pn;
    }

}
void pop(queueentry *ele, queue *pq)
{
     if(is_empty(pq))return;
     queuenode *pn=(queuenode *)malloc(sizeof(queuenode));
     pn=pq->fr;
     {
         if(pq->fr==pq->rear)pq->fr=pq->rear=NULL;
        else
        pq->fr=pq->fr->next;
     }
     free(pn);
}
void front(queueentry *ele, queue *pq)
{
    if(is_empty(pq))return;
    else

      {
          *ele=pq->fr->data;
      }
}
void clearqueue(queue *pq)
{
    queuenode *pn=(queuenode *)malloc(sizeof(queuenode));
    while(pq->fr)
    {
        pn=pq->fr;
        pq->fr=pq->fr->next;
        free(pn);
    }
    pq->rear=NULL;
}
void traversequeue(queue *pq,void (*pf)(queueentry ele))
{
    if(is_empty(pq))return;
    queuenode *pn=(queuenode *)malloc(sizeof(queuenode));
    pn=pq->fr;
    while(pn)
    {
        (*pf)(pn->data);
        pn=pn->next;
    }

}
