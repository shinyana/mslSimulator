#include "guidance_control.h"

const int bit_completion = 1;
const int missile_separation = 2;
const int guidance_initial = 3;
const int guidance_mid = 4;
const int guidance_final = 5;

class Autopilot {
  private:
    Guidance_Control guidance_control;    
    int discrete_missile_seperation;
    int discrete_intakecover_sereration;
    int discrete_cartridge_starter;
    int discrete_igniter;
    int discrete_arming_on;
    int discrete_arming_off;
    int discrete_destructer;

    int ap_sequence;
    double target_position_x;
    double target_position_y;
    
    double rest_of_miles;

    void StatusController();
    void GuidanceController();
    void EngineController();
    void HomingHeadController();
    void ThrustController();
    void OutputDiscreteSignals();
  public:
    Autopilot();
    void SequenceController(int);
};
