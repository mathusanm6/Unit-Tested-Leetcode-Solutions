import random


class RandomizedSet:
    def __init__(self) -> None:
        self.arr: list[int] = []  # dense array
        self.map: dict[int, int] = {}  # val -> idx

    def insert(self, val: int) -> bool:
        if val in self.map:
            return False
        self.map[val] = len(self.arr)
        self.arr.append(val)
        return True

    def remove(self, val: int) -> bool:
        idx = self.map.pop(val, None)  # lookup + delete in one step
        if idx is None:
            return False
        last = self.arr.pop()
        if idx != len(self.arr):
            self.arr[idx] = last
            self.map[last] = idx
        return True

    def getRandom(self) -> int:
        return self.arr[random.randrange(len(self.arr))]
