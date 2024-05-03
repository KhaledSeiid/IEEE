#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"header.h"
void dispaly(queueentry ele)
{
    printf("%d\n",ele.x);
}
void main()
{
    queue qu;
    init_qu(&qu);
    if(is_empty(&qu))printf("11111111\n");
    queueentry ele1,ele2 ;
    ele1.x=5;
    push(ele1,&qu);
    push(ele1,&qu);
    push(ele1,&qu);
    push(ele1,&qu);
    if(is_full(&qu))printf("11111111\n");
    traversequeue(&qu,&dispaly);
    return 0;
}
