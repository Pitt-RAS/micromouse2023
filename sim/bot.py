from maze import Maze
from node import Node

class Bot:
    def __init__(self, maze, page, size):
        self.terrain = maze
        self.coords = [0, 0]
        self.face = 0
        self.page = page
        self.tileSize = size

    # Move the bot forwards in the direction it is facing
    def Go(self):
        match self.face:
            case 0:
                self.coords[1] += 1
                self.page.move(self.page.robot, 0, self.tileSize)
            case 1:
                self.coords[0] += 1
            case 2:
                self.coords[1] -= 1
            case _:
                self.coords[0] -= 1

    # Turn the bot either 90 deg right (cw = True) or 90 deg left (cw = False)
    def Turn(self, cw):
        if cw:
            self.face += 1
        else:
            self.face -= 1
        if self.face < 0:
            self.face = 3
        if self.face > 3:
            self.face = 0

    # Returns True if the bot is facing a wall and false if not
    def Peer(self):
        match self.face:
            case 0:
                return self.terrain.data[self.coords[0]][self.coords[1] + 1].getSouth()
            case 1:
                return self.terrain.data[self.coords[0] + 1][self.coords[1]].getWest()
            case 2:
                return self.terrain.data[self.coords[0]][self.coords[1] - 1].getNorth()
            case _:
                return self.terrain.data[self.coords[0] - 1][self.coords[1]].getEast()
