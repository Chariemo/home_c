#coding=utf-8
score=[]
a=0
b=0
while True:	
	print('请输入数字(以任意负数结束):'),
	x=input('')
	if x>=0:
		score+=[x]
		continue
	break
for i in score:
	if i%2==0:
		a+=1
	else:
		b+=1
print'偶数个数：',a
print'奇数个数：',b 
