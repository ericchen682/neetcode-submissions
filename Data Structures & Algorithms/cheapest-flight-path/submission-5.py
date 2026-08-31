class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # determine cheapest we can get to any airport at any time < k
        curr_cheapest_price = [-1] * n
        curr_cheapest_price[src] = 0
        next_cheapest_price = [-1] * n
        for i in range(k + 1):
            next_cheapest_price = curr_cheapest_price.copy()
            for u, v, price in flights:
                if curr_cheapest_price[u] == -1:
                    continue
                elif next_cheapest_price[v] == -1:
                    next_cheapest_price[v] = curr_cheapest_price[u] + price
                else:
                    next_cheapest_price[v] = min(next_cheapest_price[v], curr_cheapest_price[u] + price)
            curr_cheapest_price = next_cheapest_price
        return next_cheapest_price[dst]


