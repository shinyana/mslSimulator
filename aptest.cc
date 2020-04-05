#include "aptest.h"
#include "autopilot.h"

int main(void){
  InputParameter ip = { 1
                        };

  INE ine = { 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 0.0, 0.0
              };
  double engine_rpm = 0.0;

  int simulation_counter = 0;
  double clock_rate = 1200;
  double halt_simulation_at_limit = 100;

  /* create instance of autopilot */
  Autopilot ap = Autopilot();

  while (halt_simulation_at_limit > simulation_counter / clock_rate) {
    ap.SequenceController(ip, ine, engine_rpm);
    engine_rpm += halt_simulation_at_limit / clock_rate;
    simulation_counter++;
  }
}
