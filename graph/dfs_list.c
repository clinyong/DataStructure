/*邻接表的深度遍历*/

#include <stdio.h>
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

int visited[100];

void DFS(lGragh l, int i)
{
    edgeNode *p;

    visited[i] = 1;
    printf("%d\n", l.list[i].data);

    p = l.list[i].firstEdge;

    while (p) {
        if (!visited[p->adjvex]) {
            DFS(l, p->adjvex);
        }

        p = p->next;
    }
}

void DFSTraverse(lGragh l)
{
    int i;

    for (i = 0; i < l.numVex; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < l.numVex; i++) {
        if (!visited[i]) {
            DFS(l, i);
        }
    }
}
