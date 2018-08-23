/* Volante The Gamepad
 *  
 *  Multi Version - for car and flight simulators, three axis (one slider and two knobs) and 15 buttons 
 *  
 *  Possibility to: 
 *  - free assign the IDE pin number to the Button lib numbers
 *  - use a mixing layout with simple pull-up touch, capacitive or classic push buttons
 *  
 *   This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  
 *  
 *  https://github.com/MHeironimus/ArduinoJoystickLibrary
 *  https://www.arduino.cc/en/Tutorial/Debounce
 *  
 *  mail: mancioman2@gmail.com
 *  
 *  
 *  BUTTON CONFIGURATION
 *  
 *  --- BUTTONS ---
 *  ONE = 0 / RX1
 *  TWO = 1 / TX0
 *  THREE = 2
 *  FOUR = 3
 *  FIVE = 4
 *  SIX = 5
 *  SEVEN = 6
 *  EIGHT = 7
 *  NINE = 8
 *  TEN = 9
 *  ELEVEN = 10
 *  TWELVE = 14 
 *  THIRTEEN = 15 
 *  FOURTEEN = 16 
 *  FIFTEEN = 21 / A3
 *  
 *  
 *  --- AXIS ---
 *  
 *  A2 = X
 *  A0 = Y
 *  A1 = Z
 *  
 *  The HOT KEY is the button that center the Z axis when keep pressed.
 *  Is useful when the car lose control to free the wheels and keep control back. 
 *  
 *  To set the HOT KEY:
 *  - disconnect Volante from PC
 *  - keep pressed a digital button
 *  - connect the USB cable
 *  - wait more than 5 sec
 *  - release the button
 *  
 *  If potentiometers don't work properly probably 
 *  they are dirty inside. Open the metal cover and clean
 *  the part between the grafite and the brush
 *  
 *  If the axies still vibrate, try to reduce the ohm capacity of the small capacitors to 1uF
 *  
 */

#include <Joystick.h>

// axes are int in the array mask
#define X 997
#define Y 998
#define Z 999

// joystick configuration
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, // joystick ID 
  JOYSTICK_TYPE_JOYSTICK, // device type
  15, // buttons number (up,right,left,down are 2 axis)
  0,
  true, // X axis
  true, // Y axis
  true, // Z axis
  false, // X rotation?
  false, // Y rotation?
  false, // Z rotation?
  false, // rudder
  false, // throttle
  false, // accelerator
  false, // brake
  false // steering
);

// reverse X and Y axis - true = reversed
bool rev_X = false; 
bool rev_Y = false; 


// the Button elements
struct BUTTON {

  int number; // pin number in Arduino IDE
  int pad; // number on gamepad
  String pull; // pull-up, pull-down or float
  boolean analog; // yes or no?
  boolean is_hot; // is this button the hot_key?
};


int wiring[18] = {

   // copy and paste here your button layout (the numbers in Arduino IDE)
   
   A2, // steering
   A0, // alt
   A1, // gas analogic potentiometers pins
   
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   14,
   15,
   16,
   21 // Arduino IDE pin number
     
};

int binding[18] = {

  // copy and paste here your button layout (the numbers as they are recognized in Windows)
  // remember the joystick lib start counting from zero
  
  X, // steering
  Y, // alt
  Z, // gas analogic potentiometers pins

  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14 // Arduino IDE pin number
  
};

// "up" = pull-up, "down" = pull-down, "float" = float (not connected internally in case of extrenal pull resistors)
String pull_mask[18] = {

  /* copy and paste here your button layout (the state of the buttons)
   * float = pin free pysically non connected 
   * down = shorted to GND (pull-down resistor https://playground.arduino.cc/CommonTopics/PullUpDownResistor)
   * up = shorted to +5V (pull-up resistor https://playground.arduino.cc/CommonTopics/PullUpDownResistor)
   */

  "float",
  "float",
  "float", // potentiometers
  
  "float",
  "float",
  "float",
  "float",
  "float", // capacitive from button 1 to 5

  "float",
  "float",
  "float",
  "float",
  "float",
  "float",
  "float",
  "float",
  "float",
  "float" // push buttons from 6 to 15
};

boolean analog_mask[18] = {

  /* copy and paste here your button layout (is this button or pot analog?)
   *  true = analog (0-1023)
   *  false = digital (0-1)
   */

  true,
  true,
  true, // A0, A1 e A2

  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false // digital buttons
};

// time limit
long timer = 5000;
// disengage hot key serching
boolean active = true;

// hot_key selected
int hot_key;

// value of Z axis
int z_pow = 0;

