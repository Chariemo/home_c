#coding=utf-8
import random
a=random.randint(0,10)
b=input('请在1-10之间猜一个数:')
while True:
	if b>a:
		print'大了！'
		b=input('请继续\n:')
	elif b<a:
		print'小了！'
		b=input('加油!\n:')
	else:
		print'你真是牛逼啊!'
		break
