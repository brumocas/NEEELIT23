import tkinter as tk
import serial.tools.list_ports

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portList = []

for onePort in ports:
    portList.append(str(onePort))
    print(str(onePort))

val = 5



'''
for i in range(0,len(portList)):
    if portList[i].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
'''

serialInst.baudrate = 115200
serialInst.port = "COM5"
serialInst.open()


def update_angle1():
    serialInst.write(("b" + str(int(slider1.get()))).encode())

def update_angle2():
    serialInst.write(("s" + str(int(slider2.get()))).encode())

def update_angle3():
    serialInst.write(("e" + str(int(slider3.get()))).encode())

def update_angle4():
    serialInst.write(("w" + str(int(slider4.get()))).encode())

def update_angle5():
    serialInst.write(("g" + str(int(slider5.get()))).encode())

def set_crab_animation():
    serialInst.write("C".encode())

def set_hello_animation():
    serialInst.write("H".encode())

def set_special_animation():
    serialInst.write("S".encode())

root = tk.Tk()
root.title("Robot Arm Control")

slider1 = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, label="", length=300, highlightthickness=0, bd=0, sliderlength=20, troughcolor='#ddd', activebackground='#aaa')
slider1.grid(row=0, column=0, padx=10, pady=10)

slider2 = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, label="", length=300, highlightthickness=0, bd=0, sliderlength=20, troughcolor='#ddd', activebackground='#aaa')
slider2.grid(row=1, column=0, padx=10, pady=10)

slider3 = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, label="", length=300, highlightthickness=0, bd=0, sliderlength=20, troughcolor='#ddd', activebackground='#aaa')
slider3.grid(row=2, column=0, padx=10, pady=10)

slider4 = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, label="", length=300, highlightthickness=0, bd=0, sliderlength=20, troughcolor='#ddd', activebackground='#aaa')
slider4.grid(row=3, column=0, padx=10, pady=10)

slider5 = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, label="", length=300, highlightthickness=0, bd=0, sliderlength=20, troughcolor='#ddd', activebackground='#aaa')
slider5.grid(row=4, column=0, padx=10, pady=10)

button1 = tk.Button(root, text="Update Angle 1", command=update_angle1, bg='#0000ff', fg='#fff', activebackground='#3e8e41')
button1.grid(row=0, column=1, padx=10, pady=10)

button2 = tk.Button(root, text="Update Angle 2", command=update_angle2, bg='#0000ff', fg='#fff', activebackground='#3e8e41')
button2.grid(row=1, column=1, padx=10, pady=10)

button3 = tk.Button(root, text="Update Angle 3", command=update_angle3, bg='#ff0000', fg='#fff', activebackground='#3e8e41')
button3.grid(row=2, column=1, padx=10, pady=10)

button4 = tk.Button(root, text="Update Angle 4", command=update_angle4, bg='#ff0000', fg='#fff', activebackground='#3e8e41')
button4.grid(row=3, column=1, padx=10, pady=10)

button5 = tk.Button(root, text="Update Angle 5", command=update_angle5, bg='#4CAF50', fg='#fff', activebackground='#3e8e41')
button5.grid(row=4, column=1, padx=10, pady=10)

button6 = tk.Button(root, text="Hello Animation", command=set_hello_animation, bg='#4CAF50', fg='#fff', activebackground='#3e8e41')
button6.grid(row=5, column=0, padx=10, pady=10)

button7 = tk.Button(root, text="Crab Animation", command=set_crab_animation, bg='#4CAF50', fg='#fff', activebackground='#3e8e41')
button7.grid(row=6, column=0, padx=10, pady=10)

button8 = tk.Button(root, text="Special Animation", command=set_special_animation, bg='#4CAF50', fg='#fff', activebackground='#3e8e41')
button8.grid(row=7, column=0, padx=10, pady=10)


# SET THE INIT ANGLE VALUES OF THE SERVOS
slider1.set(0)
slider2.set(70)
slider3.set(90)
slider4.set(45)
slider5.set(0)

root.mainloop()

