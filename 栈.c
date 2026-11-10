#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef struct{
    int data[MAXSIZE];
    int top;
}sqstack;

//初始化
void Initstack(sqstack*q){
    q->top=-1;
}
//判断栈是否为空
int isempty(sqstack*q){
    if(q->top==-1){
        return 1;
    }
    else{
    return 0;
    }
}
//判断栈是否为满
//进栈
int push(sqstack*q,int e){
    if(q->top>=MAXSIZE-1){
        return 0;
    }
    q->top++;
    q->data[q->top]=e;
    return 1;
}
//出栈
int pop(sqstack*q,int *e){
    if(q->top==-1){
        return 0;
    }
    *e=q->data[q->top];
    q->top--;
    return 1;
}
//获取栈顶元素
int gettop(sqstack*q,int *e){
    if(q->top==-1){
        return 0;
    }
    *e=q->data[q->top];
    return 1;
}


//栈的动态内存分配
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef struct{
    int *data;
    int top;
}sqstack;
sqstack*Initstack(){
    sqstack*s=(sqstack*)malloc(sizeof(sqstack));
    s->data=(int *)malloc((sizeof(int))*MAXSIZE);
    s->top=-1;
    return s;
}


//栈的链式实现
typedef int Elemtype;
typedef struct stackNode{
    Elemtype data;
    struct stackNode*next;
}stack;
//链式初始化
stack*Initstack(){
    stack*s=(stack*)malloc(sizeof(stack));
    s->data=0;
    s->next=NULL;
    return s;
}
//链式判断为空
int isempty(stack*q){
    if(q->next==NULL){
        return 1;
    }
    else{
    return 0;
    }
}
//链式进栈
int push(stack*q,Elemtype e){
    stack*s=(stack*)malloc(sizeof(stack));
    s->data=e;
    s->next=q->next;
    q->next=s;
    return 1;
}
//链式出栈
int pop(stack*q,Elemtype*e){
    if(q->next==NULL){
        return 0;
    }
    *e=q->next->data;
    stack*p=q->next;
    q->next=p->next;
    free(p);
    return 1;
}
