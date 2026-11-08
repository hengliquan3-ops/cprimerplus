#include<stdio.h>
//线性表的定义
#define MAXSIZE 100
typedef int E;
typedef struct{
    E data[MAXSIZE];
    int length;
}seqlist;
//线性表的初始化
void intiList(seqlist*L){
    L->length=0;
}
//在尾部添加元素
int appendElem(seqlist*L,E e){
    if(L->length>MAXSIZE){
        printf("超出范围");
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
}
//插入元素
int insertElem(seqlist*L,int pos,E e){
    if(L->length>=MAXSIZE){
        printf("超出范围");
        return 0;
    }
    if(pos<1||pos>L->length){
        printf("位置错误");
        return 0;
    }
    if(pos<L->length){
    for(int i=L->length;i>pos;i--){
        L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=e;
    L->length++;
    }
    return 1;
}
//删除元素
int deleteElem(seqlist*L,int pos,E*e){
    if(L->length<1){
        printf("无法删除");
        return 0;
    }
    if(pos<1||pos>L->length){
        printf("位置错误");
        return 0;
    }
    *e=L->data[pos-1];
    if(pos<L->length){
    for(int i=pos;i<L->length;i++){
        L->data[i-1]=L->data[i];
    }
    }
    L->length--;
    return 1;
}
//查找元素
int foundElem(seqlist*L,E e){
    for(int i=0;i<L->length;i++){
        if(L->data[i]==e){
            return i+1;
        }
    }
    return 0;
}


#include<stdlib.h>
//动态分布内存地址初始化
typedef struct{
    int *data;
    int length;
    int capacity;
}seqlist;
void InitList(seqlist*L,int intiCapacity){
    if(intiCapacity<=0){
        intiCapacity=10;
    }
    L->data=(int*)malloc(intiCapacity*sizeof(int));
    if(L->data==NULL){
        printf("分配内存失败");
        exit(1);
    }
    L->length=0;
    L->capacity=intiCapacity;
}
void DestoryList(seqlist*L){
    if(L->data!=NULL){
        free(L->data);
        L->data=NULL;
    }
    L->length=0;
    L->capacity=0;
}
