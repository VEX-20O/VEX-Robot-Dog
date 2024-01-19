using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor Arm;
extern motor Drive1;
extern motor Drive2;
extern signature Vision17__BALL;
extern signature Vision17__SIG_2;
extern signature Vision17__SIG_3;
extern signature Vision17__SIG_4;
extern signature Vision17__SIG_5;
extern signature Vision17__SIG_6;
extern signature Vision17__SIG_7;
extern vision Vision17;
extern bumper BumperH;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );