//
//  main.cpp
//  LinkList
//
//  Created by kidd on 2018/9/12.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
#define elemType int

typedef struct LNode{
    elemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList CreateList(LinkList &L){
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next = NULL;
    for (int i = 0; i < 10; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = i+1;
        s->next = L->next;
        L->next = s;
    }
    return L;
}

void Print(LinkList L){
    LNode *s = L->next;
    while (s != NULL) {
        printf("%d ",s->data);
        s = s->next;
    }
    printf("\n");
}

int Find(LinkList L, int num){
    
    LNode *pre, *p;
    pre = p = L->next;
    int count = 0;
    while (p!=NULL) {
        if (count < num) {
            count++;
            p = p->next;
        }else{
            p = p->next;
            pre=pre->next;
        }
    }
    if (count < num) {
        return 0;
    }
    printf("%d \n",pre->data);
    return 1;
}

int main(int argc, const char * argv[]) {
    
    LinkList list;
    CreateList(list);
    Print(list);
    printf("%d \n", Find(list, 1));
    
    return 0;
}
