#include "Lexical.h"

bool IsLetter(char ch) {
    if ((ch >= 'a' && ch <= 'z') || ch >= 'A' && ch <= 'Z')
        return true;
    else
        return false;
}

bool IsDigit(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

char * Mystrupr(char * str, char *temp0) {
    char *temp = temp0;
    int i = 0;
    for (; *str != '\0'; str++) {
        temp[i++] = toupper(*str);
    }
    temp[i] = '\0';
    return temp;
}

int Reserve(char *str, PRW keywords) {
    int i;
    char temp[30]; //存放strToken大写化
    for (i = 0; i < NUM_K; i++) {
        if (strcmp(Mystrupr(str, temp), keywords[i].symbol) == 0) {
            return keywords[i].code;
        }
    }
    if (i == NUM_K) {
        return 0;
    }
}

char GetChar(char *str) {
    return str[index0++];
}

void Concat(char *str, char ch) {
    int index = 0;
    if (str[0] == '\0') {
        str[0] = ch;
        str[1] = '\0';
    }
    else {
        while (str[index] != '\0') {
            index++;
        }
        str[index] = ch;
        str[index+1] = '\0';
    }
}

void Retract(char *ch) {
    index0--;
    *ch = ' ';
}
void GetBC(char *str, char *ch) {
    if (*ch != ' ')
        return;
    else {
        do {
            *ch = GetChar(str);
        } while (*ch == ' ' && *ch != '\0');
    }
}

int InsertId(PID identifiers, char *str) {
    strcpy(identifiers[NUM_ID].symbol, str);
    identifiers[NUM_ID].code = 6;
    strcpy(identifiers[NUM_ID].value, str);
    NUM_ID++;
    return NUM_ID;
}

void ToBinary(char *str, int binary[]) {
    int i_str = atoi(str);
    int i;
    int temp[16];
    for(i = 0; i < 16; i++) {
         temp[i] = i_str % 2;
         i_str = i_str / 2;
    }
    for (i = 15; i >= 0; i--) {
        binary[15-i] = temp[i];
    }
}

int InsertConst(PNUM numbers, char *str) {
    strcpy(numbers[NUM_NUM].symbol, str);
    numbers[NUM_NUM].code = 7;
    int binary[16];
    int i;
    ToBinary(str, binary);
    for (i = 0; i < 16; i++) {
        numbers[NUM_NUM].value[i] = binary[i];
    }
    NUM_NUM++;
    return NUM_NUM;
}

int InsertSymbol(PSYM symbols, char *str, int code) {
     strcpy(symbols[NUM_SYM0].symbol, str);
     symbols[NUM_SYM0].code = code;
     strcpy(symbols[NUM_SYM0].value, "-");
     NUM_SYM0++;
     return NUM_SYM0;
}

void Run(RW keywords[], ID identifiers[], NUM numbers[],
        SYM symbols[]) {
    char ch = ' ';
    int code, value;
    char *strin = (char *) malloc(sizeof(char) * 200);
    if (strin == NULL)
        exit(0);
    fgets(strin, 200, stdin);
    char *strToken = (char *) malloc(sizeof(char) * 30);
    if (strToken == NULL)
        exit(0);

    do {
        strToken[0] = '\0';
        ch = GetChar(strin);
        GetBC(strin, &ch);
        if (IsLetter(ch)) {
            while (IsLetter(ch) || IsDigit(ch)) {
                 Concat(strToken, ch);
                 ch = GetChar(strin);
            }
            Retract(&ch);
            code = Reserve(strToken, keywords);

            if (code == 0) {
                InsertId(identifiers, strToken);
                printf("ID:%s\n", strToken);
            }
            else {
                printf("KEYWORD: %s\n", strToken);
            }
        }
        else if (IsDigit(ch)) {
            while (IsDigit(ch)) {
                 Concat(strToken, ch);
                 ch = GetChar(strin);
            }
            Retract(&ch);
            value = InsertConst(numbers, strToken);
            printf("NUM: %s\n", strToken);
        }
        else if (ch == '=') {
            Concat(strToken, ch);
            InsertSymbol(symbols, strToken, 8);
            printf("Symbol: %s\n", strToken);
        }
        else if (ch == '+') {
            Concat(strToken, ch);
            ch = GetChar(strin);
            if (ch == '+') {
                Concat(strToken, ch);
                InsertSymbol(symbols, strToken, 9);
                printf("Symbol: %s\n", strToken);
            }
            else {
                Retract(&ch);
                InsertSymbol(symbols, strToken, 10);
                printf("Symbol: %s\n", strToken);
            }
        }
        else if (ch == '-') {
            Concat(strToken, ch);
            ch = GetChar(strin);
            if (ch == '-') {
                Concat(strToken, ch);
                InsertSymbol(symbols, strToken, 11);
                printf("Symbol: %s\n", strToken);
            }
            else {
                Retract(&ch);
                InsertSymbol(symbols, strToken, 12);
                printf("Symbol: %s\n", strToken);
            }
        }
        else if (ch == '*') {
            Concat(strToken, ch);
            ch = GetChar(strin);
            if (ch == '*') {
                Concat(strToken, ch);
                InsertSymbol,(symbols, strToken, 13);
                printf("Symbol: %s\n", strToken);
            }
            else {
                Retract(&ch);
                InsertSymbol(symbols, strToken, 14);
                printf("Symbol: %s\n", strToken);
            }
        }
        else if (ch == ';') {
            Concat(strToken, ch);
            InsertSymbol(symbols, strToken, 15);
            printf("Symbol: %s\n", strToken);
        }
        else if (ch == '(') {
            Concat(strToken, ch);
            InsertSymbol(symbols, strToken, 16);
            printf("Symbol: %s\n", strToken);
        }
        else if (ch == ')') {
            Concat(strToken, ch);
            InsertSymbol(symbols, strToken, 17);
            printf("Symbol: %s\n", strToken);
        }
        else if (ch == '{') {
            Concat(strToken, ch);
            InsertSymbol(symbols, strToken, 18);
            printf("Symbol: %s\n", strToken);
        }
        else if (ch == '}') {
            Concat(strToken, ch);
            InsertSymbol(symbols, strToken, 19);
            printf("Symbol: %s\n", strToken);
        }
        else if (ch == '>') {
            Concat(strToken, ch);
            ch = GetChar(strin);
            if (ch == '=') {
                Concat(strToken, ch);
                InsertSymbol(symbols, strToken, 20);
                printf("Symbol: %s\n", strToken);
            }
            else {
                Retract(&ch);
                InsertSymbol(symbols, strToken, 21);
                printf("Symbol: %s\n", strToken);
            }
        }
        else if (ch == '<') {
             Concat(strToken, ch);
             ch = GetChar(strin);
             if (ch == '=') {
                 Concat(strToken, ch);
                 InsertSymbol(symbols, strToken, 22);
                 printf("Symbol: %s\n", strToken);
             }
             else {
                  Retract(&ch);
                  InsertSymbol(symbols, strToken, 23);
                  printf("Symbol: %s\n", strToken);
             }
        }
        else if (ch == '\n') {
             printf("END!\n");
        }
        else if (ch == '\0') {
             exit(0);
        }
        else {
            printf("Error!!! I don't know what it is! ascii: %d\n", ch);
        }
    } while (ch != '\0');

    free(strin);
    free(strToken);
}

int main(void) {
    RW keywords[NUM_K] = {{"WHILE", 1, "-"}, {"FOR", 2, "-"},
        {"IF", 3, "-"}, {"ELSE", 4, "-"}, {"DO", 5, "-"}};
    ID identifiers[30];
    NUM numbers[30];
    SYM symbols[30];
/*
    strcpy(keywords[0].symbol, "WHILE");
    keywords[0].code = 1;
    strcpy(keywords[0].value, "-");

    strcpy(keywords[1].symbol, "FOR");
    keywords[1].code = 2;
    strcpy(keywords[1].value, "-");

    strcpy(keywords[3].symbol, "IF");
    keywords[3].code = 3;
    strcpy(keywords[3].value, "-");

    strcpy(keywords[4].symbol,"ELSE");
    keywords[4].code = 4;
    strcpy(keywords[4].value, "-");

    strcpy(keywords[5].symbol, "DO");
    keywords[5].code = 5;
    strcpy(keywords[5].value, "-");
*/
    Run(keywords, identifiers, numbers, symbols);
    return 0;
}
