#coding=utf-8
score=[70,90,78,85,97,94,65,80]
score_max=score[0]
score_min=score[0]
print'所有分数值是:'
for i in score:
	print(i),
	if i > score_max:
		score_max=i
	if i < score_min:
		score_min=i
print'\n'
print '最高分=',score_max
print'最低分=',score_min
