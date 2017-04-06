/*
 *  Seat_Persist.c
 *
 *  Created on: 2015年5月23日
 *  Author: lc
 */

#include "Seat_Persist.h"
#include "../Service/Seat.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<unistd.h>

static const char SEAT_DATA_FILE[] = "Seat.dat";
static const char SEAT_DATA_TEMP_FILE[] = "SeatTmp.dat";

int Seat_Perst_Insert(const seat_t *data) {
	// 请补充完整
	assert(NULL!=data);

	FILE *fp = fopen(SEAT_DATA_FILE, "ab");

	int rtn=0;

	if (NULL == fp) {

		printf("cannot open file %s!\n",SEAT_DATA_FILE);

		return 0;

	}



	rtn=fwrite(data, sizeof(seat_t), 1, fp);



	fclose(fp);



       return rtn;
}

int Seat_Perst_InsertBatch(seat_list_t list) {
	// 请补充完整
	assert (list != NULL);
	FILE *fp;
	int rtn=0;
	seat_node_t *Node;
	Node = list->next;
	seat_t data;
	data = Node->data;
	fp=fopen(SEAT_DATA_FILE,"ab");
	if(fp==NULL)
	{
		printf("Cannot open file %s!\n", SEAT_DATA_FILE);
		exit(0);	
	}
	else
	{
		while (Node != list)
		{
			if (fwrite(&data, sizeof(seat_t) , 1 ,fp))
			{
				rtn++;
				Node = Node->next;
				data = Node->data;
			}
		}
	}
	fclose (fp);
	return rtn;

}

int Seat_Perst_Update(const seat_t *data) {
	// 请补充完整
	
	assert (data!= NULL);
	seat_t buf;
	int found = 0;
	FILE *fp=fopen(SEAT_DATA_FILE,"rb+");
	if(NULL==fp)
	{
		printf("open file error\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&buf,sizeof(seat_t),1,fp))
			if(data->id==buf.id)
			{
				fseek(fp,-sizeof(seat_t),SEEK_CUR);
				fwrite(data,sizeof(seat_t),1,fp);
				found=1;
				break;
			}
	}
	fclose(fp);
	return found;

}

int Seat_Perst_DeleteByID(int ID) {
	// 请补充完整
	if (rename (SEAT_DATA_FILE, SEAT_DATA_TEMP_FILE) < 0)
	{
	printf ("Cannot open file %s",SEAT_DATA_FILE);
	return 0;
	}
	FILE *fp1, *fp2;
	if ((fp1 = fopen (SEAT_DATA_FILE, "wb")) == NULL)
 	{
		printf ("Cannot open file %s", SEAT_DATA_FILE);
		return 0;
	}
	if ((fp2 = fopen (SEAT_DATA_TEMP_FILE, "rb")) == NULL)
	{
		printf ("Cannot open file %s", SEAT_DATA_TEMP_FILE);
	return 0;
	}
  	seat_t buf;
	int found = 0;
	while (!feof (fp2))
		if (fread (&buf, sizeof (seat_t), 1, fp2))
		{
			if (ID == buf.id)
			{
				found = 1;
				continue;
			}
			fwrite (&buf, sizeof (seat_t), 1, fp1);
		}
	fclose (fp1);
	fclose (fp2);
	remove (SEAT_DATA_TEMP_FILE);
    return found;
}


int Seat_Perst_DeleteAllByRoomID(int roomID) {
	// 请补充完整
	FILE *fp1, *fp2;
	seat_t *buf;
	int count = 0;
	if (rename (SEAT_DATA_FILE, SEAT_DATA_TEMP_FILE) < 0)
	{
		printf ("Cannot open file %s!\n", SEAT_DATA_FILE);
		return 0;
	}
	if ((fp1 = fopen (SEAT_DATA_FILE, "wb")) == NULL)
	{
		printf ("Cannot open file %s!\n", SEAT_DATA_FILE);
		return 0;
	}
	if ((fp2 = fopen (SEAT_DATA_TEMP_FILE, "rb")) == NULL)
	{
		printf ("Cannot open file %s!\n", SEAT_DATA_TEMP_FILE);
		return 0;
	}
	
	while (!feof (fp2))
	{
		if (fread (buf, sizeof (seat_t), 1, fp2))
		{
			if (buf->roomID == roomID)
			{
				if (fwrite (buf, sizeof (seat_t), 1, fp1))
				{
					count++;
					continue;
				}
			}
		}
	}

	fclose (fp1);
	fclose (fp2);
	remove (SEAT_DATA_TEMP_FILE);
	return count;
				
}

int Seat_Perst_SelectByID(int ID, seat_t *buf) {
	// 请补充完整
	assert(NULL!=buf);



	FILE*fp=fopen(SEAT_DATA_FILE,"rb");

	if(NULL==fp){

		printf("cannot open file %s!\n",SEAT_DATA_FILE);

		return 0;

	}

	seat_t data;

	int found=0;

	while(!feof(fp)){

	    if(fread(&data,sizeof(seat_t),1,fp)){

		if(ID==data.id){

			*buf=data;

			found=1;

			break;

		}

	    }

	}

	fclose(fp);	

       return found;
}

int Seat_Perst_SelectAll(seat_list_t list) {
	// 请补充完整
	seat_node_t *newNode;
	seat_t data;
	int recCount = 0;
	
	assert (NULL != list);
	
	List_Free (list, seat_node_t);
	FILE *fp;
	if ((fp = fopen (SEAT_DATA_FILE,"rb")) == NULL)	
	{
		printf ("Cannot open file %s", SEAT_DATA_FILE);
		return 0;
	}
	while (!feof (fp))
	{
		if (fread (&data, sizeof (seat_t), 1, fp))
		{
			newNode = (seat_node_t *) malloc (sizeof (seat_node_t));
			if (!newNode)
			{
				printf ("Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
				break;
			}
			newNode->data = data;
			List_AddTail (list, newNode);
			recCount++;
		}
	}
	fclose (fp);
	return recCount;
}

int Seat_Perst_SelectByRoomID(seat_list_t list, int roomID) {
	// 请补充完整
	FILE *fp;
	seat_t buf;
	seat_node_t *newNode;
	int count = 0;
	assert (list != NULL);
	
	List_Free (list, seat_node_t);
	if ((fp = fopen (SEAT_DATA_FILE, "rb")) == NULL)
	{
		printf ("Cannot open file1 %s!\n", SEAT_DATA_FILE);
		return 0;
	}
	while (!feof (fp))
	{
		if (fread (&buf, sizeof (seat_t), 1, fp))
		{
			if (buf.roomID == roomID)
			{
				if ((newNode = (seat_node_t *) malloc (sizeof (seat_node_t))) == NULL)
				{
					printf ("Memory Load fail!\n");
					return 0;
				}
				newNode->data = buf;
				List_AddTail (list, newNode);
				count++;
			}
		}
	}
	fclose (fp);
	return count;
}
