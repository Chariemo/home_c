/*简单列表类型的头文件*/
#include <stdbool.h>
#define TSIZE 45
typedef struct file {
	char title[TSIZE];
	int rating;
}Item;

typedef struct node {
	Item item;
	struct node * next;
}Node, * List;

void InitializeList (List * plist); // 初始化列表
bool ListIsEmpty (const List  plist); //确定列表是否为空列表
bool ListIsFull (const List  plist); //确定列表是否已满
unsigned int ListItemCount (const List  plist); //确定列表中项目的个数
bool AddItem (Item item, List * plist); //在列表尾部添加一个项目
void Traverse (const List  plist, void (*pfun) (Item item)); /*把一个函数作用
于列表中的每个项目*/
void EmptyTheList (List * plist);

