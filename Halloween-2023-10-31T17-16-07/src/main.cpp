/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Eric Lind                                                 */
/*    Created:      Tue Oct 31 2023                                           */
/*    Description:  Boston Dynamics Robot Dog Vision                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Arm                  motor         20              
// Drive1               motor         19              
// Drive2               motor         18              
// Vision17             vision        17              
// BumperH              bumper        H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

/*

This program uses a Proportional control module in combination with a vision sensor to make
the robot follow the  ball, and aim its 'head' at it. 

*/

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  //P control constants (to tune)
  float pturn = 0.4;
  float pdrive = 1.2;
  float parm = 0.11;
  float finalspeed = 1;

  //Main control loop
  while (1) {

    Vision17.takeSnapshot(Vision17__BALL); //Initial sensing of the loop to check for object

    //Will not move if no object of the specified signature is detected or the emergency button is pressed
    if(Vision17.objects[0].exists && !BumperH.pressing()){
      
      //Needed errors in the objects position relative to the vision camera
      float visXerr = 316/2.0-Vision17.objects[0].centerX;
      float visYerr = 100-Vision17.objects[0].centerY;
      float visHerr = Vision17.objects[0].height - 45;

      //Per-loop drive control 
      double turnL = 0;
      double turnR = 0;
      double armM = 0;

      //Turning P Control
      if(visXerr > 50 || visXerr <-50){
        turnR-=visXerr*pturn;
        turnL+=visXerr*pturn;
      }
  
      //Arm Angle P control
      if(visYerr > 50 || visYerr <-50){
        armM-=parm*visYerr;
      }

      //Distance P control
      if(Vision17.objects[0].height < 60 || Vision17.objects[0].height > 40){
        turnR+= visHerr*-pdrive;
        turnL+= visHerr*-pdrive;
      }
     
      //Per-loop movement based on sums of errors
      Drive1.spin(forward,turnL*finalspeed,percent);
      Drive2.spin(forward,turnR*finalspeed,percent);
      Arm.spin(forward,armM,percent);
    }

    else{ //if no object or button pressing, stop all movement
      Drive1.stop();
      Drive2.stop();
      Arm.stop();
    }
  }
}
