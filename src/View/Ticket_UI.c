#include "Ticket_UI.h"

#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"

#include <stdio.h>
#include <stdlib.h>

//����״̬���ض�Ӧ��ʾ״̬����
inline char Ticket_UI_Status2Char(ticket_status_t status) {

	// �벹������
       return 'X';
}

void Ticket_UI_Print(int ID){
	// �벹������
}

//���ݼƻ�ID��ʾ����Ʊ
void Ticket_UI_ListBySch(const schedule_t *sch,	ticket_list_t tickList, seat_list_t seatList) {
	// �벹������
}

void ListTickets(void){
	// �벹������
}


int UpdateTicket(int id){
	// �벹������
       return 1;
}


int QueryTicket(int id){

	// �벹������
       return 1;
}
