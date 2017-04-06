/*队列接口*/
#pragma c9x on
#include <stdbool.h>
typedef struct item {
	int gumption;
	int charisma;
}Item;

#define MAXQUEUE 10

typedef struct node {
	Item item;
	struct node *next;
}Node;

typedef struct queue {
	Node * front;
	Node * rear;
	int items;
}Queue;

void InitializeQueue (Queue *pq); //初始化队列
bool QueueIsFull (const Queue * pq);//检查队列是否已满
bool QueueIsEmpty (const Queue *pq);//检查队列是否为空
int QueueItemCount (const Queue * pq);//确定队列中项目的个数
bool EnQueue (Item item, Queue * pq);//向队列尾端添加项目
bool EdQueue (Item *pitem, Queue *pq);//从队列首端删除项目
void EmptyTheQueue (Queue * pq);//清空队列

