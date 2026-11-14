#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct{
    Elemtype data[MAXSIZE];
    int front;
    int rear;
}Queue;
//初始化
void initQueue(Queue*Q){
    Q->front=0;
    Q->rear=0;
}
//判断队列是否为空
int isEmpty(Queue*Q){
    if(Q->front==Q->rear){
        return 1;
    }
    else{
        return 0;
    }
}
//出队
int outQueue(Queue*Q){
    if(Q->front==Q->rear){
        return 0;
    }
    Elemtype e=Q->data[Q->front];
    Q->front++;
    return 1;
}
//入队
int eQueue(Queue*Q,Elemtype e){
    if(Q->rear>=MAXSIZE){
        if(adjustQueue(Q)){
            return 0;
        }
    }
    Q->data[Q->rear]=e;
    Q->rear++;
    return 1;
}
//调整队列
int adjustQueue(Queue*Q){
    if(Q->front<=0){
        return 0;
    }
    else{
        int step=Q->front;
        for(int i=Q->front;i<=Q->rear;i++){
            Q->data[i-step]=Q->data[i];
            Q->front=0;
            Q->rear=Q->rear-step;
            return 1;
        }
    }
}