#coding=utf-8
a=raw_input('请输入任意个数值(以逗号隔开):')
b=a.split(',')
s=1
for c in b:
	if int(c)%2!=0:
		s*=int(c)
	else:
		continue
print'所有奇数乘积是:',s
