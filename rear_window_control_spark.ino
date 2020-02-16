const int upTime = 10000; // up time to run

const int downTime = 8000; // down time to run

const int buttonTime = 200; // length of input capture


//pin numbers
const int MotorUp = 3; // the number of the up pin

const int MotorDown = 4; // the number of the down pin

const int input = 0; // the number of the input pin

bool lastInputLow = false;

uint8_t upState = HIGH; // upState used to set the up direction

uint8_t downState = HIGH; // downState used to set the down direction

bool IsWindowUp = true; // window state

unsigned long lastRecordedTime = 0; // Time up operation was updated
 

////////////////////////////////////
void setup() 
{

  // set the digital pin as output:

  pinMode(MotorUp, OUTPUT);

  pinMode(MotorDown, OUTPUT);

  pinMode(input, INPUT_PULLUP);

  digitalWrite(MotorUp,LOW);

  digitalWrite(MotorDown,LOW);
}

/////////////////////////////////////////
void loop() 
{

  if((digitalRead(input)==LOW) && (lastInputLow == false))
  {
      //if (lastInputLow == false)
      //{
          lastRecordedTime = millis() ;
          lastInputLow = true;
      /* }
     else if (millis()- lastRecordedTime > buttonTime)  // we have a valid signal on the input
      { */ 
          if (IsWindowUp)                     // we roll window down
          {
              digitalWrite(MotorDown,HIGH);
              while ( millis() - lastRecordedTime < upTime); // && (digitalRead(input)==HIGH));
              delay(1);
              digitalWrite(MotorDown,LOW);
              IsWindowUp = false;

          }
          else                                 // we roll window down
          {
              digitalWrite(MotorUp,HIGH);
              while  ( millis() - lastRecordedTime < downTime);// && (digitalRead(input)==LOW));
              delay(1);
              digitalWrite(MotorUp,LOW);
              IsWindowUp = true;
          
          
          lastInputLow = false;
      }     
  }
  else
    lastInputLow = false;

}
