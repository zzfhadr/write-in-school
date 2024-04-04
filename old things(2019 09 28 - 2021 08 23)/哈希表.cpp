#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 10

typedef unsigned int uint;
/*定义一个链表的节点*/
typedef struct Node{
    char key[17];
    char value[4];
    struct Node *next;
}Node;

/*定义一组链表*/
Node *node[HASHSIZE];

/*初始化:为链表头开辟空间*/
int init(Node *node)
{
    node = (Node *)malloc(sizeof(Node));
    if(NULL == node)
        return 1;

    memset(node,'\0',sizeof(Node));

    return 0;
}

/*计算哈希值*/
uint hash(const char *key){
    uint hash = 0;
    for(; *key; ++key)
    {
        hash = hash*33+*key;
    }
    return hash%HASHSIZE;
}

/*查找:根据哈希值得出index, 然后到对应的链表中查找*/
Node *lookup(const char *key)
{
    Node *np;
    uint index;
    index = hash(key);
    for(np = node[index];np;np = np->next){
        if(!strcmp(key, np->key))
            return np;
    }
    return NULL;
}

/*插入：先查找该值是否存在，然后计算哈希值，插入对应的链表*/
uint install(const char *key, const char *value)
{
    uint index;
    Node *np;

    if(!(np = lookup(key))){
        index = hash(key);
        np = (Node*)malloc(sizeof(Node));
        if(!np)
            return 1;
        strcpy(np->key, key);
        strcpy(np->value, value);

        np->next = node[index];
        node[index] = np;
    }
    return 0;
}

/*例：*/
int main()
{
    /*为哈希表插入一组数据*/
    char key[17] = "10.10.16.31";
    char value[4] = "001";
    install(key, value);

    char key1[17] = "10.10.16.32";
    char value1[4] = "002";
    install(key1, value1);

    char key2[17] = "10.10.16.33";
    char value2[4] = "003";
    install(key2, value2);

    char key3[17] = "10.10.16.34";
    char value3[4] = "004";
    install(key3, value3);

    char key4[17] = "10.10.16.41";
    char value4[4] = "005";
    install(key4, value4);

    Node *np;

    /*哈希表初始化：如果不为表头赋值的话可以省略*/
    int i,j;
    for(i=0;i<HASHSIZE;i++){
        init(node[i]);
    }

    /*遍历哈希表*/
    for(i=0; i<HASHSIZE; i++)
    {
        if(node[i]){
            printf("i:%d, key:%s, value:%s\n", i, node[i]->key, node[i]->value);

            np = node[i]->next;
            while(np){
                printf("i:%d, key:%s, value:%s\n", i,np->key, np->value);
                np = np->next;
            }
        }
    }
    
    return 0;
}
