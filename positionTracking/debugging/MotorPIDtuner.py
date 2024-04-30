import tkinter as tk
import serial
import math
import matplotlib.pyplot as plt
import numpy as np
from tkinter import *
from tkinter import ttk

backVar = 100
interval = 751//backVar

useSerial = True
if useSerial:
    ser = serial.Serial('COM14', 230400, timeout=0.1)

root = tk.Tk()
root.minsize(800,300)
root.maxsize(800,300)
root.title('Motor PID Tuner')
root.state('zoomed')
root.config(background='#fafafa')

actualVelocity = [(x, 100) for x in range(0, 751, interval)]

targetVelocity =  [(x, 100) for x in range(0, 751, interval)]

velocitySlider = Scale(root, from_= -1, to=1, orient=HORIZONTAL, digits=3, resolution = 0.01, width=30, length=200)
velocitySlider.grid(column=0, row=2)

plotcanvas = tk.Canvas(root, width=800, height=200)
plotcanvas.grid(column=0, row=1)

velLine = plotcanvas.create_line(targetVelocity, fill="blue", width = 2)
actualLine = plotcanvas.create_line(targetVelocity, fill="red", width = 2)

PIDgrid = Frame(root)
PIDgrid.grid(column=0, row=3)

Plabel = Label(PIDgrid, text = "P:")
PtextBox = Text(PIDgrid, height = 1, width = 10)
PtextBox.insert(END, "0")

Ilabel = Label(PIDgrid, text = "I:")
ItextBox = Text(PIDgrid, height = 1, width = 10)
ItextBox.insert(END, "0")

Dlabel = Label(PIDgrid, text = "D:")
DtextBox = Text(PIDgrid, height = 1, width = 10)
DtextBox.insert(END, "0")

Flabel = Label(PIDgrid, text = "F:")
FtextBox = Text(PIDgrid, height = 1, width = 10)
FtextBox.insert(END, "0")


Plabel.grid(column=0,row=0)
PtextBox.grid(column=1,row=0)

Ilabel.grid(column=2,row=0)
ItextBox.grid(column=3,row=0)

Dlabel.grid(column=4,row=0)
DtextBox.grid(column=5,row=0)

Flabel.grid(column=6,row=0)
FtextBox.grid(column=7,row=0)



def update(tv, av):
    tv.pop(0)
    tv = list(map(lambda tup: (tup[0] - interval, tup[1]), tv))
    tv.append((740, int(-velocitySlider.get()*100 + 100)))

    av.pop(0)
    av = list(map(lambda tup: (tup[0] - interval, tup[1]), av))
    ser.flush()

    velocity = 0
    try:
        velocity = float(ser.readline().decode())
        av.append((740, int(-velocity*100 + 100)))

        
        print(f'<{velocitySlider.get()}>\n')
        #ser.write(f'<{velocitySlider.get()}>\n'.encode('utf-8'))
        p = float(PtextBox.get("1.0",END))
        i = float(ItextBox.get("1.0",END))
        d = float(DtextBox.get("1.0",END))
        f = float(FtextBox.get("1.0",END))
    
        ser.write(f'<{p}|{i}|{d}|{f}|{velocitySlider.get()}>\n'.encode('utf-8'))
    except Exception as e:
        pass
    
    plotcanvas.coords(velLine, [a for x in tv for a in x])
    plotcanvas.coords(actualLine, [a for x in av for a in x])
    

    root.after(1, update, tv, av)

root.after(1, update, targetVelocity, actualVelocity)
root.mainloop()