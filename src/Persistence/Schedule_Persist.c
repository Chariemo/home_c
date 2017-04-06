#include "Schedule_Persist.h"
#include "../Service/Schedule.h"
#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../View/Ticket_UI.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<unistd.h>


static const char SCHEDULE_DATA_FILE[] = "Schedule.dat";
static const char SCHEDULE_DATA_TEMP_FILE[] = "ScheduleTmp.dat";

int Schedule_Perst_Insert(const schedule_t *data)
{
	// 请补充完整
	int rtn = 0;
	FILE *fp;
	if ((fp = fopen (SCHEDULE_DATA_FILE, "ab")) == NULL)
	{
		printf ("Cannot open file 1%s", SCHEDULE_DATA_FILE);
		return 0;
	}
	rtn = fwrite (data, sizeof (schedule_t), 1, fp);
	fclose (fp);
	return rtn;
}

int Schedule_Perst_Update(const schedule_t *data){
	// 请补充完整
	FILE *fp;
	if ((fp = fopen (SCHEDULE_DATA_FILE, "rb+")) == NULL)
	{
		printf ("Cannot open file 2%s!\n", SCHEDULE_DATA_FILE);
		return 0;
	}
	schedule_t buf;
	int found = 0;
	
	while (!feof (fp))
	{
		if (fread (&buf, sizeof (schedule_t), 1, fp))
			if (buf.id == data->id)
			{
				fseek (fp, -sizeof (schedule_t), SEEK_CUR);
				fwrite (data, sizeof (schedule_t), 1, fp);
				found = 1;
				break;
			}
	}
	fclose (fp);
	return found;
	
       return 1;
}

int Schedule_Perst_DeleteByID(int ID){
	// 请补充完整
   	FILE *fp1, *fp2;
	schedule_t buf;
	int found;
	rename (SCHEDULE_DATA_FILE, SCHEDULE_DATA_TEMP_FILE);
	if ((fp1 = fopen (SCHEDULE_DATA_FILE, "wb")) == NULL)
	{	
		printf ("Open fail!1");
		exit (1);
	}
	if ((fp2 = fopen (SCHEDULE_DATA_TEMP_FILE, "rb")) == NULL)
	{
		printf ("Open fail!2");
		exit (2);
	}
	found = 0;
	while (!feof (fp2))
	{
		
		fread (&buf, sizeof (schedule_t), 1 ,fp2);
		if (buf.id == ID)
			found = 1;
		else 
			fwrite (&buf, sizeof (schedule_t), 1, fp1);
	} 
	fclose (fp1);
	fclose (fp2);
	remove (SCHEDULE_DATA_TEMP_FILE);
	return found;
}

int Schedule_Perst_SelectByID(int ID, schedule_t *buf){
	// 请补充完整
	FILE *fp;
	schedule_t data;
	int found = 0;
	if ((fp = fopen (SCHEDULE_DATA_FILE, "rb")) == NULL)
	{
		printf ("Cannot open filee3 %s", SCHEDULE_DATA_FILE);	
		return 0;
	}
	while (!feof (fp))
	{
		if (fread (&data, sizeof (schedule_t), 1, fp))
			if (data.id == ID)
			{
				*buf = data;
				found = 1;
				break;
			}
	}
	fclose (fp);
	return found;
}

int Schedule_Perst_SelectAll(schedule_list_t list){
	// 请补充完整
	assert (list != NULL);
	FILE *fp;
	int count = 0;
	schedule_node_t *newNode;
	schedule_t data;
	if ((fp = fopen (SCHEDULE_DATA_FILE, "rb")) == NULL)
	{
		printf ("Cannot open file 4%s!\n", SCHEDULE_DATA_FILE);
		return 0;
	}
	List_Free (list, schedule_node_t);
	
	while (!feof (fp))
	{
		if (fread (&data, sizeof (schedule_t), 1, fp))
		{	
			newNode = (schedule_node_t *) malloc (sizeof (schedule_node_t));
			if (!newNode)
			{
				printf ("Warning, Memory Load Failed!\n");
				break;
			}
			newNode->data = data;
			List_AddTail (list, newNode);
			count ++;
		}
	}
	fclose (fp);
	return count;
}

int Schedule_Perst_SelectByPlay(schedule_list_t list, int play_id){
	// 请补充完整
	FILE *fp;
	int count = 0;
	assert (list != NULL);
	if ((fp = fopen (SCHEDULE_DATA_FILE, "rb")) == NULL)
	{
		printf ("Cannot open file5 %s", SCHEDULE_DATA_FILE);
		return 0;
	}
	schedule_t data;
	schedule_node_t *newNode;
	while (!feof (fp))
	{
		if (fread (&data, sizeof (schedule_t), 1, fp) == 0)
		{
			printf ("Failed!");
			return 0;
		}
		if (data.play_id == play_id)
		{
			if ((newNode = (schedule_node_t *) malloc (sizeof (schedule_node_t)))== NULL)
			{	
				printf ("Memory Load Failed!\n");
				return 0;
			}	
				newNode->data = data;
				List_AddTail (list, newNode);
				count++;
			
		}
	}
	fclose (fp);
	return count;
}
