#include<stdio.h>
#include<stdlib.h>
typedef int E;
typedef struct{
    E data;
    struct Node*next;
}Node;
//初始化
Node*initlist(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
//单链表--头插法
int insertElem(Node*L,E e){
    Node*p=(Node*)malloc(sizeof(Node));
    if(p==NULL)return 0;
    p->data=e;
    p->next=L->next;
    L->next=p;
    return 1;
}
//遍历
void ListNode(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
//单链表--在任意位置插入
int insert_Elem(Node*L,E e,int pos){
    if(L==NULL||pos<1){
        return 0;
    }
    Node*pre=L;
    int j=0;
    while(pre!=NULL&&j<pos-1){
        pre=pre->next;
        j++;
    }
    if(pre=NULL){
        return 0;
    }
    Node*p=(Node*)malloc(sizeof(Node));
    if(p==NULL)return 0;
    p->data=e;
    p->next=pre->next;
    pre->next=p;
    return 1;
}
//删除节点
int deleteElem(Node*L,int pos){
    if(L==NULL||pos<1)return 0;
    int j=0;
    Node*pre=L;
    while(pre!=NULL&&j<pos-1){
        pre=pre->next;
        j++;
    }
    Node*p=pre->next;
    if(p==NULL||p->next==NULL){
        return 0;
    }
    pre->next=p->next;
    free(p);
    return 1;
}
//获取链表长度
int lengthList(Node*L){
    if(L==NULL)return 0;
    int j=0;
    Node*p=L->next;
    while(p!=NULL){
        p=p->next;
        j++;
    }
    return j;
}
//释放链表
void destoryList(Node**L){
    if(L==NULL||*L==NULL){
        return;
    }
    Node*p=*L;
    Node*temp=NULL;
    while(p!=NULL){
        temp=p->next;
        free(p);
        p=temp;
    }
    *L=NULL;
}