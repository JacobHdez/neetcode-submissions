class DynamicArray:
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.data = [None] * capacity

    def get(self, i: int) -> int:
        return self.data[i]

    def set(self, i: int, n: int) -> None:
        if self.data[i] is None:
            self.size += 1
        self.data[i] = n

    def pushback(self, n: int) -> None:
        if self.capacity == self.size:
            self.resize()
        self.data[self.size] = n
        self.size += 1

    def popback(self) -> int:
        self.size -= 1
        v = self.data[self.size]
        self.data[self.size] = None
        return v

    def resize(self) -> None:
        self.data += [None] * self.capacity
        self.capacity *= 2

    def getSize(self) -> int:
        return self.size
    
    def getCapacity(self) -> int:
        return self.capacity
