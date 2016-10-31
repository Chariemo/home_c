#ifndef _HuffmanCode_H_
#define _HuffmanCode_H_

#define N 256 //叶子个数
#define M 2*N-1 //huffman结点个数
#define MAXINT 32787
#define MAX 10000 //最大文本字符数
typedef struct
{
	char ch;
	int weight;
	int parent;
	int LChild;
	int RChild;
}HTNode, HuffmanTree[M+1];

typedef char * HuffmanCode[N+1];  //编码表

int count = 0; //实际叶子数
void Init (HuffmanTree ht, int w[]);//初始化 读入文件 统计字符频度
void CrtHuffmanTree (HuffmanTree ht, int w[]); //Huffman创建
void CrtHuffmanCode (HuffmanTree ht, HuffmanCode hc);//编码
void HuffmanDecode (HuffmanTree ht, HuffmanCode hc);//译码
void select_ht (HuffmanTree ht, int pos, int *s1, int *s2);//选择权值最小的叶子结点
int copy (char *str1, char *str2, int pos);// 取得译码过程中剩余的编码字符
void compress (HuffmanTree ht, HuffmanCode hc); //压缩
void uncompress (); //解压缩



#endif
