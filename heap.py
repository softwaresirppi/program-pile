from typing import *
# MAX heap
class Heap:
    def __init__(self):
        self.nodes = []

    def parent(self, i: int) -> int | None:
        if i == 0:
            return None # :(
        return int((i - 1) / 2)
    def left(self, i: int) -> int | None:
        left = i * 2 + 1
        if left < len(self.nodes):
            return left
        else:
            return None # :(
    def right(self, i: int) -> int | None:
        right = i * 2 + 2
        if right < len(self.nodes):
            return right
        else:
            return None # :(

    def top(self) -> int:
        return self.nodes[0]

    def put(self, x: int):
        self.nodes.append(x)
        me = len(self.nodes) - 1
        dad = self.parent(me)

        while dad != None and self.nodes[dad] < self.nodes[me]:
            # IF YOU ARE BAD, IM YOUR DAD
            self.nodes[me], self.nodes[dad] = self.nodes[dad], self.nodes[me]
            me = dad

            dad = self.parent(dad)

    def take(self):
        self.nodes[0] = self.nodes[-1]
        self.nodes.pop()

        me = 0

        left = self.left(me)
        right = self.right(me)
        print(f'[{left}] {me} [{right}]')
        while ((left != None and me != None and self.nodes[me] < self.nodes[left])
                or
               (right != None and me != None and self.nodes[me] < self.nodes[right])):
            print(f'[{left}] {me} [{right}]')
            if left != None and me != None and self.nodes[me] < self.nodes[left]:
                self.nodes[me], self.nodes[left] = self.nodes[left], self.nodes[me]
                me = left
            elif right != None and me != None and self.nodes[me] < self.nodes[right]:
                self.nodes[me], self.nodes[right] = self.nodes[right], self.nodes[me]
                me = right
            left = self.left(me)
            right = self.right(me)
