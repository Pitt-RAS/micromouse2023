import tkinter as tk
import serial



useSerial = False
if useSerial:
    ser = serial.Serial('COM12', 115200, timeout=0.1)

class Mouse:
    def __init__(self, canvas, color, size, x, y, dx, dy):
        self.canvas = canvas
        self.color = color
        self.size = size
        self.x = x
        self.y = y
        self.dx = dx
        self.dy = dy
        self.ball = canvas.create_oval(x-size, y-size, x+size, y+size, fill=color)
        self.line = canvas.create_line(x,y,x,y+(2*size),fill=color,arrow=tk.LAST)

    def move(self):
        
        if(useSerial):
            try:
                data = int(ser.readline().decode().strip())
                #print(data)
                print(data % 1000)
                self.canvas.moveto(self.ball, data%1000, self.dy)
            except Exception as e:
                print(e)


class App:
    def __init__(self, master):
        self.master = master
        self.canvas = tk.Canvas(master, width=800, height=800)
        self.canvas.pack()
        self.ball = Mouse(self.canvas, "red", 10, 200, 200, 0, 0)
        self.update()

    def update(self):
        self.ball.move()
        self.master.after(15, self.update)

root = tk.Tk()
app = App(root)
root.mainloop()