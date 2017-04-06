#coding=utf-8
list1=[]
n=input('输入n的值:')
for i in range(1,n+1,1):
	x=input('输入一个字符:')
	list1=list1+[x]
print 'tuple=',tuple(list1)
