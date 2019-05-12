#include<stdio.h>
#include<stdlib.h>

struct List
{
    struct Node *head;
    struct Node *tail;
};

struct Node
{
    int value;
    struct Node *next;
};

void init(struct List *l)
{
    l->head = NULL;
    l->tail = NULL;
}

int push_back(struct List*l, int value)
{
    struct Node* t=(struct Node*) malloc(sizeof(struct Node));
    t->value = value;
    t->next=NULL;
    if (l->head==NULL){
        l->head = t;
        l->tail = t;
        return 0;
    }
    else{
        l->tail->next=t;
        l->tail = t;
        return 0;
    }
}

int push_front(struct List *l, int value)
{
    struct Node* t=(struct Node*) malloc(sizeof(struct Node));
    t->value=value;
    if (l->head==NULL){
        l->head=t;
        l->tail=t;
        t->next=NULL;
        return 0;
    }
    else{
        t->next=l->head;
        l->head=t;
        return 0;
    }
}

void clear(struct List *l)
{
    struct Node *tmp;
    while (l->head!=NULL){
        tmp=(l->head)->next;
        free(l->head);
        l->head=tmp;
    }
    free(tmp);
}

int isEmpty(struct List* l)
{
    if ((l->head==NULL) && (l->tail==NULL)){
        return 0;
    }
    else {
        return 1;
    }
}

struct Node* find(struct List* l, int value)
{
    struct Node* tmp = l->head;
    while (tmp->next!=NULL){
        if (tmp->value==value){
            return  tmp;
        }
        else{
            tmp=tmp->next;
        }
    }
    return NULL;
}

int insertAfter(struct Node*n, int value)
{
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->value=value;
    t->next=n->next;
    n->next=t;
    return 0;
}

int reMove(struct List* l, int value)
{
    struct Node* adress;
    struct Node* tmp=l->head;
    adress = find(l, value);
    if (adress==NULL){
        return 1;
    }
    else{
        if (adress==l->head){
            l->head=l->head->next;
        }
        else{
            while (tmp->next!=adress){
                tmp=(tmp)->next;
            }
            if (adress==l->tail){
                l->tail=tmp;
            }
            else{
                tmp->next=adress->next;
            }
        }
        free(adress);
        return 0;
    }
}

void print(struct List*l)
{
    struct Node* tmp=l->head;
    while (tmp){
        printf("%d ", tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
    free(tmp);
}
int main(){
    int n, y;
    scanf("%d", &n);
    struct List lis;
    init(&lis);
    for (int i=0; i<n; i++){
        scanf("%d", &y);
        push_back(&lis, y);
    }
    print(&lis);
    int b, c, d;
    struct Node* tmp;
    scanf("%d %d %d", &b, &c, &d);
    tmp=find(&lis, b);
    if (tmp!=NULL){
        printf("1");}
    else{
        printf("0");}
    if (find(&lis, c)){
        printf("1");}
    else{
        printf("0");}
    if (find(&lis, d)){
        printf("1");}
    else{
        printf("0");}
    printf("\n");
    scanf("%d", &y);
    push_back(&lis, y);
    print(&lis);
    scanf("%d", &y);
    push_front(&lis, y);
    print(&lis);
    scanf ("%d %d", &n, &y);
    tmp=lis.head;
    for (int i=1; i<n; i++)
    { tmp=tmp->next;}
    insertAfter(tmp, y);
    print(&lis);
    scanf("%d", &y);
    reMove(&lis, y);
    print(&lis);
    clear(&lis);
}
