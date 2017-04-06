#coding=utf-8
i=1
s=0
z=1
n=input('输入一个n的值:')
for i in range(1,n+1,1):
	z=z*i
	s=s+z
print '1!+2!+...+n!=',s
