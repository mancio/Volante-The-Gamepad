/* Volante The Gamepad
 *  
 *  Joystick version - for car and flight simulators, three axis (one slider and two knobs) and 15 buttons 
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


// switch buttons
int one = 0;
int two = 1;
int three = 2;
int four = 3;
int five = 4;
int six = 5;
int seven = 6;
int eight = 7;
int nine = 8;
int ten = 9;
int eleven = 10;
int twelve = 14;
int thirteen = 15;
int fourteen = 16;
int fifteen = 21;

// the total number of digital buttons (starting from 0)
int el_num = 14; 

// buttons array values
int button_array[] = {one,two,three,four,five,six,seven,eight,
                        nine,ten,eleven,twelve,thirteen,fourteen,fifteen};
                        
// steering and gas-brake potentiometers
int st = A2;
int alt = A0;
int gas = A1;

//  potentiometers array value
//int pot_array[st, alt, gas];



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
    
    pinMode(button_array[i], INPUT_PULLUP);
  
  }

  

  
  
  

}

// shift the potentiometer scale to reach negative value of the axis
long mapper(long m){

  return map(m, 0, 1023, -1023, 1023);
  
}




void setup() {

  DDRD &= ~(1<<5); // disable TXLED and RXLED (TXLED is always on if the USB is tranmitting data)

  // start joystick library and set axis range
  joy_conf();

  // set buttons PULLUP
  button_conf(); 

  
  
}



void loop() {
  
  
  
  // check every digital button
  for(int i=0; i <= el_num; i++){

    if(debouncer(button_array[i]) == LOW){

      Joystick.setButton(i, HIGH);
      
    }else{

      Joystick.setButton(i, LOW);
      
     }

    }

  
  

  Joystick.setXAxis(mapper(analogRead(st)));
  Joystick.setYAxis(mapper(analogRead(alt)));
  Joystick.setZAxis(mapper(analogRead(gas)));

} 
