#coding=utf-8
list1=[]
list2=[]
list3=[]
n=input('输入n的值:')
for i in range(1,n+1,1):
	x=input('输入一个数:')
	if x>0:
		list1=list1+[x]
	elif x<0:
		list2=list2+[x]
	else:
		list3=list3+[x]
print '这些数中正数的个数:',len(list1)
print '这些数中负数的个数:',len(list2)
print '这些数中零的个数:',len(list3)
