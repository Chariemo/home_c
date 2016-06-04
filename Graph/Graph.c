#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	MGraph G;
	CreateDG (&G);
	int dist[MAX];
	int path[MAX][MAX] = {0};
	Dijkstra (G, 0, dist, path);
	return 0;
	int i, j;
	for (i = 0; i < G.vernum; i++)
	{
		if (i != 0)
		{
			printf ("%c", G.vertex[0]);
			for (j = 1; path[i][j]; j++)
				printf ("->%c", G.vertex[path[i][j]]);
			printf ("->%c\n", G.vertex[i]);
			printf ("distance: %d\n", dist[i]); 
		}
	}
}

void CreateDG (MGraph *G)
{
	G->kind = DG;

	int i, j, k, cost;
	VertexData v1, v2;
	printf ("Enter vernum and arcnum:(<%d): ", MAX);
	scanf ("%d %d", &(G->vernum), &(G->arcnum));
	getchar ();
	printf ("Enter the vertex: ");
	for (i = 0; i < G->vernum; i++)
		scanf ("%c", &(G->vertex[i]));
	for (i = 0; i < G->vernum; i++)
		for (j = 0; j < G->vernum; j++)
			G->arcs[i][j] = INFINITY;
	for (k = 0; k < G->arcnum; k++)
	{
		printf ("Enter v1 v2 and cost: ");
		getchar ();
		scanf ("%c %c %d", &v1, &v2, &cost);
		i = Locate (G, v1);
		j = Locate (G, v2);
		G->arcs[i][j] = cost;	
	}
}

int Locate (MGraph *G, VertexData v)
{
	int i;
	for (i = 0; i < G->vernum; i++)
		if (G->vertex[i] == v)
			return i;
	printf ("UnKnowed Vertex %c!", v);
	exit (0);
}

void Print (MGraph G)
{
	int i, j; 
	for (i = 0; i < G.vernum; i++)
		printf ("\t%c", G.vertex[i]);
	for (i = 0; i < G.vernum; i++)
	{
		printf ("\n%c\t", G.vertex[i]);
		for (j = 0; j < G.vernum; j++)
			printf ("%d\t", G.arcs[i][j]);
		printf ("\n");
	}
}

void DegreeDG (MGraph G, int *od, int *id)
{
	int i, j;
	for (i = 0; i < G.vernum; i++)
		id[i] = od[i] = 0;
	
	for (i = 0; i < G.vernum; i++)
		for (j = 0; j < G.vernum; j++)
			if (G.arcs[i][j] != INFINITY)
				od[i]++;
	for (i = 0; i < G.vernum; i++)
		for (j = 0; j < G.vernum; j++)
			if (G.arcs[j][i] != INFINITY)
				id[i]++;	
}

bool isExist (MGraph G, VertexData v1, VertexData v2)
{
	int i, j;
	i = Locate (&G, v1);
	j = Locate (&G, v2);
	if (G.arcs[i][j] == INFINITY)
		return false;
	else
		return true;
}

void TraverseDFS (MGraph G)
{
	int i;
	for (i = 0; i < G.vernum; i++)
		visited[i] = 0;
	for (i = 0; i < G.vernum; i++)
		if (!visited[i])
			DFS (G, i);
}

void DFS (MGraph G, int vi)
{
	int vj;
	printf ("%c ", G.vertex[vi]);
	visited[vi] = 1;
	vj = 0;
	while (vj < G.vernum)
	{
		if (!visited[vj] && G.arcs[vi][vj] != INFINITY)
			DFS(G, vj);
		vj++;
	}
}

void TraverseBFS (MGraph G)
{
	int i;
	for (i = 0; i < G.vernum; i++)
		visited[i] = 0;
	for (i = 0; i < G.vernum; i++)
		if (!visited[i])
			BFS(G, i);
}

void BFS (MGraph G, int vi)
{
	Queue *q;
	Init_Queue (&q);
	int v, i;
	printf ("%c ", G.vertex[vi]);
	In_Queue (q, vi);
	visited[vi] = 1;
	while (!IsEmpty_Queue (q))
	{
		Out_Queue (q, &v);
		i = 0;
		while (i < G.vernum)
		{
			if (!visited[i] && G.arcs[v][i] != INFINITY)
			{
   				printf ("%c ", G.vertex[i]);
				visited[i] = 1;
				In_Queue (q, i);
			}
			i++;
		}
	}
}



