import tkinter as tk
import serial
import math


useSerial = True
if useSerial:
    ser = serial.Serial('COM14', 230400, timeout=0.1)

class Mouse:
    def __init__(self, canvas, color, size, x, y, dx, dy):
        self.size = size
        self.canvas = canvas
        self.color = color
        self.size = size
        self.x = x
        self.y = y
        self.dx = dx
        self.dy = dy
        self.ball = canvas.create_oval(x-size, y-size, x+size, y+size, fill=color)
        self.line = canvas.create_line(x,y,x,y+(2*size),fill=color,arrow=tk.LAST, width = self.size)

    def parse_input(self, input_string):
        variables = {}
        values = input_string.split('|')
        variables["x"] = float(values[0])
        variables["y"] = float(values[1])
        variables["theta"] = float(values[2])
        return variables

    def move(self):
        
        if(useSerial):
            try:
                #data = int(ser.readline().decode().strip())
                serialData = ser.readline().decode()

                position = self.parse_input(serialData)

                #print(data)
                #print(data % 1000)
                #print(position.get('x'),position.get('y'))
                self.canvas.moveto(self.ball, int(position.get('x'))-self.size, int(position.get('y'))-self.size)
                #self.canvas.moveto(self.line, int(position.get('x')), int(position.get('y')))
                x2 = self.size * 2 * math.cos(position.get('theta')) + position.get('x')
                y2 = self.size * 2 * math.sin(position.get('theta')) + position.get('y')

                self.canvas.coords(self.line, int(position.get('x')), int(position.get('y')), int(x2), int(y2))
            except Exception as e:
                print(e)


class App:
    def __init__(self, master):
        self.master = master
        self.canvas = tk.Canvas(master, width=800, height=800)
        self.canvas.pack()
        self.mouse = Mouse(self.canvas, "red", 20, 200, 200, 0, 0)
        self.update()

    def update(self):
        self.mouse.move()
        self.master.after(1, self.update)

root = tk.Tk()
app = App(root)
root.mainloop()