#include "Schedule.h"
#include "../Common/List.h"
#include "../Persistence/Schedule_Persist.h"
#include "Ticket.h"
#include <stdio.h>

inline int Schedule_Srv_Add(const schedule_t *data) {
	// �벹������
	int rtn;
	rtn = Schedule_Perst_Insert (data);
	if (Ticket_Srv_AddBatch (data->id, data->studio_id))
		return rtn;
   	return 0;
}

inline int Schedule_Srv_Modify(const schedule_t *data) {
	// �벹������
	int rtn;
	rtn = Schedule_Perst_Update (data);
	Ticket_Srv_DeleteBatch (data->id);
	Ticket_Srv_AddBatch (data->id, data->studio_id);
	return rtn;
}

inline int Schedule_Srv_DeleteByID(int ID) {
	// �벹������
	int rtn;
	rtn = Schedule_Perst_DeleteByID (ID);
	Ticket_Srv_DeleteBatch (ID);
    rtn;
}

inline int Schedule_Srv_FetchByID(int ID, schedule_t *buf) {
	// �벹������
	return Schedule_Perst_SelectByID (ID, buf);

}

inline int Schedule_Srv_FetchAll(schedule_list_t list) {
	// �벹������
	return Schedule_Perst_SelectAll (list);
	
}

inline int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id) {
	// �벹������
	return Schedule_Perst_SelectByPlay (list, play_id);
	
}

//�����ݳ�ID��ͳ�������ʼ�Ʊ��������Ʊ��������
int Schedule_Srv_StatRevByPlay(int play_id, int *soldCount, int *totalCount) {
	// �벹������
       return 1;
}

