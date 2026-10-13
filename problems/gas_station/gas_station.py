def canCompleteCircuit(gas: list[int], cost: list[int]) -> int:
    if sum(gas) < sum(cost):
        return -1

    start_idx = 0
    total = 0
    for idx in range(len(gas)):
        total += gas[idx] - cost[idx]
        if total < 0:
            start_idx = idx + 1
            total = 0

    return start_idx
