from playsound import playsound
from scipy.io import wavfile
import numpy as np
from numpy import diff, negative, savetxt
import time
updatesPerSec = 20
difRange = 5000
FileName = "allIWantForChristmasIsYou"
AudioName = FileName + ".wav" # Audio File
OutputFile = FileName + ".txt"
fs, Audiodata = wavfile.read(AudioName)


current = 0
NewDataLeft = []
NewDataRight = []
stepVariable = round(fs/updatesPerSec)

while current < (len(Audiodata)-fs):
    current += stepVariable
    NewDataLeft.append(Audiodata[current][0])
    NewDataRight.append(Audiodata[current][1])


ListMax = int(max(NewDataLeft))
ListMin = int(min(NewDataLeft))

Total = int(ListMax) - int(ListMin)

section = Total/3
subSection = section/2

MidRange = (subSection,negative(subSection))
MaxRange = (ListMax,MidRange[0])
MinRange = (MidRange[1]-1,ListMin)

colorList = []
outFile = open(OutputFile,"w+")
outFile.write(str(updatesPerSec))
outFile.write("\n")

colors = ["red","white","green"]
colorIndex = 0
NeedChange = True
PrevValue = NewDataLeft[0]

for items in range(0,len(NewDataLeft)):
    if NeedChange == True:
        colorValue = colors[colorIndex]
        if colorIndex == 2:
            colorIndex = 0
        else:
            colorIndex +=1
    NeedChange = False
    Current = NewDataLeft[items]
    dif = abs(Current) - abs(PrevValue)
    if abs(dif) > difRange:
        NeedChange = True
    PrevValue = Current
    colorList.append(colorValue)
    outFile.write(colorValue)
    outFile.write("\n")


outFile.close()


