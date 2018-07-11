# Volante-The-Gamepad
The new revolutionary joystick for car and flight simulation games.

### Software 
The code use the famous libray ```Joystick.h```. You can find some sketches still in testing [here](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch).
These are designed for the main project and for variants with different axis and buttons.
From the first testing seem to work only the ```JOYSTICK_TYPE_JOYSTICK``` configuration. Unfortunately seem that Microsoft has stop to support the HID human interface and only the basic function works. Still no solution for force feedback and particular multiaxis joystick.... now the more complex gaming simulation devices have their own drivers. You don't need the basic plug and play driver. Please have a look for the [HID architecture](https://docs.microsoft.com/en-us/windows-hardware/drivers/hid/) to understand and maybe help :)

### Hardware
The hardware consist in the joystick case, buttons, knobs, the [Arduino Pro Micro](https://www.sparkfun.com/products/12640) and the the shield module to interface the Arduino with the buttons and knobs. The module board is designed by using [KiCad](http://kicad-pcb.org/). [Here](https://oshpark.com/shared_projects/UvrbzbYx) you can find the PCB ready to print. This super cool service is provided by OSHPark.


### Directory structure
1. [ArduinoJoystickLibrary-master](https://github.com/mancio/Volante-The-Gamepad/tree/master/ArduinoJoystickLibrary-master) - the Joystick library written by [Matthew Heironimus](https://github.com/MHeironimus)

2. [Fritzing](https://github.com/mancio/Volante-The-Gamepad/tree/master/Fritzing) - The Fritzing project with a prototype on breadbord.

3. [Picture](https://github.com/mancio/Volante-The-Gamepad/tree/master/Picture) - some pictures for the Fritzing draft and the building process

4. [Volante sketch](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch) - the code
   - [joystick](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch/joystick) - the main code, the most tested. The sketch for the touch version of the Gamepad. The I/O pin are in PULLUP configuration. The PINs change to LOW when the finger or any not-hi-resistance organic object connect both the pad tracks. The finger and each resistor on the shield should be considered as a voltage devider. Your body has an internal resistance of 100 KOhm so the resistors on the shield should be 2 MOhm. You can use [this](http://www.ohmslawcalculator.com/voltage-divider-calculator) voltage devider calculator to calculate the resistor. The Arduino pin mosfets are LOW state when the input is about <= 2.5V. If you use a less conductive item to close the contacts of the pad maybe you will have to raise the resistance up to 20MOhm
   
   [pad](https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/touch_button_simple)
  
5. [kicad](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad) - the Kicad scheme and PCB project.

### Conclusion
This project is focused to design a new kind of joystick that make pleasant the racing and flight simulation gaming experience.
The joystick will provide a slider linear potentiometer (throttle/brake), two knobs potentiometers (up/down - left/right) and 15 buttons
The difference from the past is the presence of _linear potentiometers_ that give the possibility to the player to be absolutely precice with the movements.

#### Note
Don't worry if is not totaly clear... you are smart and perfect. This project is still on working.

