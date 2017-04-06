v#coding=utf-8
import math 
a,b,c=input('请输入三角形三边长:')
if a+b>c or a+c>b or b+c>a:
	p=(a+b+c)/2
	temp=p*(p-a)*(p-b)*(p-c)
	area=math.sqrt(temp)
	if a==b==c:
		r='等边三角形'
	elif a==b!=c:
		r='等腰三角形'
	elif a**2+b**2==c**2 or a**2+c**2==b**2 or b**2+c**2==a**2:
		r='直角三角形'
	else:
		r='普通三角形'
else:
	r='非三角形'
if r!='非三角形':
	print('三角形的面积是:%d'%area)
   	print('三边构成:%s'%r)
