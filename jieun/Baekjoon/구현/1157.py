s = input().lower()
set_li = list(set(s))
cnt = []
for i in set_li:
    cnt.append(s.count(i))
if cnt.count(max(cnt))>=2:
    print('?')
else:
    print(set_li[cnt.index(max(cnt))])