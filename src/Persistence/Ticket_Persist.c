#include "Ticket_Persist.h"
//#include "../Persistence/Common_Persist.h"
#include "../Service/Ticket.h"
#include "../Service/Seat.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<unistd.h>

static const char TICKET_DATA_FILE[]="Ticket.dat";
static const char TICKET_DATA_TEMP_FILE[]="TicketTemp.dat";

int Ticket_Perst_Insert(ticket_list_t list){
	assert (list != NULL);
    FILE *fp;
    int count = 0;
    if ((fp = fopen (TICKET_DATA_FILE, "ab")) == NULL)
    {
        printf ("Cannot open file %s", TICKET_DATA_FILE);
        return 0;
    }
    ticket_node_t *node;
    node = (list)->next;
    ticket_t buf;
    buf = node->data;
    while (node != list)
    {
        if (fwrite (&buf, sizeof (ticket_t), 1, fp))
            count++;
        node = node->next;
        buf = node->data;
    }
	fclose (fp);
	return count;

}
int Ticket_Perst_Delete(int schedule_id){
	
	if(rename(TICKET_DATA_FILE, TICKET_DATA_TEMP_FILE)<0){
		printf("Cannot open file!");
		return 0;
	}
	
	FILE *fpSour, *fpTarg;
	fpSour = fopen(TICKET_DATA_TEMP_FILE,"rb");
	if(NULL == fpSour){
		printf("Cannot open file %s!", TICKET_DATA_TEMP_FILE);
		return 0;
	}
	
	fpTarg = fopen(TICKET_DATA_FILE,"wb");
	if(NULL == fpTarg){
		printf("Cannot open file %s!",TICKET_DATA_FILE);
		return 0;
	}

	ticket_t buf;
	
	int found = 0;
	while(!feof(fpSour)){
		if(fread(&buf, sizeof(ticket_t), 1, fpSour)){
			if(schedule_id != buf.schedule_id){
				fwrite(&buf, sizeof(ticket_t), 1, fpTarg);
			}
			else 
				found = 1;
		}
		}
	fclose(fpSour);
	fclose(fpTarg);
	
	remove(TICKET_DATA_TEMP_FILE);
	return found;
}

int Ticket_Perst_Update(const ticket_t * data) {
	assert(NULL != data);
	
	FILE *fp = fopen(TICKET_DATA_FILE,"rb");
	if(NULL == fp)
	{
		printf("Cannot open file %s!", TICKET_DATA_FILE);
		return 0;
	}
	ticket_t buf;
	
	int found = 0;
	
	while(!feof(fp)){
		if(fread(&buf, sizeof(ticket_t), 1, fp)){
			if(buf.id == data->id){
				fseek(fp, -sizeof(ticket_t), SEEK_CUR);
				fwrite(data, sizeof(ticket_t), 1, fp);
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	
	return found;
		
}


int Ticket_Perst_SelectByID(int ID, ticket_t *buf) {
	
       return 1;
}

int Ticket_Perst_SelectAll(ticket_list_t list) {
	
       return 1;
}


int Ticket_Perst_SelectBySchID(ticket_list_t list, int schedule_id) {
	
	ticket_node_t *newNode;
	ticket_t data;
	int recCount = 0;

	assert(NULL !=list);

	FILE *fp = fopen(TICKET_DATA_FILE,"rb");
	if(NULL == fp){
		printf ("Cannot open file %s!\n", TICKET_DATA_FILE);
		return 0;
	}	

	while(!feof(fp)){
		if(fread(&data, sizeof(ticket_t), 1, fp)){
			if(schedule_id == data.schedule_id){
				newNode = (ticket_node_t*) malloc(sizeof(ticket_node_t));
				if(!newNode){
					printf ("Cannot Load Memory!\n");
					exit (1);
				}
				newNode->data=data;
				List_AddTail(list, newNode);
				recCount++;
			}
		}
	}
	fclose(fp);
	return recCount;
}


int Ticket_Perst_SelectByKeyList(ticket_list_t list, entkey_list_t keyList) {
	
       return 1;
}
