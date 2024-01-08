
#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
int pos = 0;

void setup(){
  Serial.begin(9600); //This is for serial monitor.
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(7);
  myservo1.write(165);
  myservo2.write(25);
  myservo3.write(25);
  myservo4.write(25);
  myservo5.write(25);
}
void loop() {
   if (Serial.available() > 0)//Storing bytes from the serial port that are available for reading.
  {
    char data = Serial.read(); // reading the data received from the bluetooth module.
    switch (data)//Using Switch case for opening and closing of the gate.
    {
      case '1': for (pos = 0; pos <= 90; pos += 1) //Giving codition to rotate the bluetooth_motor from 0 to 90 degree.
        {
          myservo1.write(25);
  myservo2.write(165);
  myservo3.write(165);
  myservo4.write(165);
  myservo5.write(165);
        }
        break; //Use to stop the loop.
      case '2': for (pos = 90; pos >= 0; pos -= 1) //Giving codition to rotate the bluetooth_motor from 90 to 0 degree.
        {
         myservo1.write(165);
  myservo2.write(25);
  myservo3.write(25);
  myservo4.write(25);
  myservo5.write(25);
        }
        break; //Use to stop the loop.
        case '3': for (pos = 90; pos >= 0; pos -= 1) //Giving codition to rotate the bluetooth_motor from 90 to 0 degree.
        {
         myservo1.write(25);
  myservo2.write(165);
  myservo3.write(25);
  myservo4.write(165);
  myservo5.write(165);
        }
        break; //Use to stop the loop.
        case '4': for (pos = 90; pos >= 0; pos -= 1) //Giving codition to rotate the bluetooth_motor from 90 to 0 degree.
        {
         myservo1.write(165);
  myservo2.write(165);
  myservo3.write(165);
  myservo4.write(25);
  myservo5.write(25);
        }
        break; //Use to stop the loop.
        case '5': for (pos = 90; pos >= 0; pos -= 1) //Giving codition to rotate the bluetooth_motor from 90 to 0 degree.
        {
         myservo1.write(25);
  myservo2.write(165);
  myservo3.write(25);
  myservo4.write(25);
  myservo5.write(165);
        }
        break; //Use to stop the loop.
        case '6': for (pos = 90; pos >= 0; pos -= 1) //Giving codition to rotate the from 90 to 0 degree.
        {
         myservo1.write(25);
  myservo2.write(165);
  myservo3.write(165);
  myservo4.write(25);
  myservo5.write(165);
        }
        break; //Use to stop the loop.
      default : break; //if there is no data then it will by defalt break the loop.
    }
    Serial.println(data); //Print it in serial monitor.
  }

}
