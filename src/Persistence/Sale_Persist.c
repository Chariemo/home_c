#include "Sale_Persist.h"
#include "../Common/List.h"
#include "../Service/Sale.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

static const char SALE_DATA_FILE[] = "Sale.dat";
static const char SALE_DATA_TEMP_FILE[] = "SaleTmp.dat";

int Sale_Perst_Insert(const sale_t *data) {
	// 请补充完整
    FILE *fp;
	int rtn;
	if((fp = fopen(SALE_DATA_FILE,"ab")) == NULL)
		printf("Open failure!\n");
	else
		rtn = fwrite(data,sizeof(sale_t),1,fp);
		fclose(fp);
		return (rtn);
}


int Sale_Perst_DeleteByID(int saleID) {
	// 请补充完整
    
	FILE *fp1, *fp2;
	sale_t buf;
	int found;
	rename (SALE_DATA_FILE, SALE_DATA_TEMP_FILE);
	if ((fp1 = fopen (SALE_DATA_FILE, "wb")) == NULL)
	{	
		printf ("Open failure!");
		exit (1);
	}
	if ((fp2 = fopen (SALE_DATA_TEMP_FILE, "rb")) == NULL)
	{
		printf ("Open failure");
		exit (2);
	}
	found = 0;
	while (!feof (fp2))
	{
		
		if ((fread (&buf, sizeof (sale_t), 1 ,fp2)) == 0)
		{
			printf ("Failed!\n");
			exit (3);
		}
		if (buf.id == saleID)
			found = 1;
		else 
			fwrite (&buf, sizeof (sale_t), 1, fp1);
	} 
	fclose (fp1);
	fclose (fp2);
	remove (SALE_DATA_TEMP_FILE);
	return found;
}

//根据用户ID载入给定时间区间内的销售记录
int Sale_Perst_SelectByUsrID(sale_list_t list, int usrID, user_date_t stDate,
		user_date_t endDate) {

	// 请补充完整
       return 1;
}


//根据给定时间区间内的销售记录
int Sale_Perst_SelectByDate(sale_list_t list, user_date_t stDate,
		user_date_t endDate) {

	// 请补充完整
    FILE *fp;
	int recCount = 0;
	sale_t saleRec;
	sale_node_t *newNode;
	if((fp = fopen(SALE_DATA_FILE,"rb")) == NULL)
		printf("Cannot open file %s!\n", SALE_DATA_FILE);
	else
	{
		while(!feof(fp))
		{
			if(!fread(&saleRec,sizeof(sale_t),1,fp))
			{
				if (saleRec.date.day >= stDate.day && saleRec.date.day <= endDate.day)
				{
					if ((newNode = (sale_node_t *) malloc (sizeof (sale_node_t))) == NULL)
					{
						printf ("Load Memory Failed!\n");	
						exit (1);
					}
					newNode->data = saleRec;
					List_AddTail (list, newNode);
					recCount++;
				}
			}
		}
	}
	fclose (fp);
	return recCount;
}

/*

//queryUid = null,query all the uid Sale information return the all uid Sale information number
//queryUid =  uid, query the uid Sale information return the uid Sale  number
 *
int  Sale_Infor_By_Uid(char * queryUid, Sale_list_t head)
{
       // 请补充完整
       return 1;
}

int Sale_Infor_By_Time(char  queryTime[][30], Sale_list_t head)
{
// 请补充完整
       return 1;
}

//根据票的id获得票的基本信息 
int Select_Price_By_Playid(int id, ticket_t *buf)
{
// 请补充完整
       return 1;
}
*/

