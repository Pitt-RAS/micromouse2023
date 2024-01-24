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

    def fill(self, map):
        marray = bin(int(map, 16))[2:].zfill(1024)
        print(str(marray))
        for col in range(0, 16):
            for row in range(0, 16):
                offset = col * 64 + row * 4
                self.data[row][col].setWalls([bool(int(marray[offset])), bool(int(marray[offset + 1])), bool(int(marray[offset + 2])), bool(int(marray[offset + 3]))])
        print("Dat0: {}".format(str(self.data[0][0].getWalls())))
        print("Dat1: {}".format(str(self.data[0][1].getWalls())))
        print("Dat11: {}".format(str(self.data[1][0].getWalls())))
