/*
 * Account_Persist.c
 *
 *  Created on: 2015��5��8��
 *      Author: Administrator
 */

#include "Account_Persist.h"
#include "../Service/Account.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include<unistd.h>
#include <string.h>

static const char ACCOUNT_DATA_FILE[] = "Account.dat";
static const char ACCOUNT_DATA_TEMP_FILE[] = "AccountTmp.dat";

//�ж��˺��ļ��Ƿ����
int Account_Perst_CheckAccFile() {
       // �벹������
       return 1;
}

//�����û��������˺�
int Account_Perst_SelByName(char usrName[], account_t *buf) {
	// �벹������
       return 1;
}

int Account_Perst_Insert(const account_t *data) {
	// �벹������
       return 1;
}

int Account_Perst_Update(const account_t * data) {
	// �벹������
       return 1;
}

int Account_Perst_DeleteByID(int id) {
	// �벹������
       return 1;
}

int Account_Perst_SelectByID(int id, account_t *buf) {
	// �벹������
       return 1;
}

int Account_Perst_SelectAll(account_list_t list) {
	// �벹������
       return 1;
}

