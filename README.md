# m590gsm
sample code and interfacing instruction for m590 gsm module
 
 See documentation: 
 http://guides.cyntech.co.uk/raspberry-pi/tutorial/soldering-the-m590-gsmgprs-module/
 
 Pins :</br>
 
+5v >	5v power supply in</br>
GND	> Ground – 0v</br>
I	> Ring – Output (Will pulse low for an incoming call or SMS)</br>
T	> Transmit (3.3v logic)</br>
R	> Receive (3.3v logic)</br>
V	> Voltage after diode (Around 4.45v – M590 maximum is 4.5v)</br>
K	> On/Off (Latched input – Pull low to turn on, pull low again to turn module off)</br>
G	> Ground – 0v</br>

Note :</br>
Connect a 1000uF capacitor between 5V and GND. THIS IS IMPORTANT. </br>
