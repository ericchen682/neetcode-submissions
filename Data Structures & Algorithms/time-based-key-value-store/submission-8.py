class TimeMap:

    def __init__(self):
        self.store = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store[key].append((value, timestamp));

    def get(self, key: str, timestamp: int) -> str:
        arr = self.store.get(key)
        if not arr or arr[0][1] > timestamp:
            return ""
        l = 0
        r = len(arr) - 1
        while l < r:
            mid = l + (r - l + 1) // 2
            if arr[mid][1] <= timestamp:
                l = mid
            else:
                r = mid - 1
        return arr[l][0]
