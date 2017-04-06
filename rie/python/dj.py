#coding=utf-8
from math import*
x1,y1=input('输入第一象限的点坐标:')
x3,y3=input('输入第三象限的点坐标:')
d=sqrt((x1-x3)**2+(y1-y3)**2)
print '两点间的距离:',d
