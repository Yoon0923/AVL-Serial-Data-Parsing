# AVL-Serial-Data-Parsing
Name: Yoonsu Cho 
Major: Computer Engineering
Board Used: Arduino Uno Rev3
# Project 3 - Serial Data Parsing
# 1. Project Overview:

The goal of this project was to design and implement a simple serial command interface using the Arduino Uno. The system receives structured commands in the format KEY:VALUE through serial communication and executes corresponding actions, such as turning LEDs on/off or flashing them for a user-defined duration.

# 2. System Overview:

- The system structure is as follows:
	User Command Input (Serial Monitor)
		↓
	Serial Data Reception 
		↓
	Arduino Microcontroller (Command Parsing)
		↓
	Execution Logic
		↓
	Digital Output (LED)

- Execution follows:
1. A command is entered in the Serial Monitor.
2. Serial input is buffered character by character until a newline character indicates the end of a complete command.
3. When a newline character \n is detected, the full command string is considered complete.
4. The command is parsed by separating the key and value using ‘ : ‘ delimiter.
5. The corresponding action is executed.
6. A response message is sent back to the Serial Monitor.


# 3. Implemented Commands:

LED:ON - Turn LED on
LED:OFF - Turn LED off
STATUS:GET - Display the current LED state
BLINK:<milliseconds> - Blink the LED for the specified duration

Example Commands: 
LED:ON
STATUS:GET
BLINK:1000
# 4. Implementation Summary:

The system reads serial input character-by-character and stores it in a buffer until a newline character is detected. The command is then parsed by separating the key and value using a delimiter. Based on the parsed result, the corresponding LED action is executed.

# 5. Development Challenges:

I discovered that the toInt() function returns 0 when the input is not a valid number. To address this, implemented input validation to ensure only positive values are accepted for the BLINK command.

# 6. Demonstration:
