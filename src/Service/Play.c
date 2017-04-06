#include "Play.h"
#include "../Common/List.h"
#include "../Persistence/Play_Persist.h"
#include <string.h>


inline int Play_Srv_Add(const play_t *data) {
	// �벹������
	return Play_Perst_Insert (data);
}

inline int Play_Srv_Modify(const play_t *data) {
	// �벹������
	return Play_Perst_Update (data);
}

inline int Play_Srv_DeleteByID(int ID) {
	// �벹������
	return Play_Perst_DeleteByID (ID);
}

inline int Play_Srv_FetchByID(int ID, play_t *buf) {
	// �벹������
	return Play_Perst_SelectByID (ID, buf);

}

inline int Play_Srv_FetchAll(play_list_t list) {
	// �벹������
	return Play_Perst_SelectAll (list);
		
}

//���ݾ�Ŀ���������Ŀ����������ľ�Ŀ����
int Play_Srv_FetchByName(play_list_t list, char condt[]){
	// �벹������
       return 1;
}



//���ݾ�Ŀ���ƹ��˴�filter��list���й��ˣ����ع��˺�ʣ��ľ�Ŀ����
int Play_Srv_FilterByName(play_list_t list, char filter[]){
	// �벹������
       return 1;
}


