/*
 *  Seat_UI.c
 *
 *  Created on: 2015年5月23日
 *  Author: lc
 */
#include "Seat_UI.h"

#include "../Service/Seat.h"
#include "../Service/Studio.h"
#include "../Service/EntityKey.h"
#include "../Common/List.h"
#include <stdio.h>

//根据状态返回对应表示状态符号
inline char Seat_UI_Status2Char(seat_status_t status) {

	// 请补充完整

	if(status==9)

		return '~';

	else if(status==1)

       		return '#';

	else

		return ' ';
}

//根据状态符号返回桌位状态
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	// 请补充完整

	if(statusChar == '#')

		return SEAT_GOOD;

	else if(statusChar == '~')

		return SEAT_BROKEN;

	else
       	return SEAT_NONE;

}

void Seat_UI_MgtEntry(int roomID) {
	// 请补充完整
	studio_t buf;
	seat_list_t list;
	List_Init (list, seat_node_t);
	int r, c;
	char choice;
	int rows, cols;
	if (Studio_Srv_FetchByID (roomID, &buf))
	{
		if (Seat_Srv_FetchByRoomID (list, roomID) ==0)
		{
			buf.seatsCount = Seat_Srv_RoomInit (list, roomID, buf.rowsCount, buf.colsCount);
			Studio_Srv_Modify (&buf);
		}
		do {
			printf ("====================================================================\n");
			printf ("  *********************Projection Seat List***********************\n");
			printf ("--------------------------------------------------------------------\n");
		seat_node_t *pos;
		pos = (list)->next;
		for(r = 1; r <= buf.rowsCount; r++)
		{
			for (c = 1; c <= buf.colsCount; c++)
			{	
				printf ("%c ", Seat_UI_Status2Char(pos->data.status));	
				pos = pos->next;
			}
			printf ("\n");
		}
		 	printf ("******************************************\n");
			printf ("[A]dd || [U]pdate || [D]elete || [R]eturn\n");
			printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf ("Your choice:");
			scanf ("%*c");
			scanf ("%c", &choice);
			scanf ("%*c");
			switch (choice)
			{
			case 'a':
			case 'A':
			Seat_UI_Add (list, roomID, buf.rowsCount, buf.colsCount);break;

			case 'd':
			case 'D':
				printf ("rows and cols:");
				scanf ("%d %d", &rows, &cols);
				Seat_UI_Delete (list, rows, cols);break;
			case 'u':
			case 'U':
				printf ("rows and cols:");
				scanf ("%d %d", &rows, &cols);
				Seat_UI_Modify (list, rows, cols);break;
			}
		} while (choice != 'r' && choice != 'R');
	}	
	List_Destroy (list, seat_node_t);
}

int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {  //输入一个座位
	// 请补充完整
	int newRecCount;
	char choice;
	newRecCount = 0;
	seat_node_t *newNode;
	seat_t data;
	do
	{	
		printf("Iput rowsCount < [%d],closCount < [%d]:", row, column);
		scanf("%d %d",&(data.row),&(data.column));
		while (data.row > row && data.column > column)
		{
			printf("Iput rowsCount < [%d],closCount < [%d]:", row, column);
		    scanf("%d %d",&(data.row),&(data.column));
		}
		while (Seat_Srv_FindByRowCol (list,  data.row, data.column) != NULL)
		{
			printf ("Seat has existed!");
			printf("Iput rowsCount < [%d],closCount < [%d]:", row, column);
			scanf ("%d %d", &(data.row), &(data.column));
		}
		data.id = EntKey_Srv_CompNewKey ("Seat");
		data.roomID = roomID;
	    data.status = 0;
	    if (Seat_Srv_Add(&data))
	    {
			newRecCount++;
			newNode = (seat_node_t *) malloc (sizeof (seat_node_t));
			newNode->data = data;
			List_AddTail (list, newNode);
    		printf("Succeed!");
	    }
	    else
			printf("failure!");
		printf ("[A]dd?");
		scanf ("%*c");
		scanf ("%c", &choice);
		scanf ("%*c");
	}while (choice == 'a' || choice == 'A');
	return newRecCount;
}

int Seat_UI_Modify(seat_list_t list, int row, int column) {

	seat_node_t *buf;
	char sta;
	int count = 0;
	buf = Seat_Srv_FindByRowCol (list, row, column);
	if (buf != NULL)
	{	
		sta = Seat_UI_Status2Char (buf->data.status);
		
		printf ("Status of Seat: %c\n",sta );
		printf ("Change:0/1/9:");
		scanf ("%d", &buf->data.status);
		if (Seat_Srv_Modify (&(buf->data)))
		{
			printf ("Succeed!\n");
			count ++;
		}
		else
			printf ("Failed!\n");
	}
	else
	{
		printf ("None!\n");
	}
	return count;

}

int Seat_UI_Delete(seat_list_t list, int row, int column) {
       // 请补充完整
	seat_node_t *Node;
	int count = 0;
	Node = Seat_Srv_FindByRowCol (list, row, column);
	if (Node == NULL)
	{
		printf ("None!");
		return count;
	}
	else 
	{
		if (Seat_Srv_DeleteByID (Node->data.id))
		{
			printf ("Succeed!\n");
			count = 1;
			return count;
		}
		else
		{
			printf ("Failed!\n");
		}
	}
}		




