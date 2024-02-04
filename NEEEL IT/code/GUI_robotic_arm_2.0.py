import serial.tools.list_ports

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portList = []

for onePort in ports:
    portList.append(str(onePort))
    print(str(onePort))

val = input("Select Port: COM")

for i in range(0,len(portList)):
    if portList[i].startswith("COM" + str(val)):
        portVar = "COM" + str(val)

serialInst.baudrate = 115200
serialInst.port = portVar
serialInst.open()

BASE_ANGLE = 90
SHOULDER_ANGLE = 120
ELBOW_ANGLE = 45
WRIST_ANGLE = 40
GRIPPER_ANGLE = 0

while 1:

    angle = input('Input join and its rotation: \n')
    serialInst.write(angle.encode(('utf-8')))

    if angle == 'exit':
        exit()