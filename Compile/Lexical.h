#ifndef LEXICAL_H_
#define LEXICAL_H_

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>

#define NUM_K 30
int index0 = 0; //搜索指示器
int NUM_ID = 0; //标识符表含有数
int NUM_NUM = 0; //数字表含
int NUM_SYM0 = 0; //符号数

typedef struct {
    char symbol[8];
    int code;
    char value[8];
} RW, * PRW;

typedef struct {
    char symbol[8];
    int code;
    char value[8];
} ID, *PID;

typedef struct {
    char symbol[8];
    int code;
    int value[16];
}NUM, *PNUM;

typedef struct {
    char symbol[8];
    int code;
    char value[8];
}SYM, *PSYM;

bool IsLetter(char ch);

bool IsDigit(char ch);

char * Mystrupr(char *str, char *temp0);

int Reserve(char *str, PRW keywords);

char GetChar(char *str);

void Concat(char *str, char ch);

void Retract(char *ch);

void GetBC(char *str, char *ch);

void ToBibary(char *str, int binary[]);

int InsertId(PID identifiers, char *str);

int InsertConst(PNUM numbers, char *str);

int InsertSymbol(PSYM symbols, char *str, int code);

void Run(PRW keywords, PID identifiers, PNUM numbers,
        PSYM symbols);

#endif
