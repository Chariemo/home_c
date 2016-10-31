#include "HuffmanCode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void )
{
	
	HuffmanTree ht;
    HuffmanCode hc;
    printf ("\n\n\t\t\tWellcome!!!\n\n");

    char ch ;
    ch = getchar ();
    
	int w[N] = {0}; //字符频度
    Init (ht, w);
    CrtHuffmanTree (ht, w);
    CrtHuffmanCode (ht, hc);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("-----------------------简单文本压缩工具------------------------\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("****                                                       ****\n");
    printf ("****              1、压缩. (Local.souce -> Local.zig)      ****\n");
    printf ("****                                                       ****\n");
    printf ("****              2、解压. (Local.zig -> Local.final)      ****\n");
    printf ("****                                                       ****\n");
    printf ("****                                local.code (编码文件)  ****\n");
    printf ("****                                ( 自行检查相应文件 )   ****\n");
    printf ("****                                  Enter 'q' to quit    ****\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("Now your choice: ");
    setbuf (stdin, NULL);
    ch = getchar ();
    if (ch == '1')
        compress (ht, hc);
    else if(ch == '2')
        uncompress ();
    else if (ch == 'q')
        return 0;
	return 0;
}
//初始化 读入文件 统计字符频度
void Init (HuffmanTree ht, int w[])
{
	FILE *fp;
	char ch;
	int i;
	int tag; //判断字符是否已读入
	if ((fp = fopen ("Local.souce" , "rb")) == NULL)
	{
        printf ("Open %s failed!", "Local.souce");	
		exit (0);
	}
	while ((ch = getc (fp)) != EOF)
	{
		tag = 0;
		for (i = 1; i <= count; i++)
			if (ch == ht[i].ch)
			{	
				w[i]++;
				tag = 1;
			}
		if (tag == 0)
		{
			ht[++count].ch = ch;
			w[count]++;
		}
	}	
	fclose (fp);
}
//Huffman创建
void CrtHuffmanTree (HuffmanTree ht, int w[])
{
	int i, s1, s2, m;
	m = 2 * count - 1;
	for (i = 1; i <= count; i++)
	{
		ht[i].weight = w[i];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = count+1; i <= m; i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = count+1; i<= m; i++)
	{
		select_ht (ht, i-1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[i].LChild = s1;
		ht[i].RChild = s2;
		ht[s1].parent = ht[s2].parent = i;
	}
}
// 创建编码表
void CrtHuffmanCode (HuffmanTree ht, HuffmanCode hc)
{
    char *cd, *codes;
    FILE *fp;
    char ch;
	int start, c, p, i;
	cd = (char *) malloc (N * sizeof (char));
    cd[N-1] = '\0';
	for (i = 1; i <= count; i++)
	{    
		start = N - 1;
		c = i;
		p = ht[i].parent;
		while (p != 0)
		{
			--start;
			if (ht[p].LChild == c) 
				cd[start] = '0';
			else
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}
        hc[i] = (char *) malloc ((N-start)* sizeof (char));
		strcpy (hc[i], &cd[start]);
	}
    if ((codes = (char *) malloc (MAXINT * sizeof (char))) == NULL)
        exit (0);
    memset (codes, 0, sizeof (codes));
    if ((fp = fopen ("Local.souce", "rb")) == NULL)
    {
            printf ("Open failed!\n");
            exit (0);
    }
    while ((ch = getc (fp)) != EOF)
        for (i = 1; i <= count; i++)        
            if (ht[i].ch == ch)
            {
                strcat (codes, hc[i]);
                break;
            }
    if ((fp = fopen ("Local.code", "wb")) == NULL)
    {
        printf ("Open failed!\n");
        exit (0);
    }            
    fputs (codes, fp);
    fclose (fp);
    free (codes);
	free (cd);
}


//截取待译文本编码
int copy (char *str1, char *str2, int pos)
{ 
	char *q; int tag = 0;
    q = str1 + pos;
    while (*q != '\0')
	{
		tag = 1;
        *str2++ = *q++;
    }
	*str2 = '\0';
	return tag;
}

//选择权值最小的两个叶子结点
void select_ht (HuffmanTree ht, int pos, int *s1, int *s2)
{
	int m1, m2, i, j;
	m1 = m2 = MAXINT;
	for (i = 1; i <= pos; i++)
	{
		if (ht[i].weight < m1 && ht[i].parent == 0)
		{
			m2 = m1;
			*s2 = *s1;
			*s1 = i;
			m1 = ht[i].weight;
		}
		else if (ht[i].weight < m2 && ht[i].parent == 0)
		{
			m2 = ht[i].weight;
			*s2 = i;
		}
	}
}
//压缩
void compress (HuffmanTree ht, HuffmanCode hc)
{   
    FILE *fp, *outfp, *data, *message;
	char temp[9], ch1, ch2;
	int i, j, k;
	int length = 0;//压缩文件长度
	int flag ; // 记录最后剩余几位	
    if ((data = fopen ("Local.data", "wb")) == NULL)
    {
        printf ("Open failed!\n");
        exit (0);
    }
    fwrite (ht, sizeof (HuffmanTree), 1, data);
	if ((fp = fopen ("Local.souce", "rb")) == NULL)
	{
		printf ("Open %s failed!\n", "Local.souce");
		exit (0);
	}
	if ((outfp = fopen ("Local.zig", "wb")) == NULL)
	{
		printf ("Open %s failed!\n", "Local.zig");
		exit (0);
	}

	while ((ch1 = getc (fp)) != EOF)
	{
		
		for (i = 1; i <= count; i++)
			if (ht[i].ch == ch1)
				strcat (temp, hc[i]);
		ch2 = 0;
		while ((j = strlen (temp)) >= 8)
		{
			for (i = 0; i < 8; i++)
			{
				if (temp[i] == '1')
					ch2 = (ch2<<1) | 1;
				else
					ch2 <<= 1;
			}
			fwrite (&ch2, 1, 1, outfp);
			length++;
			strcpy (temp, temp+8);
		}
	}
    flag = strlen (temp);
	if (j > 0)
	{
		strcat (temp, "00000000");
		for (i = 0; i < 8; i++)
		{
			if (temp[i] == '1')
				ch2 = (ch2<<1) | 1;
			else 
				ch2 <<= 1;
		}
		fwrite (&ch2, 1, 1, outfp);
		length++;
	}
    if ((message = fopen ("message.f", "wb")) == NULL)
    {
        exit (0);
    }
	fwrite (&flag, sizeof (int), 1, message);
	fwrite (&length, sizeof (int), 1, message);
	fclose (fp);
	fclose (outfp);
    fclose (data);
    fclose (message);
    printf ("Compress succeed!\n");
}

//解压缩
void uncompress ()
{
	FILE *cfp, *ucfp, *message, *data;
	char *code ;//解压文本编码
	int ch, i, j;
	int flag;
	int length = 0; //压缩文件长度
    int hcount = 0;
	static int size = 8 * sizeof (char);
    char temp[N];
    int count1 ;//解压文本关键字数
    HuffmanTree ht;
    HuffmanCode hc;
    if ((data = fopen ("Local.data", "rb")) == NULL)
    {
        printf ("Open failed\n");
        exit (0);
    }
    fread (ht, sizeof (HuffmanTree), 1, data);
    for (count1 = 1; ht[count1].ch ; count1++);
    count1--;
    CrtHuffmanCode (ht, hc);
    //解压
    if ((code = (char *) malloc (MAX * sizeof (char))) == NULL)
	{
		printf ("failed!\n");
		exit (0);
	}
	memset (code, 0, sizeof (code));
	if ((cfp = fopen ("Local.zig", "rb")) == NULL)
	{
		printf ("Open %s failed!\n", "Local.zig");
		exit (0);
	}
    if ((message = fopen ("message.f", "r")) == NULL)
        exit (0);
    fread (&flag, sizeof (int), 1, message);
	fread (&length, sizeof (int), 1, message);
	while ((ch = getc (cfp)) != EOF)
	{
		hcount++;
        memset (temp, 0, sizeof (temp));
		for (i = size - 1; i >= 0; i--, ch >>= 1)
			temp[i] = (1&ch) + '0';
        if (hcount == length) 
            temp[flag] = '\0';
		strcat (code, temp);
	}
 //译码
	int len_cd;//最长字符编码	
	char cd_1[MAX] = {0, 0, 0};
    char str[MAX] = {0,0,0};
	int tag; //判断是否匹配成功
    int len_ch = 0;//解压后文本长
	int len = 0;//已译码数
    len_cd = strlen (hc[1]);
	
    for (i = 2; i <= count1; i++)
		if (strlen (hc[i]) > len_cd)
			len_cd = strlen (hc[i]);
	while (copy (code, cd_1, len))
	{
		for (i = len_cd; i > 0; i--)
		{
			memset (temp, 0, sizeof (temp)); //清空temp[]
			strncpy (temp, cd_1, i);
			tag = 0;
			for (j = 1; j <= count1 && tag == 0; j++)
				if (strcmp (temp, hc[j]) == 0)
				{
					str[len_ch++] = ht[j].ch;
					tag = 1;
					len += i;
				}
			if (tag == 1)
				break;	
		}
	}
   
	if ((ucfp  = fopen ("Local.final", "wb")) == NULL)
	{
		printf ("Open %s failed!\n", "Local.decode");
		exit (0);
	}
    fputs (str, ucfp);
    fclose (ucfp);
    fclose (message);
	fclose (cfp);
    fclose (data);
	free (code);
    printf ("Uncompress succeed!\n");
}
