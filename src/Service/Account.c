/*
 * account.c
 *
 *  Created on: 2015��6��12��
 *      Author: Administrator
 */
#include "Account.h"
#include "EntityKey.h"
#include "../Common/List.h"
#include "../Persistence/Account_Persist.h"
#include <string.h>
#include <stdlib.h>

extern account_t gl_CurUser;

void Account_Srv_InitSys(){
	// �벹������
}
inline int Account_Srv_Verify(char usrName[], char pwd[]){

	// �벹������
       return 1;
}



account_node_t * Account_Srv_FindByUsrName(account_list_t list, char usrName[]) {
	// �벹������
       return NULL;
}


inline int Account_Srv_Add(const account_t *data){
	// �벹������
       return 1;
}
inline int Account_Srv_Modify(const account_t *data){
	// �벹������
       return 1;
}
inline int Account_Srv_DeleteByID(int usrID){
	// �벹������
       return 1;
}
inline int Account_Srv_FetchByID(int usrID, account_t *buf){
	// �벹������
       return 1;
}

inline int Account_Srv_FetchByName(char usrName[], account_t *buf){
	// �벹������
       return 1;
}

inline int Account_Srv_FetchAll(account_list_t list){
	// �벹������
       return 1;
}


