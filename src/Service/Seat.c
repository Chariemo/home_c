/*
 *  Seat.c
 *
 *  Created on: 2015��6��12��
 *  Author: lc
 */
#include <stdlib.h>
#include "../Common/List.h"
#include "Seat.h"
#include "../Persistence/Seat_Persist.h"
#include "EntityKey.h"

inline int Seat_Srv_Add(const seat_t *data){
	// �벹������
	return Seat_Perst_Insert(data);


}

inline int Seat_Srv_AddBatch(seat_list_t list){
	// �벹������
	return Seat_Perst_InsertBatch(list);

} 


inline int Seat_Srv_Modify(const seat_t *data){
	// �벹������
	return Seat_Perst_Update(data);

}

inline int Seat_Srv_DeleteByID(int ID){
	// �벹������
	return Seat_Perst_DeleteByID (ID);
}

inline int Seat_Srv_FetchByID(int ID, seat_t *buf){
	// �벹������
	return Seat_Perst_SelectByID(ID,buf);
}


inline int Seat_Srv_DeleteAllByRoomID(int roomID){

	return Seat_Perst_DeleteAllByRoomID(roomID);

	// �벹������
}


//�����ݳ���ID������λ
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID){
       // �벹������
	int SeatCount;
	SeatCount = Seat_Perst_SelectByRoomID (list, roomID);
	if (SeatCount != 0)
	Seat_Srv_SortSeatList (list);
    return SeatCount;
}

/*���ݷ�ӳ��ID��ȡ��Ч����λ*/
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


//�����С�������ʼ���ݳ�������λ
int Seat_Srv_RoomInit(seat_list_t list, int roomID, int rowsCount,
		int colsCount) {
		
	// �벹������
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

//����λ����list���а���λ�кź��к�����
void Seat_Srv_SortSeatList(seat_list_t list) {
       // �벹������
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

//�����node���뵽����������list��
void Seat_Srv_AddToSoftedList(seat_list_t list, seat_node_t *node) {
       // �벹������
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
       // �벹������
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
       // �벹������
	seat_node_t *p;
	p = (list)->next;
	while (p != list)
	{
		if (p->data.id == seatID)
			return p;
	}
    return NULL;
}
