#coding=utf-8
from math import*
i=1
s=0.0
x=input('输入首项:')
while i<20:
	s=s+x
	x=sqrt(x)
	i=i+1
print '数列前20项和:',s
