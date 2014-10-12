/*邻接矩阵的深度优先遍历*/

#include <stdio.h>
#include "graph.h"

int visited[100];

typedef struct {
    vertexType vexs[MAXVEX]; //顶点表
    edgeType edges[MAXVEX][MAXVEX]; //边表
    int numVex, numEdge; //顶点数和边数
}mGraph;

void DFS(mGraph g, int i)
{
    int j;

    /*设置该顶点为已访问过*/
    visited[i] = 1;
    printf("%d\n", g.vexs[i]);

    for (j = 0; j < g.numVex; j++) {
        /*如果i, j两点之间存在路径，并且j点未访问过*/
        if (g.edges[i][j] == 1 && !visited[j]) {
            DFS(g, j);
        }
    }
}

void DFSTraverse(mGraph g)
{
    int i;

    /*初始化所有顶点状态为未访问*/
    for (i = 0; i < g.numVex; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < g.numVex; i++) {
        if (!visited[i]) {
            DFS(g, i);
        }
    }
}
