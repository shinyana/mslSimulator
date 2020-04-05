class Guidance_Control {
  private:
    void UpdateGain();
    void Filtering();
    void Roll();
    void Pitch();
    void Yaw();
    void DistributionCommand(); 
  public:
    GuidanceControl();
    void GuidanceController(INE& ine);
};