void CreateDG_A (ALGraph *G)
{
	int i, j, k;
	VertexData v1, v2;
	ArcNode *s, *p;
	printf ("vernum & arcnum: ");
	scanf ("%d %d", &(G->vernum), &(G->arcnum));
	getchar ();
	printf ("Enter vertex: ");
	for (i = 0; i < G->vernum; i++)
	{
		scanf ("%c", &(G->vertex[i].data));
		G->vertex[i].firstArc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)
	{
		printf ("v1 and v2: ");
		getchar ();
		scanf ("%c %c", &v1, &v2);
		i = Locate_A (G, v1);
		j = Locate_A (G, v2);
		s = (ArcNode *) malloc (sizeof (ArcNode));
		s->adj = j;
		s->nextArc = NULL;
		p = G->vertex[i].firstArc;
		if (p == NULL)
			G->vertex[i].firstArc = s;
		else 
		{
			while (p->nextArc)
				p = p->nextArc;
			p->nextArc = s;
		}
	}
}

int Locate_A (ALGraph *G, VertexData v)
{
	int i;
	for (i = 0; i < G->vernum; i++)
		if (G->vertex[i].data == v)
			return i;
	printf ("UnKnowed Vertex %c!", v);
	exit (0);
		
}

void Print_A (ALGraph G)
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vernum; i++)
	{
		printf ("\n%d%c\t", i, G.vertex[i].data);
		p = G.vertex[i].firstArc;
		while (p)
		{
			printf ("%d\t", p->adj);
			p = p->nextArc;
		}
	}
	printf ("\n");
}

void Degree_A (ALGraph G, int *od, int *id)
{
	int i, j;
	ArcNode *p;
	for (i = 0; i < G.vernum; i++)
	{
		id[i] = 0;
		od[i] = 0;
	}
	for (i = 0; i < G.vernum; i++)
	{
		p = G.vertex[i].firstArc;
		while (p)
		{
			od[i]++;
			j = p->adj;
			id[j]++;
			p = p->nextArc;
		}	
	}
}

bool isExist_A (ALGraph G, VertexData v1, VertexData v2)
{
	int i, j;
	ArcNode *p;
	i = Locate_A (&G, v1);
	j = Locate_A (&G, v2);	
	p = G.vertex[i].firstArc;
	while (p && p->adj != j)
		p = p->nextArc;
	if (p == NULL)
		return false;
	else
		return true;
}

void TraverseDFS_A (ALGraph G)
{
	int i;
	for (i = 0; i < G.vernum; i++)
		visited[i] = 0;
	for (i = 0; i < G.vernum; i++)
		if (!visited[i])
			DFS_A (G, i);
}

void DFS_A (ALGraph G, int vi)
{
	ArcNode *p;
	printf ("%c ", G.vertex[vi].data);
	visited[vi] = 1;
	p = G.vertex[vi].firstArc;
	while (p)
	{
		if (!visited[p->adj])
			DFS_A (G, p->adj);
		p = p->nextArc;
	} 
}	

void TraverseBFS_A (ALGraph G)
{
	int i;
	for (i = 0; i < G.vernum; i++)
		visited[i] = 0;
	for (i = 0; i < G.vernum; i++)
		if (!visited[i])
			BFS_A (G, i);
}

void BFS_A (ALGraph G, int vi)
{
	Queue *q;
	Init_Queue (&q);
	ArcNode *p;
	int v;
	printf ("%c ", G.vertex[vi].data);
	In_Queue (q, vi);
	visited[vi] = 1;
	while (!IsEmpty_Queue (q))
	{
		Out_Queue (q, &v);
		p = G.vertex[v].firstArc;
		while (p)
		{
			if (!visited[p->adj])
			{
				printf ("%c ", G.vertex[p->adj].data);
				visited[p->adj] = 1;
				In_Queue (q, p->adj);
			}
			p = p->nextArc;
		}
	}
}

void GraphMtoAL (MGraph MG, ALGraph *ALG)
{
	int i, j;
	ArcNode *p, *s;
	ALG->vernum = MG.vernum;
	ALG->arcnum = MG.arcnum;
	for (i = 0; i < MG.vernum; i++)
	{
		ALG->vertex[i].data = MG.vertex[i];
		ALG->vertex[i].firstArc = NULL;
	}
	for (i = 0; i < MG.vernum; i++)
		for (j = 0; j < MG.vernum; j++)
			if (MG.arcs[i][j] != 0)
			{
				s = (ArcNode *) malloc (sizeof (ArcNode));
				s->nextArc = NULL;
				s->adj = j;
				p = ALG->vertex[i].firstArc;
				if (p == NULL)
					ALG->vertex[i].firstArc = s;
				else 
				{
					while (p->nextArc)
						p = p->nextArc;
					p->nextArc = s;
				}
			}
}


