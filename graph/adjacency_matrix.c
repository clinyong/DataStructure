/*邻接矩阵*/
#include <stdio.h>
#include "graph.h"

typedef struct {
    vertexType vexs[MAXVEX]; //顶点表
    edgeType edges[MAXVEX][MAXVEX]; //边表
    int numVex, numEdge; //顶点数和边数
}mGraph;

void createMGraph(mGraph *g)
{
    int i, j, k;

    printf("请输入顶点数：");
    scanf("%d", &g->numVex);
    printf("请输入边数：");
    scanf("%d", &g->numEdge);

    printf("请输入各个顶点的值:\n");
    for (i = 0; i < g->numVex; i++) {
        scanf("%d", &g->vexs[i]);
    }

    /*初始化邻接矩阵*/
    for (i = 0; i < g->numVex; i++) {
        for (j = 0; i < g->numVex; j++) {
            g->edges[i][j] = INFINITY;
        }
    }

    /*建立邻接矩阵*/
    for (k = 0; k < g->numEdge; k++) {
        printf("输入存在边的两点的下标：");
        scanf("%d, %d", &i, &j);
        printf("输入边上的权值：");
        scanf("%d", &g->edges[i][j]);

        /*无向图，矩阵对称*/
        g->edges[j][i] = g->edges[i][j];
    }
    
}
