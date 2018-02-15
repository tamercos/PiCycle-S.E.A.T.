#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(int trigger1, int echo1, int trigger2, int echo2, int motor1, int motor2);
    double distance1(int timeout);
    double distance2(int timeout);

  private:
    void recordPulseLength1();
    void recordPulseLength2();
    int trigger1;
    int echo1;
    int trigger2;
    int echo2;
    int motor1;
    int motor2;
    volatile long startTimeUsec1;
    volatile long startTimeUsec2;
    volatile long endTimeUsec1;
    volatile long endTimeUsec2;
    double distanceMeters1;
    double distanceMeters2;
    long travelTimeUsec1;
    long travelTimeUsec2;
    long now1;
    long now2;
};

#endif