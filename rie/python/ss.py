#coding=utf-8

temp=101
for i in range(100,201,1):
	for j in range(2,i):
		if i%j==0:
			break
	if i%j==0:
		continue
	if temp==i-2:
		print '双胞胎素数:',temp,',',i
	temp=i
