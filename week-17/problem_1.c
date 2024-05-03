#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSTACK 100000
typedef struct
{
    int entry[MAXSTACK];
    int top;
}stack;
void init_st(stack *pst)
{
    pst->top=0;
}
void push(int ele , stack *pst)
{
    pst->entry[pst->top]=ele;
    pst->top++;
}
void pop( stack *pst)
{
   --pst->top;
}
void top(int *pn , stack *pst)
{
   *pn=pst->entry[pst->top-1];
}
bool stackempty(stack *pst)
{
    return pst->top==0;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack st1,st2;
    init_st(&st1);
    init_st(&st2);
    int n;
    scanf("%d",&n);
    int ty;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&ty);
        switch (ty) {
        case 1:
        {
            int num;
            scanf("%d",&num);
            push(num, &st1);
        }break;
        case 2:
        {
            if(stackempty(&st2))
            {
                while (!stackempty(&st1)) {
                    int ele;
                    top(&ele,&st1);
                    push( ele,&st2);
                    pop(&st1);
                }
            }
            pop(&st2);
        }break;
        case 3:
        {
            int ele;
            if(stackempty(&st2))
            {
                while (!stackempty(&st1)) {
                    top(&ele,&st1);
                    push( ele,&st2);
                    pop(&st1);
                }
            }
            top(&ele,&st2);
               printf("%d\n",ele);
        }break;
        }
    }
    return 0;
}
