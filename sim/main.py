# This is a sample Python script.
from tkinter import *
from numpy import *
from maze import Maze

tileSize = 50

if __name__ == '__main__':
    root = Tk()
    root.title("Generic Window")
    root.geometry('1920x1080')
    maze = Maze()
    lbl = Label(root, text=("W = " + str(maze.w) + ", H = " + str(maze.h)))
    lbl.grid()
    canvas = Canvas()
    data = maze.data
    width = root.winfo_width()
    height = root.winfo_height()
    wmap = round(width / tileSize)
    hmap = round(height / tileSize)
    center = [round(width / 2), round(height / 2)]
    bot = [center - (maze.w / 2 * tileSize), center - (maze.h / 2 * tileSize)]
    for i in range(0, maze.w):
        for j in range(0, maze.h):
            corn = [bot[0] + (i * tileSize), bot[1] + (j * tileSize)]
            if(data[i][j])
    root.mainloop()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
