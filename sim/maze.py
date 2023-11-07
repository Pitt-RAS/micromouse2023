import node
import numpy as np


class Maze:
    def __init__(self):
        self.w = 16
        self.h = 16
        self.data = [[node.Node() for i in range(self.w)] for j in range(self.h)]
        for topRow in self.data[self.h-1]:
            topRow.setNorth(True)
        for botRow in self.data[0]:
            botRow.setSouth(True)
        for row in self.data:
            row[0].setWest(True)
            row[self.w-1].setEast(True)
        self.data[0][0].setSouth(False)
        self.entrance = self.data[0][0]
        self.data = np.array(self.data)
