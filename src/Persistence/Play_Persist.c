#include "Play_Persist.h"
#include "../Service/Play.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<unistd.h>
#include <string.h>

static const char PLAY_DATA_FILE[] = "Play.dat";
static const char PLAY_DATA_TEMP_FILE[] = "PlayTmp.dat";

int Play_Perst_Insert(const play_t *data) {
	// 请补充完整
   	assert(NULL!=data);

	FILE *fp=fopen(PLAY_DATA_FILE,"ab");

	int rtn=0;

	if(fp==NULL){

		printf("cannot open file %s!\n",PLAY_DATA_FILE);

		return 0;

	}

	rtn=fwrite(data,sizeof(play_t),1,fp);

	fclose(fp);

	return rtn;
}

int Play_Perst_Update(const play_t *data) {
	// 请补充完整
	assert (NULL != data);
       int found=0;
	play_t buf;
	FILE *fp=fopen(PLAY_DATA_FILE,"rb+");
	if(NULL==fp)
	{
		printf("open file error\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&buf,sizeof(play_t),1,fp))
			if(data->id==buf.id)
			{
				fseek(fp,-sizeof(play_t),SEEK_CUR);
				fwrite(data,sizeof(play_t),1,fp);
				found=1;
				break;
			}
	}
	fclose(fp);
	return found;
}

int Play_Perst_DeleteByID(int ID) {
	// 请补充完整
          	if(rename(PLAY_DATA_FILE,PLAY_DATA_TEMP_FILE)<0){

		printf("cannot open file %s!\n",PLAY_DATA_FILE);

		return 0;

	}

	FILE *fpSour,*fpTarg;

	fpSour=fopen(PLAY_DATA_TEMP_FILE,"rb");

	if(NULL==fpSour){

		printf("cannot open file %s!\n",PLAY_DATA_TEMP_FILE);

		return 0;

	}

	fpTarg=fopen(PLAY_DATA_FILE,"wb");

	if(NULL==fpTarg){

		printf("cannot open file %s!\n",PLAY_DATA_FILE);

		return 0;

	}

	play_t buf;

	int found=0;

	while(!feof(fpSour)){

		if(fread(&buf,sizeof(play_t),1,fpSour)){

			if(ID!=buf.id){
				fwrite(&buf,sizeof(play_t),1,fpTarg);
			}
			else 
				found = 1;
		}
	}
	fclose(fpTarg);

	fclose(fpSour);

	remove(PLAY_DATA_TEMP_FILE);

	return found;
}

int Play_Perst_SelectByID(int ID, play_t *buf) {
	// 请补充完整a
	FILE *fp;
	play_t data;
	int found = 0;
	if ((fp = fopen (PLAY_DATA_FILE, "rb")) == NULL)
	{
		printf ("Cannot open file %s", PLAY_DATA_FILE);
		exit (0);
	}
	while (!feof (fp))
	{
		if (fread (&data, sizeof (play_t), 1, fp))
		{
			if (data.id == ID)
			{
				*buf = data;
				found = 1;
				break;
			}
		}
	}
	fclose (fp);
	return found;
	
}

int Play_Perst_SelectAll(play_list_t list) {
	// 请补充完整
	play_node_t *newNode;
	play_t data;
	int recCount = 0;

	assert (NULL != list);
		
	List_Free (list, play_node_t);
		
	FILE *fp = fopen (PLAY_DATA_FILE, "rb");
	if (NULL == fp)
	{
		return 0;
	}

	while (!feof (fp))
	{	
		if(fread (&data, sizeof (play_t), 1, fp))
		{
			newNode = (play_node_t *) malloc (sizeof (play_node_t));
			if (!newNode)
			{
				printf ("Memory Load fail!\n");
				break;
			}
			newNode->data = data;
			List_AddTail (list, newNode);
			recCount ++;
		}
	}
	fclose (fp);
	return recCount;	
}

/*int Play_Perst_SelectByName(play_list_t list, char condt[]) {
	// 请补充完整
	assert (list != NULL);
	FILE *fp;
	int rtn = 0;
	if ((fp = fopen (PLAY_DATA_FILE, "rb")) == NULL)
	{
		printf ("Cannot open file %s!\n", PALY_DATA_FILE);
		return 0;
	}
	play_t buf;
	while (!feof (fp))
	{
		if (fwrite (&buf, sizeof (play_t), 1, fp))
			if (strcmp (buf.name, condt))
			{
				rtn = 1;
				break;
			}
	}
	fclose (fp);
	return rtn;
}
		
	*/

