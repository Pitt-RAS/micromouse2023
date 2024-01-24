from maze import Maze
from node import Node
import time


class Bot:
    def __init__(self, maze, page, size):
        self.terrain = maze
        self.coords = [0, 0]
        self.face = 0
        self.page = page
        self.tileSize = size
        self.Moving = False
        self.Robot = None

    # Move the bot forwards in the direction it is facing
    def Go(self):
        match self.face:
            case 0:
                self.coords[1] += 1
            case 1:
                self.coords[0] += 1
            case 2:
                self.coords[1] -= 1
            case _:
                self.coords[0] -= 1
        print("{}, {}".format(self.coords[0], self.coords[1]))

    # Turns the bot 180 degrees around
    def unGo(self):
        match self.face:
            case 0:
                self.face = 2
            case 1:
                self.face = 3
            case 2:
                self.face = 0
            case _:
                self.face = 1


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
                print("{} and {}".format(self.terrain.data[self.coords[1]][self.coords[0]].getWalls(), self.terrain.data[self.coords[1] + 1][self.coords[0]].getWalls()))
                return self.terrain.data[self.coords[1] + 1][self.coords[0]].getSouth() or self.terrain.data[self.coords[1]][self.coords[0]].getNorth()
            case 1:
                return self.terrain.data[self.coords[1]][self.coords[0] + 1].getWest() or self.terrain.data[self.coords[1]][self.coords[0]].getEast()
            case 2:
                return self.terrain.data[self.coords[1] - 1][self.coords[0]].getNorth() or self.terrain.data[self.coords[1]][self.coords[0]].getSouth()
            case _:
                return self.terrain.data[self.coords[1]][self.coords[0] - 1].getEast() or self.terrain.data[self.coords[1]][self.coords[0]].getWest()

    def mainLoop(self):
        self.Moving = True
        while self.Moving:
            command = input("Please Enter Command: ")
            match command:
                case "t0":
                    self.Turn(True)
                    print("Turned CW")
                case "t1":
                    self.Turn(False)
                    print("Turned CCW")
                case "p":
                    print("Peered: " + str(self.Peer()))
                case _:
                    self.Go()
                    print("Went to {}, {}".format(self.coords[0], self.coords[1]))
            time.sleep(1)
