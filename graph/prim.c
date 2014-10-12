/*prim算法生成最小生成树*/

#include <stdio.h>
#include "graph.h"

typedef struct {
    vertexType vexs[MAXVEX]; //顶点表
    edgeType edges[MAXVEX][MAXVEX]; //边表
    int numVex, numEdge; //顶点数和边数
}mGraph;

void prim(mGraph g)
{
   int mini, i, j, k;
   /**
    * adjvex表示哪段路径，比如adjvex[1] = 0，则表示0到1这段路径。
    * 当lowest里面的值为0时，表示已经加入到生成树。不为0时，结合adjvex数组，表示两点间的权值。
    * 比如像adjvex[1] = 0, lowest[1] = 65535，则表示点0到1的权值为65535
    * */
   int adjvex[MAXVEX];
   int lowest[MAXVEX]; 

   /*先把第一个元素加到生成树，然后用其它元素到第一个元素的距离初始化lowest数组*/
   for (i = 0; i < g.numVex; i++) {
       lowest[i] = g.edges[0][i];
       adjvex[i] = 0;
   }

   for (i = 1; i < g.numVex; i++) {
       mini = INFINITY;

       k = 0;
       for (j = 1; j < g.numVex; j++) {
           /*找出最短距离*/
           if (lowest[j] != 0 && lowest[j] < mini) {
               mini = lowest[j];
               k = j;
           }
       }

       /*打印出路径，并将下标为k的点设置为已加到生成树*/
       printf("(%d, %d)", adjvex[k], k);
       lowest[k] = 0;

       for (j = 1; j < g.numVex; j++) {
           /*如果该点未加到生成树，并且k点到该点的距离小于之前其它点到该点的距离，刷新lowest[j]*/
           if (lowest[j] != 0 && g.edges[k][j] < lowest[j]) {
               lowest[j] = g.edges[k][j];
               adjvex[j] = k;
           }
       }
   }


}
