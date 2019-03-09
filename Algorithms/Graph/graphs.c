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

void addEdge(GTable *g, int adj1, int adj2) {
    Glist *glist = (Glist *) malloc(sizeof(Glist));
    glist->next = g->gArray[adj1].head;
    g->gArray[adj1].head = glist;
    glist->adj = adj2;
    Glist *glist2 = (Glist *) malloc(sizeof(Glist));
    glist2->next = g->gArray[adj2].head;
    g->gArray[adj2].head = glist2;
    glist2->adj = adj1;
}

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
        addEdge(g, adj1, adj2);
    }

}

int pointsSum(GTable *g) {
    return g->point;
}

void printGraph(GTable *g) {
    printf("V:%d,EDGE:%d\n", g->point, g->edge);
    Glist *p;
    for (int i = 0; i < g->point; i++) {
        printf("%d:", g->gArray[i]);
        p = g->gArray[i].head;
        while (p != NULL) {
            printf("%d ", p->adj);
            p = p->next;
        }
        printf("\n");
    }
}

int *adj(GTable *g, int v, int *degree) {
    int *adjs;
    adjs = (int *) malloc(MAX * sizeof(int));
    Glist *p;
    p = g->gArray[v].head;
    int count = 0;
    while (p != NULL) {
        adjs[count] = p->adj;
        p = p->next;
        count++;
    }
    *degree = count;
    adjs = (int *) realloc(adjs, (count + 1) * sizeof(int));
    return adjs;
}


void dfs(GTable *g, int v, int* marked) {
    marked[v] = 1;
    printf("%d->", v);
    int degree;
    int* count;
    count = adj(g, v, &degree);
    for(int i=0; i<degree;i++)
    {
        if(!marked[count[i]]) dfs(g, count[i], marked);
    }

}

void main() {
    GTable *g;
    g = (GTable *) malloc(sizeof(GTable));
    createGraph(g);
    printGraph(g);
    int marked[MAX] = {0};
    dfs(g, 0, marked);
    for(int i=0; i<MAX;i++)
    {
        printf("%d,", marked[i]);
    }

}
