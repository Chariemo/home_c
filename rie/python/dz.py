#coding=utf-8
i=1
s=0
while s<=8848:
	s=s+(2**i)*0.2*10**(-3)
	i=i+1
print '对折次数:',i
