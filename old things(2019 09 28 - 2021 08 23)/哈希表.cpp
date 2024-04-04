#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 10

typedef unsigned int uint;
/*����һ������Ľڵ�*/
typedef struct Node{
    char key[17];
    char value[4];
    struct Node *next;
}Node;

/*����һ������*/
Node *node[HASHSIZE];

/*��ʼ��:Ϊ����ͷ���ٿռ�*/
int init(Node *node)
{
    node = (Node *)malloc(sizeof(Node));
    if(NULL == node)
        return 1;

    memset(node,'\0',sizeof(Node));

    return 0;
}

/*�����ϣֵ*/
uint hash(const char *key){
    uint hash = 0;
    for(; *key; ++key)
    {
        hash = hash*33+*key;
    }
    return hash%HASHSIZE;
}

/*����:���ݹ�ϣֵ�ó�index, Ȼ�󵽶�Ӧ�������в���*/
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

/*���룺�Ȳ��Ҹ�ֵ�Ƿ���ڣ�Ȼ������ϣֵ�������Ӧ������*/
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

/*����*/
int main()
{
    /*Ϊ��ϣ�����һ������*/
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

    /*��ϣ���ʼ���������Ϊ��ͷ��ֵ�Ļ�����ʡ��*/
    int i,j;
    for(i=0;i<HASHSIZE;i++){
        init(node[i]);
    }

    /*������ϣ��*/
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
