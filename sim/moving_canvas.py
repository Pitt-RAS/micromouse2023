import tkinter as tk


class MovingCanvas(tk.Canvas):

    def __init__(self, tileSize, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.dx = 0
        self.dy = 0
        self.dt = 25
        self.bot = None
        self.moveSize = tileSize
        self.Tick()

    # MUST BE CALLED BEFORE mainloop, links the bot to the graphic
    def Link(self, linker):
        self.bot = linker

    def Tick(self):
        # Run the bot's main loop
        command = input("Please Enter Command: ")
        match command:
            case "t0":
                self.bot.Turn(True)
                print("Turned CW")
            case "t1":
                self.bot.Turn(False)
                print("Turned CCW")
            case "p":
                print("Peered: " + str(self.bot.Peer()))
            case _:
                match self.bot.face:
                    case 0:
                        self.move(self.bot, 0, -1 * self.moveSize)
                    case 1:
                        self.move(self.bot, self.moveSize, 0)
                    case 2:
                        self.move(self.bot, 0, self.moveSize)
                    case _:
                        self.move(self.bot, -1 * self.moveSize, 0)
                self.bot.Go()
                print("Went to {}, {}".format(self.bot.coords[0], self.bot.coords[1]))

        self.after(100, self.Tick)


