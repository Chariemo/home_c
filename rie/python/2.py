#coding=utf-8
num=input('请输入一个不多于五位的正整数:')
if num<=9:
	print'它是一位数'
elif num<=99:
	print'它是两位数'
elif num<=999:
	print '它是三位数'
elif num<=9999:
	print'它是四位数'
else:
	print'它是五位数'
a=num//10000
b=(num-a*10000)//1000
c=(num-a*10000-b*1000)//100
d=(num-a*10000-b*1000-c*100)//10
e=num-a*10000-b*1000-c*100-d*10
print '万位:',a
print'千位:',b
print'百位:',c
print'十位:',d
print'个位:',e
print'它的逆序为：',e,d,c,b,a
