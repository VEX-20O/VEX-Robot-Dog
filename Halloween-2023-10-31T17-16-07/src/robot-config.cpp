#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Arm = motor(PORT20, ratio18_1, false);
motor Drive1 = motor(PORT19, ratio18_1, true);
motor Drive2 = motor(PORT18, ratio18_1, false);
/*vex-vision-config:begin*/
signature Vision17__BALL = signature (1, 8313, 11469, 9892, -1009, -305, -658, 3, 0);
signature Vision17__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision17__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision17__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision17__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision17__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision17__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vision Vision17 = vision (PORT17, 45, Vision17__BALL, Vision17__SIG_2, Vision17__SIG_3, Vision17__SIG_4, Vision17__SIG_5, Vision17__SIG_6, Vision17__SIG_7);
/*vex-vision-config:end*/
bumper BumperH = bumper(Brain.ThreeWirePort.H);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}