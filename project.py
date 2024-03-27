import speech_recognition as sr
import pyttsx3
from pyfirmata2 import Arduino, util
from threading import Timer

# Initialize Arduino board and pins
board = Arduino('COM3')
iterator = util.Iterator(board)
iterator.start()
pir_sensor = board.get_pin('d:12:i')
pin = board.get_pin('d:2:o')
pin2 = board.get_pin('d:5:o')

# Initialize speech recognition and text-to-speech engine
recognizer = sr.Recognizer()
engine = pyttsx3.init()

# Initialize variables to track the state of lights and timers
a = 0
b = 0
timer_a = None
timer_b = None
listening = False


# Function to print a message when motion is detected for LED1 (row 1)
def print_motion_detected_led1():
    print("\nMotion detected for LED1")


# Function to print a message when motion is detected for LED2 (row 2)
def print_motion_detected_led2():
    print("\nMotion detected for LED2")


# Callback function for handling changes in PIR sensor state
def pir_callback(value):
    global a, b, timer_a, timer_b
    if value:  # If motion is detected
        if a == 1:
            pin.write(1)  # Keep the light for row 1 on
            if timer_a:
                timer_a.cancel()  # Cancel the timer if motion is detected
                timer_a = None
            print_motion_detected_led1()  # Print motion detected message for LED1
        if b == 1:
            pin2.write(1)  # Keep the light for row 2 on
            if timer_b:
                timer_b.cancel()  # Cancel the timer if motion is detected
                timer_b = None
            print_motion_detected_led2()  # Print motion detected message for LED2
    else:
        if a == 1:
            timer_a = Timer(10, switch_off_light1)  # Set a timer to turn off light for row 1 after 10 seconds
            timer_a.start()
        if b == 1:
            timer_b = Timer(10, switch_off_light2)  # Set a timer to turn off light for row 2 after 10 seconds
            timer_b.start()


# Register callback for PIR sensor pin
pir_sensor.register_callback(pir_callback)


# Function to recognize speech input
def recognize_speech():
    global listening
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

    try:
        print("Recognizing...")
        text = recognizer.recognize_google(audio)
        print("Recognized text:", text)
        return text.lower().strip()
    except sr.UnknownValueError:
        print("Could not understand audio")
        return ""
    except sr.RequestError as e:
        print("Could not request results; {0}".format(e))
        return ""


# Function to switch on light for row 1
def switch_on_light1():
    global a
    print("Switching on light for row 1")
    engine.say("Switching on light for row 1")  # Speak the command
    engine.runAndWait()  # Wait for the speech to finish
    pin.write(1)
    a = 1


# Function to switch on light for row 2
def switch_on_light2():
    global b
    print("Switching on light for row 2")
    engine.say("Switching on light for row 2")  # Speak the command
    engine.runAndWait()  # Wait for the speech to finish
    pin2.write(1)
    b = 1


# Function to switch off light for row 1
def switch_off_light1():
    global a
    print("Switching off light for row 1")
    pin.write(0)
    a = 0


# Function to switch off light for row 2
def switch_off_light2():
    global b
    print("\nSwitching off light for row 2")
    pin2.write(0)
    b = 0


# Main execution loop
while True:
    engine.say("Please give a command.")
    engine.runAndWait()
    user_input = recognize_speech() if listening else input("Enter command: ")
    if user_input:
        if "start" in user_input:
            listening = True
        elif "stop" in user_input:
            listening = False
        elif listening:
            if "switch on" in user_input:
                if "row 1" in user_input:
                    if a == 0:  # Check if light for row 1 is already off
                        switch_on_light1()
                elif "row 2" in user_input:
                    if b == 0:  # Check if light for row 2 is already off
                        switch_on_light2()
                elif "all rows" in user_input:
                    if a == 0:
                        switch_on_light1()
                    if b == 0:                        switch_on_light2()
                else:
                    print("INVALID INPUT FOR ROW")
            elif "switch off" in user_input:
                if "row 1" in user_input:
                    switch_off_light1()
                elif "row 2" in user_input:
                    switch_off_light2()
                elif "all rows" in user_input:
                    switch_off_light1()
                    switch_off_light2()
            elif "terminate" in user_input:
                print("Terminating the program")
                pin.write(0)
                pin2.write(0)
                engine.say("Terminating the program")
                engine.runAndWait()
                break
