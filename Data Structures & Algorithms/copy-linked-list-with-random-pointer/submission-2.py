"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        nodes = {None: None}
        temp = head
        while temp is not None:
            nodes[temp] = Node(temp.val)
            temp = temp.next
        temp = head
        while temp is not None:
            nodes[temp].next = nodes[temp.next]
            nodes[temp].random = nodes[temp.random]
            temp = temp.next
        return nodes[head]