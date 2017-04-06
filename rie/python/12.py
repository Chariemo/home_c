#coding=utf-8
list1=[]
n=input('输入一个整数:')
for j in range(2,n,1):
	if n%j==0:
		list1=list1+[j]
print 'n的所有因子之和(除1和它本身):',sum(list1)
