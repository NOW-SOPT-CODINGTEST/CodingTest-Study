from collections import deque


def solution(bridge_length, weight, truck_weights):
    bridge = [0] * bridge_length
    Q = deque(bridge)
    time = 0
    arrivedTrucks = 0
    bridgeWeight = 0
    i = 0

    while arrivedTrucks < len(truck_weights):
        # 트럭 빼기
        if Q[0] != 0:
            bridgeWeight -= Q.popleft()
            arrivedTrucks += 1
        else:
            Q.popleft()

        # 다리에 트럭 넣기
        if (
            i < len(truck_weights)
            and bridgeWeight + truck_weights[i] <= weight
            and len(Q) - Q.count(0) < bridge_length
        ):
            Q.append(truck_weights[i])
            bridgeWeight += truck_weights[i]
            i += 1
        else:
            Q.append(0)
        time += 1
    return time
