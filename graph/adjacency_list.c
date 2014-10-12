/*邻接表*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/*边表结点*/
typedef struct edgeNode {
    int adjvex; /*顶点对应下标*/
    edgeType weight;
    struct edgeNode *next;
}edgeNode;

/*顶点表结点*/
typedef struct vertexNode {
    vertexType data; /*结点信息*/
    edgeNode *firstEdge; /*边表头指针*/
}vertexNode, adjList[MAXVEX];

typedef struct {
    adjList list;
    int numVex;
    int numEdge;
}lGragh;

void createListGraph(lGragh *g)
{
    int i, j, k;
    edgeNode *node;

    printf("请输入顶点数：");
    scanf("%d", &g->numVex);
    printf("请输入边数：");
    scanf("%d", &g->numEdge);

    /*初始化邻接表*/
    printf("请输入各个顶点的值:\n");
    for (i = 0; i < g->numVex; i++) {
        scanf("%d", &g->list[i].data);
        g->list[i].firstEdge = NULL;
    }

    /*建立边表*/
    for (k = 0; k < g->numEdge; k++) {
        printf("输入存在边的两点的下标：");
        scanf("%d, %d", &i, &j);

        /*无向图，值对称*/
        node = (edgeNode *)malloc(sizeof(edgeNode));
        node->adjvex = j;
        node->next = NULL;
        g->list[i].firstEdge = node;

        node = (edgeNode *)malloc(sizeof(edgeNode));
        node->adjvex = i;
        node->next = NULL;
        g->list[j].firstEdge = node;
    }
}
