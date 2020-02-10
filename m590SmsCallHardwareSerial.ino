/*
M590 default baud rate 57600
baud rate check, AT+IPR?
baud rate check, AT+IPR=9600 
                 baud rate changed to 9600

Pinout:
+5v --  5v power supply in
GND --  Ground – 0v
I   --  Ring, Output (Will pulse low for an incoming call or SMS)
T   --  Transmit (3.3v logic) - Arduino Rx(Pin 0)
R   --  Receive (3.3v logic) - Arduino Tx(Pin 1)
V   --  Voltage after diode (Around 4.45v – M590 maximum is 4.5v)
K   --  On/Off (Latched input – Pull low to turn on, pull low again to turn module off)
G   --  Ground – 0v

\*/

//Code 
//Hasan Sohag & Syed Razwanul Haque Nabil
//https://www.nabilbd.com
//https://www.cruxbd.com
#include <string.h>
char user_num[15]="+8801*********";                  //phone number for sending sms
int i;

void setup()
{
  Serial.begin(57600);//your baud rate
  delay(10000);// Very Important Delay. Its remove unwanted data at begining
  
 
  sendSMS("Hello World"); //sms sending function
  delay(30000);
  makeCall(); ////calling function
  delay(30000);
}

void loop()        //main loop
{
  
}

void sendSMS(char text[])
{
  delay(500);
  Serial.println("AT+CMGF=1");
  delay(500);
  Serial.println("AT+CSCS=\"GSM\"");
  delay(1000);         //Sets the Serial Module in Text Mode
  Serial.print("AT+CMGS=\"");
  delay(500);
  Serial.print(user_num);
  delay(500);
  Serial.println("\""); //'user_num' is the string of the mobile number
  delay(500);
  Serial.print(text); // The SMS text you want to send
  delay(500);
  Serial.write(0x1A); // ASCII code of CTRL+Z. command to send SMS.
  delay(500);
}


void makeCall()
{
  delay(500);
  Serial.print("ATD");
  Serial.print(user_num); //'user_num' is the string of the mobile number
  Serial.println(";");
  delay(25000);
  Serial.println("ATH"); //end the call
  delay(500);
}
