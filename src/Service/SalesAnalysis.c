/*
 * salesanalysis.c
 *
 *  Created on: 2015��6��12��
 *      Author: Administrator
 */
#include <string.h>
#include <stdio.h>
#include "SalesAnalysis.h"
#include "../Persistence/Sale_Persist.h"
#include "Sale.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"

#include "../Common/List.h"

//����Ա��usrID�ڸ���ʱ����������۶�
inline int Salesanalysis_Srv_CompSaleVal(int usrID, user_date_t stDate, user_date_t endDate){
	// �벹������
       return 1;
}

//ͳ����������
int Salesanalysis_Srv_StaticSale(salesanalysis_list_t list) {

	// �벹������
       return 1;
}

//����Ʊ������
void SalesAnalysis_Srv_SortBySale(salesanalysis_list_t list){
	// �벹������
}

/*

//ʵ���������ݷ�������ȡ�����õ��������ݣ�д�����۷�����salesanalysis_list_t slist��������
int SalesAnalysis_Srv_Analysis(play_list_t plist, sale_list_t salist,
		salesanalysis_list_t slist) {
	// �벹������
       return 1;
}

//���۷���������slist��������ݣ�����ĿƱ����������sales���ֶν�������
//sanalysisrec �����۷���������slist���������
void SalesAnalysis_Srv_Sort(salesanalysis_list_t slist, int sanalysisrec) {
	// �벹������
}

//���ݾ�Ŀ��play����id���ҵ�Sale.dat��ƥ��ļ�¼,���ؼ�¼����������Ʊ��
long SalesAnalysis_Srv_CountTicketByID(sale_list_t list, int playID) {
	// �벹������
       return 1;
}

inline int Salesanalysis_Srv_Insert(const salesanalysis_t *data) {
	// �벹������
       return 1;
}
inline int SalesAnalysis_Srv_FetchAll(salesanalysis_list_t list) {
	// �벹������
       return 1;
}
inline int Sale_Srv_FetchAll(sale_list_t list) {
	// �벹������
       return 1;
}
*/