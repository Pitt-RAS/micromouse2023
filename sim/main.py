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

    # Prepare the tkinter window
    root = Tk()
    root.title("Generic Window")
    root.geometry('1536x864')
    maze = Maze()
    data = maze.data
    #maze.fill("1B1B656949C9DEAE8D7B9ACD397B3B70535EAF76366503AE348EE82F2E815295863DA7336649BFBB48B61FCBD7735E9F13BACC8D79E5D629F9CADC576B904676176D673EFBB81E7F6E3D01C80CE48E70AD4D8334BF9D340720BAEBFF7F908FC8C6526031558DAE38980C9167648232361AC6CAC2BD8F4234668998F4E8E08594")
    print("Maze[0][0]: {}".format(str(maze.data[0][0])))
    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    print("Width: " + str(width) + ", height " + str(height))
    canvas = Canvas(root, bg="white", height=height, width=width)
    canvas.pack()

    # Find the center of the window
    # Then, finds the bottom left corner of the maze
    wmap = round(width / tileSize)
    hmap = round(height / tileSize)
    center = [round(width / 2), round(height / 2)]
    bot = [center[0] - (maze.w * .8 / 2 * tileSize), center[1] + (maze.h * .8 / 2 * tileSize)]
    print("Center: " + str(center))
    print("Bot: " + str(bot))

    # Create the maze based on the given "Maze" class data
    # Walls are stored in each node in a [0, 0, 0, 0] = N, E, S, W format
    # 1 = Wall is present, 0 = No wall present
    for i in range(0, maze.w):
        for j in range(0, maze.h):

            # Finds the bottom left corner of each individual tile to place walls
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
                canvas.create_text(corn[0] + tileSize / 2, corn[1] - tileSize / 2, text=(str(j) + ", " + str(i)),
                                   fill="black", font="Helvetica " + str(fontSize))
    cube = canvas.create_rectangle(bot[0] + 5, bot[1] - 5, bot[0] + 30, bot[1] - 30, fill="black")
    robot = Bot(maze, canvas, tileSize)


    # Define all necessary movement functions
    def tCCW(event):
        robot.Turn(0)


    def tCW(event):
        robot.Turn(1)


    def Action():
        if not robot.Peer():
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


    def mFwd(event):
        Action()


    def mBckwd(event):
        robot.unGo()
        Action()
        robot.unGo()


    def ScanUp(event):
        print("SCANNING >:)")


    # Binding all the movement commands

    root.bind("<Left>", tCCW)
    root.bind("<Right>", tCW)
    root.bind("<Up>", mFwd)
    root.bind("<Down>", mBckwd)
    root.bind("<Alt-Up>", ScanUp)
    root.bind("<Alt-Left>", ScanUp)
    root.bind("<Alt-Right>", ScanUp)
    root.mainloop()
