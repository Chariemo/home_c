#coding=utf-8
from math import*
a,b,c=input('输入系数a,b,c:')
t=(b**2)-4*a*c
if t>=0:
	x1=(-b)+sqrt(t)
	x2=(-b)-sqrt(t)
	print '方程的解为:',x1,x2
else:
	print '无解'
