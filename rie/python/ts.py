#coding=utf-8
a=raw_input('请输入年月（例如201412）:')
b=a[0:4]
c=a[4:]
if int(c)==(1 or 3 or 5 or 7 or 8 or 10 or 12):
	print'次月有31天'
elif int(c)==(4 or 6 or 9 or 11):
	print'次月有30天'
else:
	if (int(b)%400==0 or (int(b)%4==0 and int(b)%100!=0)):
		print'次月有29天'
	else:
		print'次月有28天'
