# Volante-The-Gamepad
The new revolutionary joystick for car and flight simulation games.

*(Design still in progress 😆)*

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

2. [Fritzing](https://github.com/mancio/Volante-The-Gamepad/tree/master/Fritzing) - The Fritzing project with a prototype on breadbord. A small sketch to give a basic idea.

3. [Picture](https://github.com/mancio/Volante-The-Gamepad/tree/master/Picture) - some pictures for the Fritzing design project and the building process

4. [Volante sketch](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch) - the code
   
   - [Volante](https://github.com/mancio/Volante-The-Gamepad/blob/master/Volante%20sketch/Volante/Volante.ino) - the main Arduino sketch. The sketch is design to be used with touch, capacitive and push buttons. The I/O pin can be in PULL-UP, PULL-DOWN or FLOAT configuration. 
      - The touch button design: The PINs change to LOW when the finger or any not-hi-resistance organic object connect both the pad tracks. The finger and each resistor on the shield should be considered part of a voltage devider. Your dry skin shuold have an internal resistance of 2 MOhm so the resistors on the shield should be >= 10 MOhm. You can use [this](http://www.ohmslawcalculator.com/voltage-divider-calculator) voltage devider calculator to calculate the resistor value. The Arduino pin mosfets are LOW state when the input is about <= 2.5V. If you use a less conductive material to close the contacts of the pad maybe you will have to raise the resistance up to 20MOhm. Remeber that an high resistance voltage devider make the input *(dancing* 🎶 *)*. You will see the button blipping just by touching one side of the button pad. Please avoid to connect power cable to the laptop while playing or will act like an antenna. 🎶🎶🎶🎶💩...... I'm still studing how to debounce correctly a touch button made by using a voltage devider.
      
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/touch_button_simple.PNG" width="200" height="200" />
      *touch button pad (the resistors are on the shield)* 
      &nbsp;
      
      - capacitive design: you can use the [TTP223](https://infusionsystems.com/support/TTP223.pdf) touch module 
      
   - [pin_test](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch/pin_test) - Used to check the buttons assignment. 
   
      - int wiring[18] = Arduino pin in the IDE
      - int binding[18] = Buttons of joystick lib
      - String pull_mask[18] = pin state? High Low float (depending by the button type used)
      - analog_mask[18] = is analog? (for example pot is analog and push button is digital)
      
      Write the button structure with arrays here, execute the code and check in the table if the button binding is correct. If the binding satisfy your magic fingers copy this configuration to the main code ``Volante.ino``
      
  
  
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
Don't worry if is not totally clear.... This project is still under development.

&nbsp;

#### Donation

Study, design and prototiping is expensive. If you believe in my project you can help me 😜 💲💲💲💲💲💲 😎

   - Bitcoin ```1KB6oxVrh5P6SbwFdtNHSG1rqPmdsaTaDV```

   - ETH ```0x7a5b81b2174748d6573a9ebf6b16d07c634c3e4f```

   - Litecoin ```LdVFaYbAsx9txhjVk1KURWvXqpVFDyT35k```

