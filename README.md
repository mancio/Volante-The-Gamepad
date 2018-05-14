# Volante-The-Gamepad
The new revolutionary joystick for car and flight simulation games.

### Software 
The code use the famous libray ```Joystick.h```. You can find some sketches still in testing [here](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch).
These are designed for the main project and for variants with different axis and buttons.
From the first testing seem to work only the ```JOYSTICK_TYPE_JOYSTICK``` configuration. Unfortunately seem that Microsoft has stop to support the HID human interface and only the basic function works. Still no solution for force feedback and particular multiaxis joystick.... now the more complex gaming simulation devices have their own drivers. You don't need the basic plug and play driver. Please have a look for the [HID architecture](https://docs.microsoft.com/en-us/windows-hardware/drivers/hid/) to understand and maybe help :)

### Hardware
The hardware consist in the joystick case, buttons, knobs, the [Arduino Pro Micro](https://www.sparkfun.com/products/12640) and the the shield module to interface the Arduino with the buttons and knobs. The module board is designed by using [KiCad](http://kicad-pcb.org/). [Here](https://oshpark.com/shared_projects/UvrbzbYx) you can find the PCB ready to print. This super cool service is provided by OSHPark.


### Directory structure
[ArduinoJoystickLibrary-master](https://github.com/mancio/Volante-The-Gamepad/tree/master/ArduinoJoystickLibrary-master) - the Joystick library written by [Matthew Heironimus](https://github.com/MHeironimus)

[Fritzing](https://github.com/mancio/Volante-The-Gamepad/tree/master/Fritzing) - The Fritzing project with a prototype on breadbord.

[Picture](https://github.com/mancio/Volante-The-Gamepad/tree/master/Picture) - some pictures for the Fritzing draft and the building process

[Volante sketch](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch) - the code

[kicad](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad) - the Kicad scheme and PCB project.

### Conclusion
This project is focused to design a new kind of joystick that make pleasant the racing and flight simulation gaming experience.
The joystick will provide a slider linear potentiometer (throttle/brake), two knobs potentiometers (up/down - left/right) and 15 buttons
The difference from the past is the presence of _linear potentiometers_ that give the possibility to the player to be absolutely precice with the movements.

#### Note
Don't worry if is not totaly clear... you are smart and perfect. This project is still on working.

prova
