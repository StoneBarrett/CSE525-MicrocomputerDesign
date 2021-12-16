from playsound import playsound
import threading
import random
import time
from rpi_ws281x import PixelStrip, Color
from pathlib import Path



# LED strip configuration:
LED_COUNT = 59        # Number of LED pixels.
LED_PIN = 21        # GPIO pin connected to the pixels (10 uses SPI /dev/spidev0.0).
LED_FREQ_HZ = 800000  # LED signal frequency in hertz (usually 800khz)
LED_DMA = 10       # DMA channel to use for generating signal (try 10)
LED_BRIGHTNESS = 255  # Set to 0 for darkest and 255 for brightest
LED_INVERT = False    # True to invert the signal (when using NPN transistor level shift)
LED_CHANNEL = 0       # set to '1' for GPIOs 13, 19, 41, 45 or 53

# Method for making list entries based on file line by line
def readFreqs(filepath):
    p = Path(__file__).with_name(filepath)
    with p.open('r') as f:
        frequencies = f.readlines()
    
    return frequencies

def ColorChange(strip, color):
    """Wipe color across display a pixel at a time."""
    for i in range(strip.numPixels()):
        strip.setPixelColor(i, color)
    strip.show()

def PlayMusic(song):
    FileName = song + ".wav"
    playsound(FileName)

def TranslateColor(string):
    if string == "white\n":
        return Color(255,255,255)
    if string == "green\n":
        return Color(0,255,0)
    if string == "red\n":
        return Color(255,0,0)
    else: print("invalid color")

def LightShow(song):
    fileName = song + ".txt"
    strip = PixelStrip(LED_COUNT, LED_PIN, LED_FREQ_HZ, LED_DMA, LED_INVERT, LED_BRIGHTNESS, LED_CHANNEL)
# Intialize the library (must be called once before other functions).
    strip.begin()

    # Making list based on file passed
    frequencies = readFreqs(fileName)
    UpdatesPerSec = int(frequencies[0])
    WaitTime = 1/UpdatesPerSec

    SongThread = threading.Thread(target=PlayMusic, args=(song,))
    SongThread.start()
    for i in range(1,len(frequencies)):
        NewColor = TranslateColor(frequencies[i])
        ColorChange(strip,NewColor)
        time.sleep(WaitTime)

    SongThread.join()

PrevSong = "None"
Songs = ["RockinAroundTheChristmasTree","HappyXmas","allIWantForChristmasIsYou","HotChocolateFromThePolarExpress"]

# for i in range(0,10):
#     NextSong = random.choice(Songs)
#     while NextSong == PrevSong: NextSong = random.choice(Songs)
#     print("Playing :",NextSong)
#     LightShow(NextSong)
#     PrevSong = NextSong

for song in Songs:
    print("Playing :",song)
    LightShow(song)