// true = analog read zero (by sw)
boolean fake_an = false;

BUTTON bt[18]; // generate 18 buttons

// the total number of digital buttons (starting from 0)
int el_num = 17;




// Variables will change:
//int ledState = LOW;         // the current state of the output pin
int buttonState = HIGH;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// read the state of the switch into a local variable
int reading;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers




 



// analogRead with button debouncer included
int debouncer(int button){

  // read the state of the switch into a local variable:
  reading = digitalRead(button);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
 

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  return lastButtonState;
  
}

// initialize the buttons
void bt_maker(){

  for(int i=0; i<=el_num; i++){

    bt[i].number = wiring[i];
    bt[i].pad = binding[i];
    bt[i].pull = pull_mask[i];
    bt[i].analog = analog_mask[i];
    bt[i].is_hot = false;  
  }
  
}





// config the gamepad
void joy_conf(){

  // Initialize Joystick Library
  Joystick.begin();

  Joystick.setXAxisRange(-1023, 1023);
  Joystick.setYAxisRange(-1023, 1023);
  Joystick.setZAxisRange(-1023, 1023);
  
 
   
}

void button_conf(){

  
  
  // Initialize Button switch Pins

  for(int i=0; i <= el_num; i++){

    if(!bt[i].analog){
      
      if(bt[i].pull == "up"){

        pinMode(bt[i].number, INPUT_PULLUP);
        
      }else if(bt[i].pull == "down" || bt[i].pull == "float"){

        pinMode(bt[i].number, INPUT);
        
      }
    }
    
  
  }
   
  

}

// shift the potentiometer scale to reach negative value of the axis
long mapper(long m, bool rev){

  if(rev){
    return map(m, 0, 1023, 1023, -1023);
  }else if(!rev){
    return map(m, 0, 1023, -1023, 1023);
  }
    
}

// true = the current button will become the hot-key (use a free button not used during the game)
boolean hot(){

  long time_now = millis();
  if(time_now >= timer && time_now <= timer + 2000 && active){
    active = false;
    return true;
  }

  return false;
}






void setup() {

  DDRD &= ~(1<<5); // disable TXLED and RXLED (TXLED is always on if the USB is tranmitting data)

  // initialize buttons
  bt_maker();
  
  // start joystick library and set axis range
  joy_conf();

  // set buttons PULLUP
  button_conf(); 

  
  
}



void loop() {
  
  
  
  // check every digital button
  for(int i=0; i <= el_num; i++){

    // analog check
    if(bt[i].analog){

      switch(bt[i].pad){

        case X:
          if(rev_X){
            Joystick.setXAxis(mapper(analogRead(bt[i].number), true));
          }else if(!rev_X){
            Joystick.setXAxis(mapper(analogRead(bt[i].number), false));
          }
          break;

        case Y:
          if(rev_Y){
            Joystick.setYAxis(mapper(analogRead(bt[i].number), true));
          }else if(!rev_Y){
            Joystick.setYAxis(mapper(analogRead(bt[i].number), false));
          }
          break;
          
        case Z:
          if(!fake_an){
            Joystick.setZAxis(mapper(analogRead(bt[i].number), false));
          }else{
            Joystick.setZAxis(z_pow);
          }
          break;
          
      }
            

    /* digital up or float (float is externally pull-up so is the same case as up)
     * remember to keep float the pin in the hw if the pin has an external pull-up resistor. The internal pull-up is between 20kΩ and 50kΩ
     */
    }else if( (!bt[i].analog && bt[i].pull == "up") || (!bt[i].analog && bt[i].pull == "float")){


      if(debouncer(bt[i].number) == LOW){

        Joystick.setButton(bt[i].pad, HIGH); // High because the open switch is +5V and close is GND
        if(hot()){
          bt[i].is_hot = true; // this button become the hot_key button
        }

        if(bt[i].is_hot){
          fake_an = true; // I'm pressing the hot key
        }
        
      }else{

        Joystick.setButton(bt[i].pad, LOW);

        if(bt[i].is_hot){
          fake_an = false; // I'm NOT pressing the hot key
        }
        
      }


    // digital down        
    }else if(!bt[i].analog && bt[i].pull == "down"){

      if(debouncer(bt[i].number) == LOW){

        Joystick.setButton(bt[i].pad, LOW);

        if(bt[i].is_hot){
          fake_an = false;
        }
      
      }else{

        Joystick.setButton(bt[i].pad, HIGH);
        if(hot()){
          bt[i].is_hot = true;
        }

        if(bt[i].is_hot){
          fake_an = true;
        }

               
      }
      
    }

      

    
  }



} 
