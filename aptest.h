typedef struct tagInputParameter {
  int l_serial_launch_mode;
} InputParameter;

typedef struct tagINE {
  double nx_acceleration;
  double ny_acceleration;
  double nz_acceleration:
  double p_angular_velocity;
  double q_angular_velocity;
  double r_angular_velocity;
  double x_position;
  double y_position;
  double z_position;
  double psi_angle;
  double theta_angle;
  double phi_angle;
} INE;

typedef struct tagHormingHead {
  int flag_lockon;
  double target_angle;
  double target_range;
} HormingHead;

typedef struct tagUTDC {
  double x_updated_target;
  double y_updated_target;
} UTDC;
