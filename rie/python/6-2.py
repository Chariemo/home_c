#coding=utf-8
def circle(r):
	area=3.14*r*r
	perimeter=2*3.14*r
	print'半径为',r,'的圆面积为:',area
	print'半径为',r,'的圆周长为:',perimeter
b='y'
while b[0]=='y':
	a=input('请输入圆半径:')
	circle(a)
	b=raw_input('要继续吗(y or n):')

