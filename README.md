# Volante-The-Gamepad
The new revolutionary joystick for car and flight simulation games.

&nbsp;

<p align="center">
<img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/out_box.jpg" width="550" height="400" />
</p>   

&nbsp;

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
   
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/touch_button_simple.PNG" width="200" height="200" />
      
      
   - [joystick_cap](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch/joystick_cap) - the code for the joystick with the capacitive buttons. The [TTP223](https://infusionsystems.com/support/TTP223.pdf) buttons go HIGH when pressed, the classic push normally open button go LOW when pressed. I not recomand to use the TTP223 for fast action and simulation games. The TTP223 sense a push by using an internal timer to feel the charge changing inside the capacitor. Due to this reason, it will reset after few second to LOW if keep pressed. The sensivity of the TTP223 is conditioned by the design of the touch button module and the object near it. It should switch to HIGH when not necessary giving a bad gaming experience. 
   
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/TTP223.PNG" width="200" height="200" />
   
  
   - [pin_test](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch/pin_test) - simple pin test on serial monitor
  
  
5. [kicad](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad) - the Kicad scheme and PCB project.

   - [buttons_layout](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/buttons_layout)
   
   - [buttons_layout_touch](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/buttons_layout_touch)
   
   - [lib](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/lib)
   
   - [shield](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/shield)
   
   - [shield_touch](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/shield_touch)
   
   - [touch_button_fancy](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/touch_button_fancy)
   
   - [touch_button_simple](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/touch_button_simple)

### Conclusion
This project is focused to design a new kind of joystick that make pleasant the racing and flight simulation gaming experience.
The joystick will provide a slider linear potentiometer (throttle/brake), two knobs potentiometers (up/down - left/right) and 15 buttons
The difference from the past is the presence of _linear potentiometers_ that give the possibility to the player to be absolutely precice with the movements.

#### Note
Don't worry if is not totally clear... you are smart and perfect. This project is still under development.

