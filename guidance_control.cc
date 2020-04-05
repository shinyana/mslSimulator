#include "guidance_control.h"

void Guidance_Control::GuidanceControl() {

}

void Guidance_Control::UpdateGain() {

}

void Guidance_Control::Filtering() {

}

void Guidance_Control::GuidanceController() {
  UpdateGain();
  Filtering();
  Roll();
  Pitch();
  Yaw();
  DistributionCommand();
}

void Guidance_Control::Roll() {

}

void Guidance_Control::Yaw() {

}

void Guidance_Control::Pitch() {

}

void Guidance_Control::DistributionCommand() {

}
