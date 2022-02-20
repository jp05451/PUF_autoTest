---
This is the sampling part of PUF (physically unclonable function), using arduino mega and cy62256nll.
It is running on VScode with platformio.
---

# Board setting up

pin_ar represents pin number in arduino mega
pin_cy represents pin number in cy62256nll

- selection line

  - pin_ar 2 to pin_cy 21 (A0)
  - pin_ar 3 to pin_cy 23 (A1)
  - pin_ar 4 to pin_cy 24 (A2)
  - pin_ar 5 to pin_cy 25 (A3)
  - pin_ar 6 to pin_cy 26 (A4)
  - pin_ar 22 to pin_cy 1 (A5)
  - pin_ar 24 to pin_cy 2 (A6)
  - pin_ar 26 to pin_cy 3 (A7)
  - pin_ar 28 to pin_cy 4 (A8)
  - pin_ar 30 to pin_cy 5 (A9)
  - pin_ar 32 to pin_cy 6 (A10)
  - pin_ar 34 to pin_cy 7 (A11)
  - pin_ar 36 to pin_cy 8 (A12)
  - pin_ar 38 to pin_cy 9 (A13)
  - pin_ar 40 to pin_cy 10 (A14)

- data line

  - pin_ar A0 to pin_cy 11 (I/O0)
  - pin_ar A1 to pin_cy 12 (I/O1)
  - pin_ar A2 to pin_cy 13 (I/O2)
  - pin_ar A3 to pin_cy 15 (I/O3)
  - pin_ar A4 to pin_cy 16 (I/O4)
  - pin_ar A5 to pin_cy 17 (I/O5)
  - pin_ar A6 to pin_cy 18 (I/O6)
  - pin_ar A7 to pin_cy 19 (I/O7)

- control

  - pin_ar 52 to pin_cy 27 (WE)
  - pin_ar 48 to pin_cy 20 (CE)
  - pin_ar 50 to pin_cy 22 (OE)

- power supply

  - pin_ar 5V to pin_cy 28 (VCC)
  - ground
    pin_ar GND to pin_cy 14 (GND)

# Select port

1. Connect your arduino mega to your computer
2. Open PIO home in VScode, and you can find the correct port from devices
3. Copy the port name
4. Replace the upload_port in platformio.ini with the correct port name

# Run

1. Press upload button after select the correct port
2. Open serial monitor
3. Now you can observe the result in the terminal
