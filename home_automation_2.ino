#include <Keypad.h>

const byte ROWS = 4; //Four rows
const byte COLS = 4; //Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'S','0','H','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v_passcode="";

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    //Serial.println(key);
    
    v_passcode = v_passcode + key;
    
    if(key=='A')
    {
    	Serial.println("Enter Password");
        v_passcode="";
    }
    
    if(key=='D')
    {
    	Serial.println("Validate the Password");
      	//Serial.println(v_passcode);
      	
      	if (v_passcode=="6969D")
        {
          Serial.println("Access Granted");
        }
      	else
        {
        	Serial.println("Access Denied");
        }      
    }        
  }
}