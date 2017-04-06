#coding=utf-8
list1=[]
for i in range(0,10):
	x=input('输入一个数:')
	list1=list1+[x]
print '平均分:',sum(list1)/10.0
print '最高分:',max(list1)
print '最低分:',min(list1)
