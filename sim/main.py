# This is a sample Python script.
from tkinter import *
from numpy import *
from maze import Maze
from bot import Bot
from node import Node

tileSize = 35
fontSize = int(tileSize / 5)
labels = True

if __name__ == '__main__':
    root = Tk()
    root.title("Generic Window")
    root.geometry('1536x864')
    maze = Maze()
    data = maze.data
    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    print("Width: " + str(width) + ", height " + str(height))
    canvas = Canvas(root, bg="white", height=height, width=width)
    canvas.pack()
    wmap = round(width / tileSize)
    hmap = round(height / tileSize)
    center = [round(width / 2), round(height / 2)]
    bot = [center[0] - (maze.w * .8 / 2 * tileSize), center[1] + (maze.h * .8 / 2 * tileSize)]
    print("Center: " + str(center))
    print("Bot: " + str(bot))

    for i in range(0, maze.w):
        for j in range(0, maze.h):
            # data[i][j].setWalls([1, 1, 1, 1])
            # print("Tile [" + str(i) + ", " + str(j) + "] Walls: " + str(data[i][j].walls))
            corn = [bot[0] + (j * tileSize), bot[1] - (i * tileSize)]

            if data[i][j].getNorth():
                canvas.create_line(corn[0], corn[1] - tileSize, corn[0] + tileSize, corn[1] - tileSize, fill="black")
            if data[i][j].getSouth():
                canvas.create_line(corn[0], corn[1], corn[0] + tileSize, corn[1], fill="black")
            if data[i][j].getEast():
                canvas.create_line(corn[0] + tileSize, corn[1], corn[0] + tileSize, corn[1] - tileSize, fill="black")
            if data[i][j].getWest():
                canvas.create_line(corn[0], corn[1], corn[0], corn[1] - tileSize, fill="black")
            if labels:
                canvas.create_text(corn[0] + tileSize / 2, corn[1] - tileSize / 2, text=(str(j) + ", " + str(i)), fill="black", font="Helvetica " + str(fontSize))
    cube = canvas.create_rectangle(bot[0] + 5, bot[1] - 5, bot[0] + 30, bot[1] - 30, fill="black")
    robot = Bot(maze, canvas, tileSize)

    def tCCW(event):
        robot.Turn(0)

    def tCW(event):
        robot.Turn(1)

    def mFwd(event):
        robot.Go()
        match robot.face:
            case 0:
                canvas.move(cube, 0, tileSize * -1)
            case 1:
                canvas.move(cube, tileSize, 0)
            case 2:
                canvas.move(cube, 0, tileSize)
            case _:
                canvas.move(cube, tileSize * -1, 0)

    def mBckwd(event):
        match robot.face:
            case 0:
                canvas.move(cube, 0, tileSize)
            case 1:
                canvas.move(cube, tileSize * -1, 0)
            case 2:
                canvas.move(cube, 0, tileSize * -1)
            case _:
                canvas.move(cube, tileSize, 0)

    def ScanUp(event):
        print("SCANNING >:)")

    root.bind("<Left>", tCCW)
    root.bind("<Right>", tCW)
    root.bind("<Up>", mFwd)
    root.bind("<Down>", mBckwd)
    root.bind("<Alt-Up>", ScanUp)
    root.bind("<Alt-Left>", ScanUp)
    root.bind("<Alt-Right>", ScanUp)
    root.mainloop()




