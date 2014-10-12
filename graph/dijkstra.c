/*迪杰斯特拉算法求最短路径*/

#include <stdio.h>
#include "graph.h"

typedef struct {
    vertexType vexs[MAXVEX]; //顶点表
    edgeType edges[MAXVEX][MAXVEX]; //边表
    int numVex, numEdge; //顶点数和边数
}mGraph;

/*s为路径源点下标*/
void dijkstra(mGraph g, vertexType s)
{
    int i, j, k, min;
    /*
     * path的值为前驱顶点下标，比如path[0]=1，表示点1到点0这段路径
     * weight的值为源点到该点的最短路径长度，比如weight[2]=4表示源点到点2的最短路径为4
     * final标志是否已找到最短路径，当值为1时表示已找到
     * */
    int path[MAXVEX];
    int weight[MAXVEX];
    int final[MAXVEX];

    /*初始化*/
    for (i = 0; i < g.numVex; i++) {
        weight[i] = g.edges[s][i];
        path[i] = s;
        final[i] = 0;
    }

    /*源点自身不必求最短路径*/
    final[s] = 1;

    for (i = 1; i < g.numVex; i++) {
        min = INFINITY;

        /*从第一个点开始，找出距离与当前点的最短路径。将找到的该点的下标保存到k*/
        for (j = 0; j < g.numVex; j++) {
            if (!final[j] && weight[j] < min) {
                k = j;
                min = weight[j];
            }
        }

        /*设置到k点已找到最短路径*/
        final[k] = 1;

        /*刷新最短路径数组weight*/
        for (j = 0; j <g.numVex; j++) {
            if (!final[j] && (min + g.edges[k][j] < weight[j])) {
                weight[j] = min + g.edges[k][j];
                path[j] = k;
            }
        }
    }
} 
