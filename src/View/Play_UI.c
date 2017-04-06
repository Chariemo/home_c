#include "Play_UI.h"
#include "Schedule_UI.h"

#include "../Common/List.h"
#include "../Service/Play.h"
#include "../Service/EntityKey.h"

#include <stdio.h>
#include <stdlib.h>

void Play_UI_ShowList(play_list_t list, Pagination_t paging) {

	// 请补充完整
}

void Play_UI_MgtEntry(int flag){
	// 请补充完整
	play_list_t list;
	List_Init (list, play_node_t);
	int count, i, id;
	char choice;
	play_t data;
	count = Play_Srv_FetchAll (list);
	do 
	{	play_node_t *pos;
		pos = (list)->next;
		printf ("------------------------------------------------------------------------------\n");
		printf ("********************************Play List*************************************\n");
		printf ("%s\t %10s\t %s\t %s\t %s\t%s \t%s\t %s\t%s\t\n", "ID", "NAME", "TYPE", "EARA", "RATING", "DURATION", "START_DATE", "END_DATE", "PRICE");
		for (i = 0; i < count; i++)
		{
			printf ("%d\t %10s\t %d\t %s\t %d\t  %d\t   \t%d-%d-%d\t %d-%d-%d\t %d\t\n", pos->data.id, pos->data.name, pos->data.type, pos->data.area, 
				pos->data.rating, pos->data.duration, pos->data.start_date.year,pos->data.start_date.month, pos->data.start_date.day, 							pos->data.end_date.year, pos->data.end_date.month, pos->data.end_date.day, pos->data.price);
			pos = pos->next;
		}
		if (flag == 0)
		{
			printf ("--------------------------------------------------------------------------\n");
			printf ("###############################Projection Play############################\n");
			printf ("[A]dd  ||  [D]elete  ||  [U]pdate  ||  [R]eturn  ||  [S]chedule");
			printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");		}
		else 
		{
			printf ("\n#######################################################################\n");
			printf ("                  [S]elect || [Q]uery  ||  [R]eturn");
			printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
		printf ("Your Choice:");
		scanf ("%*c");
		scanf ("%c", &choice);
		scanf ("%*c");
		switch (choice)
		{
			case 'S':
			case 's':
				printf ("ID of Play:");
				scanf ("%d", &id);
				if (Play_Perst_SelectByID (id,&data))
				{
				  	Schedule_UI_MgtEntry (id);break;
				}
				else
				{
					printf ("None!");break;
				}

			case 'q':
			case 'Q':
				printf ("ID of Play:");		
				scanf ("%d", &id);
		//		Play_UI_Query (id, &data);

			case 'a':
			case 'A':
				if (Play_UI_Add ())
					count = Play_Srv_FetchAll (list);
				break;
			
			case 'd':
			case 'D':
				printf ("ID of Play:");
				scanf ("%d", &id);	
				if (Play_UI_Delete (id))
					count = Play_Srv_FetchAll (list);
				break;

			case 'u':
			case 'U':
				printf ("ID of Play:");
				scanf ("%d", &id);
				if (Play_UI_Modify (id))
					count = Play_Srv_FetchAll (list);		
				break;
				
		}}while (choice != 'r' && choice != 'R');
		
		List_Destroy (list, play_node_t);
			
			
}



int Play_UI_Add(void)
{
       // 请补充完整
	play_t rec;
	int newRecCount = 0;
	char choice;
	do{
		printf("\n============================================================\n");
		printf("*********************  Add New Projection Play  *****************\n");
		printf("----------------------------------------------------------------\n");
		
		rec.id =  EntKey_Srv_CompNewKey ("Play");
		printf("Play Name:");
		scanf ("%s",rec.name);
		printf("Play Type(1:PLAY_TYPE_FIEL 2:PLAY_TYPE_OPEAR 3:PLAY_TYPE_CONCERT):");
		scanf("%d",&(rec.type));
		printf("Play Area:");
		scanf ("%s",rec.area);
		printf("Play rating(1:PLAY_RATE_CHILD 2:PLAY_RATE_TEENAGE 3:pLAY_RATE_ADULT):");
		scanf("%d",&(rec.rating));
		printf("Play duration");
		scanf("%d",&(rec.duration));
		printf("Play start_date");
		scanf("%d %d %d",&(rec.start_date.year),&(rec.start_date.month),&(rec.start_date.day));
		printf("Play end_date");
		scanf("%d %d %d",&(rec.end_date.year),&(rec.end_date.month),&(rec.end_date.day));
		printf("Play price:");
		scanf("%d",&(rec.price));
		printf("====================================================================\n");
			
		if(Play_Srv_Add(&rec)) {
				newRecCount +=1;
				printf("The new play added succissfully!\n");
		} else
			printf("The new play added failed!\n");
		printf("--------------------------------------------------------------------\n");
		printf("[A]dd more,[R]eturn:");
		scanf ("%*c");
		scanf("%c",&choice);
		scanf ("%*c");
	} while ('a' == choice || 'A' == choice);
	return newRecCount;
}

int Play_UI_Modify(int id){
	// 请补充完整
	play_t data;
	int rtn=0;
       	if(Play_Srv_FetchByID(id,&data)==0){
		printf("cannot insert play!");
		return 0;
	}
	else{
		printf("\n============================================================\n");
		printf("*************************play information*********************\n");
		printf("play ID:%d\n",data.id);
		printf("play name:%s\n",data.name);
		printf("play type:%d\n",data.type);
		printf("play area:%s\n",data.area);
		printf("play rating:%d\n",data.rating);
		printf("play duration:%d\n",data.duration);
		printf("play start data:%2d-%2d-%2d\n",data.start_date.year,data.start_date.month,data.start_date.day);	
		printf("play end data:%2d-%2d-%2d\n",data.end_date.year,data.end_date.month,data.end_date.day);
		printf("play price:%d\n",data.price);
		printf("\n==============================================================\n");
		printf("**********************input new information*************************\n");
		printf("new play name:\n");
		scanf("%s",data.name);
		printf("new play type:\n");
		scanf("%d",&(data.type));
		printf("new play area:\n");
		scanf("%s",data.area);
		printf("new play rating:\n");
		scanf("%d",&(data.rating));
		printf("new play duration:\n");
		scanf("%d",&(data.duration));
		printf("play start newdata\n");
		scanf("%d %d %d",&(data.start_date.year),&(data.start_date.month),&(data.start_date.day));
		printf("play end newdata\n");
		scanf("%d %d %d",&(data.end_date.year),&(data.end_date.month),&(data.end_date.day));
		printf("new play price\n");
		scanf("%d",&(data.price));
	}
	if(Play_Srv_Modify(&data)==1){
		rtn=1;
		printf("play information has been succeed modify!\n");
	}
	else{
		printf("play information hasnot been succeed modify!\n");
	}
	
	return rtn;

}

int Play_UI_Delete(int id){

       // 请补充完整
	int rtn = 0;
	if (Play_Srv_DeleteByID (id) ==1)
	{
		printf ("Succeed!\n");
		rtn = 1;
	}
	else
		printf ("Failed!\n");
	
   	return rtn;
}

/*int Play_UI_Query (int id, play_t *buf)
{
	int rtn = 0;
	if (Play_Srv_FetchByID (id, buf))
	{
		printf ("Fetch succeed!\n");
		rtn = 1;
		return rtn;
	}
	else
		printf ("Fetch Failed!\n");
	return rtn;
}*/
