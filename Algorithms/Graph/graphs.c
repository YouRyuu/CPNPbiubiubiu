//
// Created by youryuu on 19-3-8.
//
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 20

typedef struct GList    //表节点
{
    int adj;
    struct GList *next;
} Glist;

typedef struct GArray {     //顶点表节点
    int adj;
    Glist *head;
} GArray[MAX];

typedef struct GTable {     //邻接表
    GArray gArray;
    int point;
    int edge;
} GTable;

void createGraph(GTable *g) {
    int point, edge;
    scanf("%d %d", &point, &edge);
    g->point = point;
    g->edge = edge;
    for (int i = 0; i < point; i++) {
        g->gArray[i].adj = i;
        g->gArray[i].head = NULL;
    }
    int adj1, adj2;
    for (int i = 0; i < edge; i++) {
        scanf("%d %d", &adj1, &adj2);
        Glist *glist = (Glist *) malloc(sizeof(Glist));
        glist->next = g->gArray[adj1].head;
        g->gArray[adj1].head = glist;
        glist->adj = adj2;
        Glist *glist2 = (Glist *) malloc(sizeof(Glist));
        glist2->next = g->gArray[adj2].head;
        g->gArray[adj2].head = glist2;
        glist2->adj = adj1;
    }

}

void printGraph(GTable *g) {
    printf("V:%d,EDGE:%d\n", g->point, g->edge);
    Glist* p;
    for (int i = 0; i < g->point; i++) {
        printf("%d:", g->gArray[i]);
        p = g->gArray[i].head;
        while(p!=NULL)
        {
            printf("%d ",p->adj);
            p = p->next;
        }
        printf("\n");
    }
}

void main() {
    GTable *g;
    g = (GTable*)malloc(sizeof(GTable));
    createGraph(g);
    printGraph(g);
}
