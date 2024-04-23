import tkinter as tk
import serial
import math
import matplotlib.pyplot as plt
import numpy as np
from tkinter import *
from matplotlib import pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


useSerial = True
if useSerial:
    ser = serial.Serial('COM14', 230400, timeout=0.1)


root = tk.Tk()
root.geometry('1200x700+200+100')
root.title('Motor PID Tuner')
root.state('zoomed')
root.config(background='#fafafa')

xar = []
yar = []

targetVelocity = []

style.use('ggplot')
fig = plt.figure(figsize=(14, 4.5), dpi=100)
ax1 = fig.add_subplot(1, 1, 1)
ax1.set_ylim(-100, 100)
line, = ax1.plot(xar, yar, 'r')
ax1.set_xticklabels([])
line2, = ax1.plot(xar, targetVelocity, 'b')
#ser = serial.Serial('com3', 9600)

velocitySlider = Scale(root, from_= -1, to=1, orient=HORIZONTAL, digits=3, resolution = 0.01, width=30, length=200)
velocitySlider.grid(column=0, row=2)



def animate(i):

    #ser.reset_input_buffer()
    #data = ser.readline().decode("utf-8")
    #data_array = data.split(',')
    #yvalue = float(data_array[1])
    #ser.reset_input_buffer()
    ser.flush()
    try:
        velocity = float(ser.readline().decode())
    except Exception as e:
        pass
    yar.append(velocity*100)


    xar.append(i)

    targetVelocity.append(velocitySlider.get() * 100)
    
    line.set_data(xar, yar)
    line2.set_data(xar, targetVelocity)
    ax1.set_xlim(i-100, i+1)

    try:
        p = float(PtextBox.get("1.0",END))
        i = float(ItextBox.get("1.0",END))
        d = float(DtextBox.get("1.0",END))
        f = float(FtextBox.get("1.0",END))
        setVelocity = velocitySlider.get()

        #print(f'{p}|{i}|{d}|{f}|{setVelocity}')

        #ser.write(f'{p}|{i}|{d}|{f}|{setVelocity}\n'.encode('utf-8'))

    except Exception as e:
        pass


plotcanvas = FigureCanvasTkAgg(fig, root)
plotcanvas.get_tk_widget().grid(column=0, row=1)
ani = animation.FuncAnimation(fig, animate, interval=20, blit=False)

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

'''def updatePID():
    p = float(PtextBox.get("1.0",END))
    i = float(ItextBox.get("1.0",END))
    d = float(DtextBox.get("1.0",END))
    f = float(FtextBox.get("1.0",END))

    print("{p}|{i},d,f")'''


#updateButton = Button(PIDgrid, text="Update PID", command=updatePID)
#updateButton.grid(column=8,row=0)

root.mainloop()