/* Volante The Gamepad
 *  
 *  Button configuration tester  - for car and flight simulators, three axis (one slider and two knobs) and 15 buttons 
 *  
 *  Print on serial monitor the actual button configuration, useful to configure the button array masks and export them to the main code.
 *  Doesn't work as HID gamepad, show only text on Serial Monitor
 *  
 *  This program is free software: you can redistribute it and/or modify
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

// axes are int in the array mask
#define X 997
#define Y 998
#define Z 999

// print table times
int pr_time = 1;

int counter = 0;


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

  X,
  Y,
  Z, // pots are not digital buttons

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


BUTTON bt[18]; // generate 18 buttons

// the total number of digital buttons (starting from 0)
int el_num = 17;







// initialize the buttons
void bt_maker(){

  for(int i=0; i<=el_num; i++){

    bt[i].number = wiring[i];
    bt[i].pad = binding[i];
    bt[i].pull = pull_mask[i];
    bt[i].analog = analog_mask[i];
      
  }
  
}




void sep(){
  
  Serial.println("");
  Serial.println("-------------------------------");
  Serial.println("");
  
}


boolean leo_check(){

  // leonardo IDE analog pin
  int ide[8] = {18, 19, 20, 21};

  int an[8] = {A0, A1, A2, A3};

  Serial.print("Arduino Leonardo Pro Micro?");
  sep();
  

   for(int i=0; i <= el_num; i++){

    if(bt[i].analog){

      switch(bt[i].pad){

        case X:
          Serial.print("X ->");
          Serial.print("\t");
          Serial.print(bt[i].number);
          sep();
          break;
        
        case Y:
          Serial.print("Y ->");
          Serial.print("\t");
          Serial.print(bt[i].number);
          sep();
          break;
        
        case Z:
          Serial.print("Y ->");
          Serial.print("\t");
          Serial.print(bt[i].number);
          sep();
          break;
        
                 
      }
    }
  }

  for(int i=0; i<=7; i++){

    if(ide[i] != an[i]){
      return false;
    }
     
  }

  return true;
  
}



void an_builder(){
  
  // analog list
  Serial.println("Analog");
  sep();
  
  Serial.print("Axes");
  Serial.print("||");
  Serial.print("IDE PIN");
  Serial.print("||");
  Serial.print("State");
  Serial.print("||");
  sep();

  for(int i=0; i <= el_num; i++){

    if(bt[i].analog){

      switch(bt[i].pad){

        case X:
          Serial.print("X");
          Serial.print("||");
          Serial.print(bt[i].number);
          Serial.print("||");
          Serial.print(bt[i].pull);
          sep();
          break;
        
        case Y:
          Serial.print("Y");
          Serial.print("||");
          Serial.print(bt[i].number);
          Serial.print("||");
          Serial.print(bt[i].pull);
          sep();
          break;
        
        case Z:
          Serial.print("Z");
          Serial.print("||");
          Serial.print(bt[i].number);
          Serial.print("||");
          Serial.print(bt[i].pull);
          sep();
          break;
        
        default:
          Serial.print("axes");
          Serial.print("||");
          Serial.print("error");
          Serial.print("||");
          Serial.print("error");
          sep();
          break;
          
      }
    }
  }
}




void dig_builder(){

  // digital list
  Serial.println("Digital");
  sep();
  
  Serial.print("Buttons");
  Serial.print("||");
  Serial.print("IDE PIN");
  Serial.print("||");
  Serial.print("State");
  Serial.print("||");
  sep();
  
  
  for(int i=0; i <= el_num; i++){
  
    if(!bt[i].analog){
    
      Serial.print(bt[i].pad);
      Serial.print("||");
      Serial.print(bt[i].number);
      Serial.print("||");
      
      if(bt[i].pull == "up"){

        Serial.print("up");
        Serial.print("||");
        
      }else if(bt[i].pull == "down"){

        Serial.print("down");
        Serial.print("||");

      }else if(bt[i].pull == "float"){
      
        Serial.print("float");
        Serial.print("||");
      
      }else{

        Serial.print("error");
        Serial.print("||");
      
      }  

      sep();
  
    }

  }
  

}
            
      
   



void setup() {

  //DDRD &= ~(1<<5); // disable TXLED and RXLED (TXLED is always on if the USB is tranmitting data)

  Serial.begin(9600);

  // initialize buttons
  bt_maker();
  
   
  
}



void loop() {
  
    
  Serial.println("button map");
  sep();

  an_builder();

  dig_builder();

  if(leo_check()){
    Serial.println("is a Leonardo");
  }else{
    Serial.println("is NOT a Leonardo");
  }
  
  delay(60000);
  
} 
