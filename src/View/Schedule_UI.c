#include "Schedule_UI.h"
#include "Play_UI.h"

#include "../Common/List.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"
#include "../Service/EntityKey.h"

#include <stdio.h>
#include <stdlib.h>

void Schedule_UI_ListAll(void) {
	// 请补充完整
}

int Schedule_UI_Add(int play_id) {
	// 请补充完整
	schedule_t rec;
	studio_t sbuf;
	int newRecCount = 0;
	char choice;	
	do 
	{
		printf ("========================================================================\n");
		printf ("*****************Add New Projection Schedule****************************\n");
		printf ("------------------------------------------------------------------------\n");
		rec.id = EntKey_Srv_CompNewKey ("Schedule");
		rec.play_id = play_id;
		printf ("Date:");
		scanf ("%d %d %d", &rec.date.year, &rec.date.month, &rec.date.day);
		printf ("Time:");
		scanf("%d %d %d",&rec.time.hour, &rec.time.minute, &rec.time.second);
		printf ("Studio_id:");
		scanf ("%d", &rec.studio_id);
		while (!(Studio_Srv_FetchByID (rec.studio_id, &sbuf)))
		{
			printf ("studio is nor exist!\n");
			printf ("new  studio_id:");
			scanf ("%d", &rec.studio_id);
		}
		rec.seat_count = sbuf.seatsCount;	
		if (Schedule_Srv_Add (&rec))
		{
			newRecCount += 1;
			printf ("The Schedule Add Successfully!\n");
		}	
		else
		{
			printf ("Add Failed!\n");
		}
		printf ("-------------------------------------------------------------------------\n");
		printf ("[A]dd more  [R]eturn:");
		scanf ("%*c");
		scanf ("%c", &choice);
		scanf ("%*c");
	} while (choice == 'a' || choice == 'A');
	return newRecCount;
}
int Schedule_UI_Modify(int id){
	// 请补充完整
	schedule_t data;
	play_t pbuf;
	studio_t sbuf;
	int rtn=0;

		if(Schedule_Srv_FetchByID (id,&data)==0){

		printf("Schedule is not exist!:");

		return 0;

	}
	

	else{

		printf("\n*************************************************************\n");

		printf("--------------------schedule informations-----------------------\n");

		printf ("schedule id: %d\n", data.id);

		printf("schedule_play_ID:%d\n",data.play_id);

		printf("schedule_studio_ID:%d\n",data.studio_id);

		printf("play date:%d-%d-%d\n",data.date.year,data.date.month,data.date.day);

		printf("play time:%d-%d-%d\n",data.time.hour,data.time.minute,data.time.second);

		printf("seat_count:%d\n",data.seat_count);

		printf("\n*************************************************************\n");

		printf("-----------------input new informations------------------------\n");


		printf ("new play_id:");
		scanf ("%d", &data.play_id);
		while (!(Play_Srv_FetchByID (data.play_id, &pbuf)))
		{
			printf ("Play is nor exist!\n");
			printf ("new play_id:");
			scanf ("%d", &data.play_id);
		}
		printf ("new  studio_id:");
		scanf ("%d", &data.studio_id);
		while (!(Studio_Srv_FetchByID (data.studio_id, &sbuf)))
		{
			printf ("studio is nor exist!\n");
			printf ("new  studio_id:");
			scanf ("%d", &data.studio_id);
		}
		data.seat_count = sbuf.seatsCount;	
		printf("new play date:year month day\n");

		scanf("%d %d %d",&data.date.year,&data.date.month,&data.date.day);

		printf("new play time:hour minute second\n");	

		scanf("%d %d %d",&data.time.hour,&data.time.minute,&data.time.second);
		
		}

	if(Schedule_Srv_Modify(&data)==1){

		rtn=1;

		printf("modify successfully!\n");
		if (Ticket_Srv_DeleteBatch (data.id))
			Ticket_Srv_AddBatch (data.id, data.studio_id);
		

	}

	else{

		printf("modify failed!\n");

	}

	return rtn;

       
}

int Schedule_UI_Delete(int id){

	// 请补充完整
	int rtn=0;

	if(Schedule_Srv_DeleteByID(id)){

		printf("delete schedule successful!\n");

		rtn=1;

	}

	else{

		printf("delete schedule not successful!\n");

	}

       return rtn;
}
int Schedule_UI_Query(int id){

	// 请补充完整
   /* int rtn=0;

	schedule_t buf;	

	if(Schsdule_Srv_FetchByID(id,&buf)){

		printf("query schedule information successful!\n");

		rtn=1;

	}

	else{

		printf("query schedule information not successful!\n");

	}

       return rtn;*/
}

/*以列表模式显示给定剧目的演出计划信息*/
void Schedule_UI_ListByPlay(const play_t *play, schedule_list_t list, Pagination_t paging){

	// 请补充完整
}

void Schedule_UI_MgtEntry(int play_id){
       // 请补充完整
	schedule_list_t list;

	List_Init (list,schedule_node_t);

	int count, i,id;

	char choice;

	schedule_t data;

	count = Schedule_Srv_FetchAll (list);

	do

	{

		schedule_node_t *pos;

		pos = (list)->next;
		printf (".......................................................................\n");
		printf ("##############################Schedule of Play List#########################\n");
		printf ("-----------------------------------------------------------------------\n");
		printf ("%5s  %5s  %5s  %12s  %12s     %5s\n","ID", "Play_id", "Studio_id", "Data", "Time", "Seat_count");

		for(i = 0; i<count; i++)

		{

			printf("%5d  %5d  %5d  \t\t%d-%d-%d \t%d:%d:%d  %5d\n",pos->data.id,pos->data.play_id,pos->data.studio_id,pos->data.date.year,pos->data.date.month,pos->data.date.day,pos->data.time.hour,pos->data.time.minute,pos->data.time.second,pos->data.seat_count);

			pos = pos->next;

		}

			printf("\n######################### Projection Schedule####################################\n");

			printf("\n[A]dd || [D]elete || [U]pdate ||[R]eturn");

			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		printf("You choice:");
		scanf ("%*c");
		scanf("%c",&choice);
		scanf ("%*c");

		
		switch (choice)

		{
			case 'a':

			case 'A':
				printf ("Id of Play(Schedule):");
				scanf ("%d",&id);

				if(Schedule_UI_Add(id))

					count = Schedule_Srv_FetchAll (list);

				break;

			case 'd':

			case 'D':

				printf("ID of Schedule:");

				scanf("%d",&id);

				if (Schedule_UI_Delete (id))

					count = Schedule_Srv_FetchAll (list);

				break;

			case 'u':

			case 'U':

				printf("ID of Schedule:");

				scanf("%d",&id);

				if (Schedule_UI_Modify (id))

					count = Schedule_Srv_FetchAll(list);

				break;

		}}while (choice != 'r' && choice != 'R');

		List_Destroy (list,schedule_node_t);

} 

