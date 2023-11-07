import numpy as np


class Node:
    def __init__(self, x, y):
        self.walls = np.array([False, False, False, False])
        self.explored = False
        self.children = []
        self.x, self.y = x, y

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

    def getExplored(self):
        return self.explored

    def setExplored(self, dat):
        self.explored = dat

    def __eq__(self, __value: object) -> bool:
        if self.x == __value.x and self.y == __value.y:
            return True
        else:
            return False