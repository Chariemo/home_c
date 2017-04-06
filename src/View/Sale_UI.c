#include "Play_UI.h"
#include "Schedule_UI.h"
#include "Sale_UI.h"
#include "Ticket_UI.h"
#include "../Service/Ticket.h"
#include "../Service/Seat.h"
#include "../Service/Studio.h"
#include "../Service/EntityKey.h"
#include "../Service/Sale.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//引用登陆用户的全局数据结构
extern account_t gl_CurUser;

//根据计划ID，显示演出票
void Sale_UI_ShowTicket(int schID){
	// 请补充完整
}

inline int Sale_UI_SellTicket(ticket_list_t tickList, seat_list_t seatList){
	// 请补充完整
     	int row,col;

	printf("please input rows and cols:\n");

	scanf("%d %d",&row,&col);

	ticket_t tbuf;

	sale_t *abuf;

	seat_node_t *sbuf;

	if((sbuf = Seat_Srv_FindByRowCol(seatList,row,col)) != NULL){

		if(Ticket_Srv_FetchByID(sbuf->data.id,&tbuf)){

			if(tbuf.status!=1){

				Ticket_Srv_Modify(&tbuf);

				Sale_Srv_Add(abuf);

			}

			else{

				return 0;

			}

		}

		else{

			printf("do not ticket!\n");

			return 0;

		}

	}

	return 1;
}



//根据剧目ID显示演出计划
void Sale_UI_ShowScheduler(int playID) {
	// 请补充完整
	char choice;

	ticket_node_t *ptr;

	List_Init(ptr,ticket_node_t);

	play_node_t *buf;

	schedule_list_t head;

	schedule_node_t *pos;

	List_Init(pos,schedule_node_t);

	Play_Srv_FetchByID(playID,&(buf->data));

	List_Init(buf,play_node_t);

	Schedule_Srv_FetchByPlay(pos,pos->data.play_id);



	Pagination_t paging;



	List_Init(head, schedule_node_t);

	paging.offset = 0;

	paging.pageSize = SCHEDULE_PAGE_SIZE;



	paging.totalRecords = Schedule_Srv_FetchAll(head);

	Paging_Locate_FirstPage(head, paging);

	

	do{

		printf("\n==================================================================\n");

		printf("------- Total Records:%2d ----------------------- Page %2d/%2d ----\n",

				paging.totalRecords, Pageing_CurPage(paging),

				Pageing_TotalPages(paging));

		printf("******************************************************************\n");

		printf("[P]revPage|[N]extPage | [T]icket | [R]eturn");

		printf("\n==================================================================\n");



	printf("please input your choice:");

	scanf("%*c");

	scanf("%c",&choice);

	scanf("%*c");

	switch(choice){

	case 't':

	case 'T':

		Seat_UI_ShowTicket(ptr->data.schedule_id);

		break;

	case 'P':

	case 'p':

		if (!Pageing_IsFirstPage(paging)) {

				Paging_Locate_OffsetPage(head, paging, -1, schedule_node_t);

			}

			break;



	case 'n':

	case 'N':

		if (!Pageing_IsLastPage(paging)) {

				Paging_Locate_OffsetPage(head, paging, 1, schedule_node_t);

			}

			break;



	}

	}while(choice!= 'r' && choice!= 'R');

	List_Destroy(head,schedule_node_t);
}


void Sale_UI_MgtEntry() {
	// 请补充完整
}

//退票
void Sale_UI_ReturnTicket(){
	// 请补充完整
	int ID;

	ticket_t tbuf;

	ticket_node_t *buf;

	sale_t *abuf;

	List_Init(buf,ticket_node_t);

	printf("please input TicketID:\n");

	scanf("%d",&ID);

	if(Ticket_Srv_FetchByID(ID,&(buf->data))){

		if(buf->data.status!=1){

			exit (1);

		}

		else{

			Ticket_Srv_Modify(&(buf->data));

			Sale_Srv_Add(abuf);

		}

	}

	else{

		printf("do not ticket!\n");

		exit (0);

	}
}
