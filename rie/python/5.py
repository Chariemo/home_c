#coding=utf-8
x=input('请输入自变量x=')
if x<-5:
	y=x+9
elif -5<=x<5:
	y=x**2+2*x+1
else:
	y=2*x-15
print('函数值y=%d'%y)
