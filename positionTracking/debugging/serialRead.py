import serial

def readserial(comport, baudrate):

    ser = serial.Serial('COM12', 9600, timeout=0.1)        

    while True:
        data = ser.readline().decode().strip()
        if data:
            print(data)


if __name__ == '__main__':

    readserial('COM12', 9600)