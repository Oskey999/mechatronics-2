#include <Arduino.h>
#include <Servo.h>
#include <Dynamixel2Arduino.h>

//#define DEBUG_SERIAL soft_serial

int servo_pin_door =9;
int servo_pin_pitch= 8;
int dxl_pin= 2;

const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

Servo servo_door;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo servo_pitch;

Dynamixel2Arduino dxl (Serial, dxl_pin);


int pos_door = 0;    // variable to store the servo position
int pos_pitch= 0;
int maxpos=180; //max pos_doorition in degrees for the servo


void doservo(){
  for (pos_door = 0; pos_door <= maxpos; pos_door += 1) { // goes from 0 degrees to maxpos degrees
    // in steps of 1 degree
    servo_door.write(pos_door);              // tell servo to go to pos_doorition in variable 'pos_door'
    delay(15);                       // waits 15 ms for the servo to reach the pos_doorition
  }

  delay(500);
  for (pos_door = maxpos; pos_door >= 0; pos_door -= 1) { // goes from maxpos degrees to 0 degrees
    servo_door.write(pos_door);              // tell servo to go to pos_doorition in variable 'pos_door'
    delay(15);                       // waits 15 ms for the servo to reach the pos_doorition
  }

}

void dodxl(){
    // Please refer to e-Manual(http://emanual.robotis.com) for available range of value. 
  // Set Goal Velocity using RAW unit
  dxl.setGoalVelocity(DXL_ID, 200);
  delay(1000);
  // Print present velocity
 // DEBUG_SERIAL.print("Present Velocity(raw) : ");
 // DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID));
  delay(1000);

  // Set Goal Velocity using RPM
  dxl.setGoalVelocity(DXL_ID, 25.8, UNIT_RPM);
  delay(1000);
 // DEBUG_SERIAL.print("Present Velocity(rpm) : ");
//DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID, UNIT_RPM));
  delay(1000);

  // Set Goal Velocity using percentage (-100.0 [%] ~ 100.0 [%])
  dxl.setGoalVelocity(DXL_ID, -10.2, UNIT_PERCENT);
  delay(1000);
 // DEBUG_SERIAL.print("Present Velocity(ratio) : ");
 // DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID, UNIT_PERCENT));
  delay(1000);
}

void grabbertest(){
    for (pos_door = 0; pos_door <= maxpos; pos_door += 1) { // goes from 0 degrees to maxpos degrees
    // in steps of 1 degree
    servo_door.write(pos_door);              // tell servo to go to pos_doorition in variable 'pos_door'
    delay(15);                       // waits 15 ms for the servo to reach the pos_doorition
  }

  delay(10000);
  // for(pos_pitch=0; pos_pitch<=20; pos_pitch++){
  //   servo_pitch.write(pos_door);              // tell servo to go to pos_doorition in variable 'pos_door'
  //   delay(15);  
  // }
  for (pos_door = maxpos; pos_door >= 0; pos_door -= 1) { // goes from maxpos degrees to 0 degrees
    servo_door.write(pos_door);              // tell servo to go to pos_doorition in variable 'pos_door'
    delay(15);                       // waits 15 ms for the servo to reach the pos_doorition
  }
  // delay(1000);
  // for(pos_pitch=20; pos_pitch>=0; pos_pitch -=1){
  //   servo_pitch.write(pos_door);              // tell servo to go to pos_doorition in variable 'pos_door'
  //   delay(15); 
  // }
}

void pitcthtest(){
  //   for (pos_pitch = 0; pos_pitch < 40; pos_pitch += 1) { // goes from 0 degrees to maxpos degrees
  //   // in steps of 1 degree
  //   servo_pitch .write(pos_pitch);              // tell servo to go to pos_doorition in variable 'pos_door'
  //   delay(15);                       // waits 15 ms for the servo to reach the pos_doorition
  // }

  // delay(10000);
  // for (pos_pitch  = 40; pos_pitch  > 0; pos_pitch  -= 1) { // goes from maxpos degrees to 0 degrees
  //   servo_pitch .write(pos_pitch );              // tell servo to go to pos_doorition in variable 'pos_door'
  //   delay(15);                       // waits 15 ms for the servo to reach the pos_doorition
  // }
  servo_pitch.write(180);
  delay(10000);
  servo_pitch.write(0);
  delay(10000);
  servo_pitch.write(90);

}

void setup() {
  servo_door.attach(servo_pin_door);  // attaches the servo on pin 9 to the servo object
  servo_pitch.attach(servo_pin_pitch);

 //grabbertest();
  pitcthtest();

  // dynamixel setup
  
  // Use UART port of DYNAMIXEL Shield to debug.
 // DEBUG_SERIAL.begin(115200);
  
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_VELOCITY);
  dxl.torqueOn(DXL_ID);

}

void loop() {
 // doservo();
  //dodxl();
}

