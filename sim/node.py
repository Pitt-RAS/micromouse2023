import numpy as np


class Node:
    def __init__(self):
        self.walls = np.array([False, False, False, False])
        self.explored = False

    def getNorth(self):
        return self.walls[0]

    def getEast(self):
        return self.walls[1]

    def getSouth(self):
        return self.walls[2]

    def getWest(self):
        return self.walls[3]

    def setNorth(self, val):
        self.walls[0] = val

    def setEast(self, val):
        self.walls[1] = val

    def setSouth(self, val):
        self.walls[2] = val

    def setWest(self, val):
        self.walls[3] = val

    def getWalls(self):
        return self.walls

    def setWalls(self, dat):
        self.walls = dat

    def getData(self):
        return self.walls

    def getExplored(self):
        return self.explored

    def setExplored(self, dat):
        self.explored = dat

