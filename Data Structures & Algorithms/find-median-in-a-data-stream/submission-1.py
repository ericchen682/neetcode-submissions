import bisect

class MedianFinder:

    def __init__(self):
        self.sz = 0
        self.arr = []

    def addNum(self, num: int) -> None:
        self.sz += 1
        bisect.insort(self.arr, num)

    def findMedian(self) -> float:
        if self.sz % 2 == 1:
            return self.arr[self.sz//2]
        return (self.arr[self.sz//2 - 1] + self.arr[self.sz//2 ])/2
        