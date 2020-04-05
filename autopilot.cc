#include <cmath>
#include "autopilot.h"
#include "aptest.h"

/* Constructor */
Autopilot::Autopilot() {
  Guidance_Control guidance_control(InputParameter& ip); 
  
  discrete_missile_seperation = 0;
  discrete_intakecover_seperation = 0;
  discrete_cartridge_starter = 0;
  discrete_igniter = 0;
  discrete_arming_on = 0;
  discrete_arming_off = 0;
  discrete_destructer = 0;

  ap_sequence = 0;
  counter_separation = 0;
  engine_status = engine_stopped;
  target_position_x = ip.getInitialTargetPositionX();
  target_position_y = ip.getInitialTargetPositionY();
  rest_of_miles = sqrt(std::pow(target_position_x, 2.0) + std::pow(target_position_y, 2.0));
};

/*************************
* The master of sequencer
*************************/
void Autopilot::SequenceController(int& counter, InputParameter& ip, INE& ine, UTDC& utdc, double& sensor_engine_rpm) {
  ap_sequence = bit_completion; 
  if (1 == ip.serial_launch_mode && 77 > sensor_engine_rpm) {
    //ESBL before separation
    engine_status = engine_start;
    if (0 == ap_counter % 2) StatusController(ine);
    if (0 == ap_counter % 33) EngineController();
  } else {
    //ESAL or after engine stable with ESBL
    ap_sequence = missile_separation;
    if (ap_sequence == missile_separation) {
      counter_seperation++;
      if (dtime == conter_seperation) {
        ap_sequence = guidance_initial;
      }
    }
    if (77 <= sensor_engine_rpm) {
      //ESBL or after engine stable with ESAL
      engine_status = engine_stable;
      ap_sequence = guidance_initial
    } else {
      //ESAL
      double z_ine = ine.getPositionZ();
      if (z_ine < 3000) {
        engine_status = engine_start;
      }
      if (z_ine < 20) {
        ap_sequence = guidance_mid;  
      }
      if (delta_range < 25000) {
        ap_sequence = guidance_final;
      }
    }
  }
  if (0 == counter % 2) {
    /* 600Hz cycle */
    StatusController(ip, ine, utdc);
    guidance_control.GuidanceController(ine);
  }
  if (0 == counter % 10) {
    /* 100Hz cycle */
    if (engine_status == engine_Start) {
      ThrustController();
      if (rest_of_miles < 25000) {
        HomingHeadController();
      }
    }
  }
  if (0 == counter % 33) {
    /* 33msec cycle */
    EngineController();
  }
  OutputDiscreteSignals();  
}

void Autopilot::StatusController(INE& ine, UTDC& utdc) {
  /* remaining distance */
  double x_ine = ine.getPositionX;
  double y_ine = ine.getPositionY;
  rest_of_miles = sqrt(std::pow(target_position_x - x_ine, 2.0) + std::pow(target_position_y - y_ine, 2.0));
}

void Autopilot::ThrustController() {
  q_c = k_accel;
}

void Autopilot::HomingHeadController() {
  
}

void Autopilot::OutputDiscreteSignals() {
    if (engine_status == engine_start) {
      discrete_cartridge_starter = 1;
      discrete_intakecover_separation = 1;
      discrete_igniter = 1;
    }
    if (ap_sequence == ap_sq4_missile_seperation) {
      discrete_missile_seperation = 1;
    }
}
