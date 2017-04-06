#coding=utf-8
d={'0000':'特许用户','1234':'普通用户','1111':'授权用户'}
m=raw_input('请输入你的密码:'
if m in d.keys():
	print d[m]
else:
 	print'你输入的密码有误'
	m=raw_input('请重新输入密码:')
