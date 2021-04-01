# DomusAurea-Home

The DomusAurea Domotic application
.
This set of Arduino programs are built to control the different elements in a Domotic installation.

It also will include a [Surveillance Robot](https://github.com/HuanLuRobotics/DomusAurea-Assistant) application to handle the supervision of the house

Rules (for Security purpose):

- NO doors will be controlled
- Preferibly, using X10 protocol and not Wifi protocol to join the elements with the panel
  
The "DomusAurea Home" is part of the "DomusAurea" platform

## Pre-Requisites

To develop the system for the project and upload to the Arduino Board (an Arduino Mega 2560 board), we are going to use VisualStudio Code instead the Arduino IDE.

The steps to configure the VisualStudio IDE are:

- Install the Arduino Extension (and the C/C++ extension that is also suggested)
- Set the Board (Ctrl-Shift-P and then select Arduino:Board Manager and Arduino:Board Configuration)
- Set the communication port (COM3 or COM1)
- Get the Blink.ino example to test the correct communication and installation
