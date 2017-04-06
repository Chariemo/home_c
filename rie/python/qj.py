#coding=utf-8
from math import*
a,b,c=input('输入方程系数a,b,c:')
t=b**2-4*a*c
if t>=0:
	x1=((-b)+sqrt(t))/(2*a)
	x2=((-b)-sqrt(t))/(2*a)
	print '解为:','x1=',x1,',','x2=',x2
else:
	print '解不存在'
