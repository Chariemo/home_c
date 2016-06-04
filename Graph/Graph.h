#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdbool.h>
#define MAX 20
#define INFINITY 32767
typedef int DataType;
typedef struct
{
	DataType data[MAX];
	int rear, front;
}Queue;


typedef enum {DG, DN, UDG, UDN}	GraphKind;
typedef char VertexData;
int visited[MAX];
typedef struct
{
	VertexData vertex[MAX];
	int arcs[MAX][MAX];
	int vernum;
	int arcnum;
	GraphKind kind;
}MGraph;


typedef struct ArcNode 
{
	int adj;
	struct ArcNode * nextArc;
	
}ArcNode;
typedef struct VertexNode
{
	VertexData data;
	struct ArcNode *firstArc;
}VertexNode;
typedef struct 
{	
	VertexNode vertex[MAX];
	int vernum;
	int arcnum;
	GraphKind kind;
}ALGraph;


void CreateDG (MGraph *G);

int Locate (MGraph *G, VertexData v);

void Print (MGraph G);

void DegreeDG (MGraph G, int *od, int *id);

bool isExist (MGraph G, VertexData v1, VertexData v2);

void DFS (MGraph G, int vi);

void TraverseDFS (MGraph G);

void BFS (MGraph G, int vi);

void TraverseBFS (MGraph G);



void CreateDG_A (ALGraph *G);

int Locate_A (ALGraph *G, VertexData v);

void Print_A (ALGraph G);

void Degree_A (ALGraph G, int *od, int *id);

bool isExist_A (ALGraph G, VertexData v1, VertexData v2);

void TraverseDFS_A (ALGraph G);

void DFS_A (ALGraph G, int vi);

void TraverseBFS_A (ALGraph G);

void BFS_A (ALGraph G, int vi);



void Init_Queue (Queue **q);

bool IsEmpty_Queue (Queue *q);

bool IsFull_Queue (Queue *q);

void In_Queue (Queue *q, DataType x);

void Out_Queue (Queue *q, DataType *x);




void GraphMtoAL (MGraph MG, ALGraph *ALG);
void GraphALtoM (ALGraph ALG, MGraph *MG);
void PathAll (ALGraph G, int u, int v, int path[], int len);
void Prim (MGraph G, int start);
int TopoSort (ALGraph G);
int CriticalPath (ALGraph G);
void Dijkstra (MGraph G, int start, int dist[], int path[][MAX]);
void Floyd (MGraph G, int F[][MAX]);


#endif
