/*
 *  Seat.c
 *
 *  Created on: 2015年6月12日
 *  Author: lc
 */
#include <stdlib.h>
#include "../Common/List.h"
#include "Seat.h"
#include "../Persistence/Seat_Persist.h"
#include "EntityKey.h"

inline int Seat_Srv_Add(const seat_t *data){
	// 请补充完整
	return Seat_Perst_Insert(data);


}

inline int Seat_Srv_AddBatch(seat_list_t list){
	// 请补充完整
	return Seat_Perst_InsertBatch(list);

} 


inline int Seat_Srv_Modify(const seat_t *data){
	// 请补充完整
	return Seat_Perst_Update(data);

}

inline int Seat_Srv_DeleteByID(int ID){
	// 请补充完整
	return Seat_Perst_DeleteByID (ID);
}

inline int Seat_Srv_FetchByID(int ID, seat_t *buf){
	// 请补充完整
	return Seat_Perst_SelectByID(ID,buf);
}


inline int Seat_Srv_DeleteAllByRoomID(int roomID){

	return Seat_Perst_DeleteAllByRoomID(roomID);

	// 请补充完整
}


//根据演出厅ID载入座位
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID){
       // 请补充完整
	int SeatCount;
	SeatCount = Seat_Perst_SelectByRoomID (list, roomID);
	if (SeatCount != 0)
	Seat_Srv_SortSeatList (list);
    return SeatCount;
}

/*根据放映厅ID提取有效的座位*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID)
{

	seat_node_t *ptr=list->next;
	seat_node_t *normal;
	seat_list_t tlist;
	List_Init (list, seat_node_t);
	int count;
	count = Seat_Perst_SelectByRoomID(list,roomID);

	while(ptr!=list)
	{
		if(ptr->data.status!=9)
		{
			if ((normal = (seat_node_t *) malloc (sizeof (seat_node_t))) != NULL)
			{
				normal->data = ptr->data;
				List_AddTail (tlist, normal);
				count--;
			}	
		}
		ptr = ptr->next;
	}	
	List_Free (list, seat_node_t);
	list = tlist;

	Seat_Srv_SortSeatList(list);
	return count;
}


//根据行、列数初始化演出厅的座位
int Seat_Srv_RoomInit(seat_list_t list, int roomID, int rowsCount,
		int colsCount) {
		
	// 请补充完整
	int seatID, num;
	seat_node_t *p;
	seatID = EntKey_Srv_CompNewKey("Seat");
	register int r, l;
	for (r = 1; r <= rowsCount; r++)
		for (l= 1; l <= colsCount; l++)
		{
			p = (seat_node_t *) malloc (sizeof (seat_node_t));
			p->data.row = r;
			p->data.column = l;
			p->data.roomID = roomID;
			p->data.id = seatID;
			p->data.status = 1;
			seatID = EntKey_Srv_CompNewKey ("Seat");
			List_AddTail (list, p);
		}
	num = Seat_Perst_InsertBatch (list);
    return num;
}

//对座位链表list进行按座位行号和列号排序
void Seat_Srv_SortSeatList(seat_list_t list) {
       // 请补充完整
	seat_node_t *listLeft, *p;
	if (!List_IsEmpty (list))
	{
	list->prev->next = NULL;
	listLeft = list->next;
	list->next = list->prev = list;
	while (listLeft != NULL)
	{
		p = listLeft;
		listLeft = listLeft->next;
		Seat_Srv_AddToSoftedList (list, p);
	}}
}

//将结点node加入到已排序链表list中
void Seat_Srv_AddToSoftedList(seat_list_t list, seat_node_t *node) {
       // 请补充完整
	seat_node_t *p;
	if (List_IsEmpty (list))
		List_AddTail (list, node);
	p = list->next;
	while (p != list)
	{
		if (p->data.row < node->data.row || (p->data.row == node->data.row && p->data.column < node->data.column))
			List_InsertBefore (p, node);
		p = p->next;
	}
	
}

inline seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row, int column) {
       // 请补充完整
	seat_node_t *ptr;
	ptr = (list)->next;
	while (ptr != list)
	{
		if (ptr->data.row == row && ptr->data.column == column)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
	
}

inline seat_node_t * Seat_Srv_FindByID(seat_list_t list, int seatID) {
       // 请补充完整
	seat_node_t *p;
	p = (list)->next;
	while (p != list)
	{
		if (p->data.id == seatID)
			return p;
	}
    return NULL;
}
