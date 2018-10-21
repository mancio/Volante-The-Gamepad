# Volante-The-Gamepad
The new revolutionary joystick for car and flight simulation games.

*(Design still in progress 😆)*

&nbsp;

<p align="center">
<img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/touchpad.jpg" width="550" height="400" />
</p>   

*prototype with home-made touch buttons*

&nbsp;

<p align="center">
<img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/out_box.jpg" width="550" height="400" />
</p>   

&nbsp;

*prototype with classic RC remote buttons*

### Software 
The code is written by using the famous libray ```Joystick.h```. You can find some sketches still in testing [here](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch).
After some tests seem that only the ```JOYSTICK_TYPE_JOYSTICK``` configuration works. Unfortunately Microsoft stop to support the HID human interface and only the basic function works. Still no solution for force feedback and particular multiaxis joystick.... now the more complex gaming simulation devices have their own drivers. You don't need the basic plug and play driver. Please have a look for the [HID architecture](https://docs.microsoft.com/en-us/windows-hardware/drivers/hid/) to understand and maybe help 😵

### Hardware
The hardware include a joystick case, buttons, knobs, the [Arduino Pro Micro](https://www.sparkfun.com/products/12640) and the the shield to interface the Arduino with the gamepad hw. The button pad modules and the shield boards are designed with [KiCad](http://kicad-pcb.org/). You can find on [OSH Park](https://oshpark.com) the PCBs ready to print.
1. [First design - only push buttons](https://oshpark.com/shared_projects/Fl5pqxbd)
2. [Second design - esternal pull-up resistors](https://oshpark.com/shared_projects/2LW72doK)



### Directory structure
1. [ArduinoJoystickLibrary-master](https://github.com/mancio/Volante-The-Gamepad/tree/master/ArduinoJoystickLibrary-master) - the Joystick library written by [Matthew Heironimus](https://github.com/MHeironimus)

2. [Fritzing](https://github.com/mancio/Volante-The-Gamepad/tree/master/Fritzing) - The Fritzing project with a prototype on breadbord. A small sketch to give a basic idea.

3. [Picture](https://github.com/mancio/Volante-The-Gamepad/tree/master/Picture) - some pictures for the Fritzing design project and the building process

4. [Volante sketch](https://github.com/mancio/Volante-The-Gamepad/tree/master/Volante%20sketch) - the code
   
   - [Volante](https://github.com/mancio/Volante-The-Gamepad/blob/master/Volante%20sketch/Volante/Volante.ino) - the main Arduino sketch. The sketch is design to be used with touch, capacitive and push buttons. The I/O pin can be in PULL-UP, PULL-DOWN or FLOAT configuration. 
      - touch button design: The PINs change to LOW when the finger or any not-hi-resistance organic object connect both the pad tracks. The finger and each resistor on the shield should be considered part of a voltage devider. Your dry skin should have an internal resistance of 2 MOhm so the resistors on the shield should be >= 10 MOhm. You can use [this](http://www.ohmslawcalculator.com/voltage-divider-calculator) voltage devider calculator to calculate the resistor value. The Arduino pin mosfets are LOW state when the input is about <= 2.5V. If you use a less conductive material to close the contacts of the pad maybe you will have to raise the resistance up to 20MOhm. Remeber that an high resistance voltage devider make the input *(dancing* 🎶 *)*. You could see the button blipping when you touch the button pad (only one contact or both). This effect is usualy caused by the power supply cord (I'm testing on a laptop). To reduce this effect you should a cercamic capacitor between the input and the ground. The capacitor store a small charge when you press the button and release it very slowly due to the very high value resistors. This stop the flipping but introduce a small delay. You should try some caps between 100pF (101 value) - 100nF (104 value) until your find the best compromise for your application. I suggest 10nF (103 value) capacitor.
      
      [Here](https://www.tinkercad.com/things/0KRsWQPfhxv) Some experiments on ThinkerCad.
      
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/touch_button_simple.PNG" width="200" height="200" />
      *touch button pad (the resistors are on the shield)* 
      &nbsp;
      
      - capacitive design: you can use the [TTP223](https://infusionsystems.com/support/TTP223.pdf) touch module as push button Normally LOW. The button switch on/off by using an internal timer that estimate the change of the capacitive charge during a fixed time slice. I suggest this configuration only for fast operation where is not required precision. The buttons are fast to trigger but sensible to external environment (high probability of fake positive) and the chip autoreset after few seconds (do not use as acceleretor button in a game)  
      
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/TTP223.PNG" width="200" height="200" />
      *capacitive module* 
      &nbsp;
      
      - classic push button design: you can set up NO (normally open push button) using a pull-up configuration to reduce bouncing effects. When you push the button the pin will be GND. This is the most simple configuration, the button will be very reactive but harder to trigger (the most of NO push buttons are hard to click)
      
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/NO_push.PNG" width="250" height="150" />
      *NO Momentary push button for RC* 
      &nbsp;
      
      
   - [test](https://github.com/mancio/Volante-The-Gamepad/blob/master/Volante%20sketch/test/test.ino) - Used to check the buttons assignment. 
   
      - int wiring[18] = Arduino pin in the IDE
      - int binding[18] = Buttons of joystick lib
      - String pull_mask[18] = pin state? High Low float (depending by the button type used)
      - analog_mask[18] = is analog? (for example pot is analog and push button is digital)
      
      Write the button structure with arrays here, execute the code and check in the table if the button binding is correct. If the binding satisfy your magic fingers copy this configuration to the main code ``Volante.ino``
      
  
  
5. [kicad](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad) - the Kicad scheme and PCB project.

   - [buttons_layout](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/buttons_layout) - the blueprint of the gamepad case with RC push buttons
   
   - [buttons_layout_touch](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/buttons_layout_touch) - the blueprint of the gamepad case with touch buttons
   
   - [lib](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/lib) - kicad libraries of this project (include in kicad before open the project)
   
   - [shield](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/shield) - firrst shield design only for capacitive and push buttons
   
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/pcb.jpg" width="370" height="300" />
      *First PCB printed by OSH Park* 
      &nbsp;
      
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/pcb_proto.PNG" width="250" height="200" />
      *First PCB 3D view design by KiCad* 
      &nbsp;
   
   - [shield_touch](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/shield_touch) - second shield design with extaernal pull-up resistor for push, capacitive and touch buttons.
   
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/pcb2_front.jpg" width="250" height="300" />
      *Second PCB printed by OSH Park and assembled manually* 
      &nbsp;
      
      &nbsp;
      <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/pcb_smart.PNG" width="250" height="200" />
      *Second PCB 3D view design by KiCad* 
      &nbsp;
   
   - [touch_button_fancy](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/touch_button_fancy) - alternative push button PCB design
   
   - [touch_button_simple](https://github.com/mancio/Volante-The-Gamepad/tree/master/kicad/touch_button_simple) - main push button PCB design

6. [Assetto Corsa/Lotus GT Dream](https://github.com/mancio/Volante-The-Gamepad/tree/master/Assetto%20Corsa/Lotus%20GT%20Dream) - See *Cars for Assetto Corsa*

7. [Gamepad 3d design](https://github.com/mancio/Volante-The-Gamepad/tree/master/Gamepad%203d%20design) - 3d model of the gamepad Volante
   
### Game Setup

How to set up the Volante for a Awesome gaming experience

1. [Assetto corsa](https://www.assettocorsa.net/en/)

   &nbsp;
   <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/assetto_sm.jpg" width="600" height="500" />
   *Main control configuration* 
   &nbsp;
   
   &nbsp;
   <img src="https://github.com/mancio/Volante-The-Gamepad/blob/master/Picture/assetto2_sm.jpg" width="600" height="500" />
   *Steering settings* 
   &nbsp;
   
### Cars for Assetto Corsa

To make the life easy to all the funs of the amazing game Assetto Corsa I decided to build my own cars (big tail and stick to the ground :red_car:). In the folder you find the game data and the blend file made with [blender](https://www.blender.org/)

1. [Lotus GT Dream](https://github.com/mancio/Volante-The-Gamepad/tree/master/Assetto%20Corsa/Lotus%20GT%20Dream)
   
### Facebook

You can find my project on Facebook on [Andrea Mancini's Machines](https://www.facebook.com/pg/mancio.tech/photos/?tab=album&album_id=2003051576403796)
   
      

### Conclusion
This project is focused to design a new kind of joystick that make pleasant the racing and flight simulation gaming experience.
The joystick will provide a slider linear potentiometer (throttle/brake), two knobs potentiometers (up/down - left/right) and 15 buttons
The innovation from the past consist in the _linear potentiometers_ that give the possibility to the player to perform absolutely precise movements.

#### Note
Don't worry if is not totally clear.... This project is still under development.

&nbsp;

#### Donation

Studying, designing and prototiping is expensive. If you believe in my project you can help me 😜 💲💲💲💲💲💲 😎

   - Bitcoin ```1KB6oxVrh5P6SbwFdtNHSG1rqPmdsaTaDV```

   - ETH ```0x7a5b81b2174748d6573a9ebf6b16d07c634c3e4f```

   - Litecoin ```LdVFaYbAsx9txhjVk1KURWvXqpVFDyT35k```