void GraphALtoM (ALGraph ALG, MGraph *MG)
{
	int i, j;
	ArcNode *p;
	MG->vernum = ALG.vernum;	
	MG->arcnum = ALG.arcnum;
	for (i = 0; i < MG->vernum; i++)
		for (j = 0; j < MG->vernum; j++)
			MG->arcs[i][j] = 0;
	for (i = 0; i < ALG.vernum; i++)
	{
		MG->vertex[i] = ALG.vertex[i].data;
		for (p = ALG.vertex[i].firstArc; p != NULL; p = p->nextArc)
		{
			MG->arcs[i][p->adj] = 1;		
		}
	}
}
int visited1[MAX] = {0};
void PathAll (ALGraph G, int u, int v, int path[], int len)
{
	int w;
	ArcNode *p;
	if (u == v)
	{
		for (w = 0; w < len; w++)
			printf ("%c ", G.vertex[path[w]].data);
		printf ("\n");
	}
	else
	{
		for (p = G.vertex[u].firstArc; p; p = p->nextArc)
		{
			if (!visited1[p->adj] && p->adj != path[0])
			{
				visited1[p->adj] = 1;
				path[len] = p->adj;
				PathAll (G, p->adj, v, path, len+1);
				visited1[p->adj] = 0;
			}
		}
		
	}
}


void Prim (MGraph G, int start)
{
	struct
	{
		int adj;
		int lowcost;
	}closeedge[MAX];
	int i, e, k, m, min;
	closeedge[start].lowcost = 0;
	for (i = 0; i < G.vernum; i++)
		if (i != start)
		{
			closeedge[i].adj = start;
			closeedge[i].lowcost = G.arcs[start][i];
		}
	for (e = 0; e < G.vernum-1; e++)
	{
		min = INFINITY;
		for (k = 0; k < G.vernum; k++)
		{
			if (closeedge[k].lowcost != 0 && closeedge[k].lowcost < min)
			{
				m = k;
				min = closeedge[k].lowcost;
			}
		}
		closeedge[m].lowcost = 0;
	for (i = 0; i < G.vernum; i++)
		if (i != m && G.arcs[m][i] < closeedge[i].lowcost)
		{
			closeedge[i].lowcost = G.arcs[m][i];
			closeedge[i].adj = G.arcs[m][i];
		}
	}
}

int TopoSort (ALGraph G)
{
	Queue *q;
	int indegree[MAX], outdegree[MAX];
	int i, count, k;
	ArcNode *p;
	Degree_A (G, outdegree, indegree);
	Init_Queue (&q);
	for (i = 0; i < G.vernum; i++)
		if (indegree[i] == 0)
			In_Queue (q, i);
	count = 0;
	while (!IsEmpty_Queue (q))
	{
		Out_Queue (q, &i);
		printf ("%c ", G.vertex[i].data);
		count++;
		p = G.vertex[i].firstArc;
		while (p)
		{	
			k = p->adj;
			indegree[k]--;
			if (indegree [k] == 0)
				In_Queue (q, k);
			p = p->nextArc;
		}
	}
	if (count < G.vernum)
		return 0;
	else 
		return 1;
}

int CriticalPath (ALGraph G)
{
	ArcNode *p;
	int i, j, k, a, ei, li, flag = 0;
	int vl[MAX];
	
}

void Dijkstra (MGraph G, int start, int dist[],  int path[][MAX]){
	int mindist, i, j, k, t = 1;
	for (i = 0; i < G.vernum; i++)
	{
		dist[i] = G.arcs[start][i];
		if (G.arcs[start][i] != INFINITY)
			path[i][1] = start;
	}
	path[start][0] = 1;
	for (i = 1; i < G.vernum; i++)
	{
		mindist = INFINITY;
		for (j = 0; j < G.vernum; j++)
			if (!path[j][0] && dist[j] < mindist)
			{
				k = j;
				mindist = dist[j];
			}
		if (mindist == INFINITY)
			return;
		path[k][0] = 1;
		for (j = 0; j < G.vernum; j++)
		{
			if (!path[j][0] && dist[k]+G.arcs[k][j] < dist[j])
 			{
				dist[j] = dist[k] + G.arcs[k][j];
				t = 1;
				while (path[k][t] != 0)
				{
					path[j][t] = path[k][t];
					t++;
				}
			path[j][t] = k;
			path[j][t+1] = 0;
			}
		}
	}
	
}

void Floyd (MGraph G, int F[][MAX])
{
	int path[MAX][MAX];
	int i, j, k;
	for (i = 0; i < G.vernum; i++)
		for (j = 0; j < G.vernum; j++)
		{
			F[i][j] = G.arcs[i][j];
			path[i][j] = INFINITY;
		}
	for (i = 0; i < G.vernum; i++)
		for (j = 0; j < G.vernum; j++)
			for (k = 0; k < G.vernum; k++)
				if (F[i][j] > F[i][k] + F[k][j])
				{
					F[i][j] = F[i][k] + F[k][j];
					path[i][j] = k;				
				}
}
