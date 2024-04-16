minus_splt = input().split('-')
plus_splt = ([i.split('+') for i in minus_splt])

li = []
for i in plus_splt:
    i_sum = sum(int(num) for num in i)
    li.append(i_sum)

print(-sum(li[1:])+li[0])