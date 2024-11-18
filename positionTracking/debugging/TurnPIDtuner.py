import tkinter as tk
import serial
import math
import matplotlib.pyplot as plt
import numpy as np
from tkinter import *
from tkinter import ttk

useSerial = True
if useSerial:
    ser = serial.Serial('COM14', 230400, timeout=0.1)

root = tk.Tk()
root.minsize(800,300)
root.maxsize(800,300)
root.title('Turn PID Tuner')
root.state('zoomed')
root.config(background='#fafafa')

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

def sendTurn():
    ser.flush()
    try:
        p = float(PtextBox.get("1.0",END))
        i = float(ItextBox.get("1.0",END))
        d = float(DtextBox.get("1.0",END))
        
        ser.write(f'<{p}|{i}|{d}|1>\n'.encode('utf-8'))

    except Exception as e:
        print(e)

Fbutton = Button(PIDgrid, text = "Turn", command=sendTurn)



Plabel.grid(column=0,row=0)
PtextBox.grid(column=1,row=0)

Ilabel.grid(column=2,row=0)
ItextBox.grid(column=3,row=0)

Dlabel.grid(column=4,row=0)
DtextBox.grid(column=5,row=0)
Fbutton.grid(column=6,row=0)


def update():
    ser.flush()
    try:

        #ser.write(f'<{velocitySlider.get()}>\n'.encode('utf-8'))
        p = float(PtextBox.get("1.0",END))
        i = float(ItextBox.get("1.0",END))
        d = float(DtextBox.get("1.0",END))

        print(ser.readline().decode())
        ser.write(f'<{p}|{i}|{d}|0>\n'.encode('utf-8'))
    except Exception as e:
        pass
    
    root.after(1, update)
#
root.after(1, update)
root.mainloop()