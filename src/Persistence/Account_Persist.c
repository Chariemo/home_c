/*
 * Account_Persist.c
 *
 *  Created on: 2015年5月8日
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

//判断账号文件是否存在
int Account_Perst_CheckAccFile() {
       // 请补充完整
       return 1;
}

//根据用户名载入账号
int Account_Perst_SelByName(char usrName[], account_t *buf) {
	// 请补充完整
       return 1;
}

int Account_Perst_Insert(const account_t *data) {
	// 请补充完整
       return 1;
}

int Account_Perst_Update(const account_t * data) {
	// 请补充完整
       return 1;
}

int Account_Perst_DeleteByID(int id) {
	// 请补充完整
       return 1;
}

int Account_Perst_SelectByID(int id, account_t *buf) {
	// 请补充完整
       return 1;
}

int Account_Perst_SelectAll(account_list_t list) {
	// 请补充完整
       return 1;
}

