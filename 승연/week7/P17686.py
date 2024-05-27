def solution(files):
    file = []
    for i in files:
        headidx = -1
        tailidx = len(i)

        for j in range(len(i)):
            if i[j].isdigit():
                headidx = j
                break

        for j in range(headidx + 1, len(i)):
            if not i[j].isdigit():
                tailidx = j
                break

        if tailidx == -1:
            tail = []
            num = i[headidx:]
        else:
            tail = i[tailidx:]
            num = i[headidx:tailidx]

        head = i[:headidx]
        file.append([head, num, tail])

    file.sort(key=lambda x: (x[0].lower(), int(x[1])))

    for i in range(len(file)):
        file[i] = file[i][0] + file[i][1] + file[i][2]

    return file
