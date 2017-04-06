#include "Ticket.h"
#include "EntityKey.h"

#include "../Common/List.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Persistence/Ticket_Persist.h"
#include "../Persistence/Play_Persist.h"
#include "../Persistence/Schedule_Persist.h"
#include "../Service/Seat.h"

#include <stdio.h>
#include <stdlib.h>

int Ticket_Srv_AddBatch(int schedule_id, int studio_id){
	// �벹������
	seat_list_t seat_list;
	List_Init (seat_list, seat_node_t);
	int count;
	count = Seat_Srv_FetchByRoomID (seat_list, studio_id);
	if (count != 0)
	{
		ticket_list_t ticket_list;
		List_Init (ticket_list, ticket_node_t);
		ticket_t buf;
		seat_node_t *pos;
		ticket_node_t *newNode;
		pos = (seat_list)->next;
		while (pos != seat_list)
		{
			buf.id = EntKey_Srv_CompNewKey ("Ticket");
			buf.schedule_id = schedule_id;
			buf.seat_id = pos->data.id;
			if ((newNode = (ticket_node_t *) malloc (sizeof (ticket_node_t))) == NULL)
			{
				printf ("Cannot load memory!\n");
				exit (1);
			}
			newNode->data = buf;
			List_AddTail (ticket_list, newNode);
			pos = pos->next;
		}
		if (Ticket_Perst_Insert (ticket_list))
			return count;
		return 0;
	}	
		
}

int Ticket_Srv_DeleteBatch(int schedule_id) {
	// �벹������
	return Ticket_Perst_Delete (schedule_id);
}

int Ticket_Srv_Modify(const ticket_t * data){
	// �벹������
       return 1;
}

int Ticket_Srv_FetchByID(int ID, ticket_t *buf) {
	// �벹������
       return 1;
}


//������λID��list���Ҷ�ӦƱ
inline ticket_node_t * Ticket_Srv_FindBySeatID(ticket_list_t list, int seat_id){
	// �벹������
       return NULL;
}


//���ݼƻ�ID��ȡ�����ݳ�Ʊ
int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id) {

       // �벹������
       return 1;
}

//�����ݳ��ƻ�ID��ͳ�������ʼ�Ʊ��������Ʊ������
int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount, int *totalCount){
	// �벹������
       return 1;
}


