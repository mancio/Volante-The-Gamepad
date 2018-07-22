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
 *  A0 = A0
 *  A1 = A1
 *  A2 = A2
 *  
 *  If potentiometers don't work properly probably 
 *  they are dirty inside. Open the metal cover and clean
 *  the part between the grafite and the brush
 *  
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


struct BUTTON {

  int number; // pin number in Arduino IDE
  int pad; // number on gamepad
  String pull; // pull-up, pull-down or float
  boolean analog; // yes or no?
};


int wiring[18] = {

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

  X, // steering
  Y, // alt
  Z, // gas analogic potentiometers pins

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
  14,
  15 // Arduino IDE pin number
  
};

// "up" = pull-up, "down" = pull-down, "float" = float (not connected internally in case of extrenal pull resistors)
String pull_mask[18] = {

  "float",
  "float",
  "float", // potentiometers
  
  "down",
  "down",
  "down",
  "down",
  "down", // capacitive from button 1 to 5

  "up",
  "up",
  "up",
  "up",
  "up",
  "up",
  "up",
  "up",
  "up",
  "up" // push buttons from 6 to 15
};

boolean analog_mask[18] = {

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
long mapper(long m){

  return map(m, 0, 1023, -1023, 1023);
  
}


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

    if(bt[i].analog){

      switch(bt[i].pad){

        case X:
          Joystick.setXAxis(mapper(analogRead(bt[i].number)));
          break;

        case Y:
          Joystick.setYAxis(mapper(analogRead(bt[i].number)));
          break;
          
        case Z:
          Joystick.setZAxis(mapper(analogRead(bt[i].number)));
          break;
          
      }
            
      
    }else if( (!bt[i].analog && bt[i].pull == "up") || (!bt[i].analog && bt[i].pull == "float")){


      if(debouncer(bt[i].number) == LOW){

        Joystick.setButton(bt[i].pad, HIGH);
        if(hot()){
          hot_key = bt[i].pad;
        }

        if(hot_key == bt[i].pad){
          while(debouncer(bt[i].number) == LOW){
            Joystick.setZAxis(0);
          }
        }
        
      }else{

        Joystick.setButton(bt[i].pad, LOW);
      
      }

            
    }else if(!bt[i].analog && bt[i].pull == "down"){

      if(debouncer(bt[i].number) == LOW){

        Joystick.setButton(bt[i].pad, LOW);
      
      }else{

        Joystick.setButton(bt[i].pad, HIGH);
        if(hot()){
          hot_key = bt[i].pad;
        }

        if(hot_key == bt[i].pad){
          while(debouncer(bt[i].number) == HIGH){
            Joystick.setZAxis(0);
          }
        }

        
      }
      
    }

      

    
  }



} 
