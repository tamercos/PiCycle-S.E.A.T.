#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(int trigger1, int echo1, int vibDisc1, int trigger2, int echo2, int vibDisc2, int trigger3, int echo3, int vibDisc3);
    double distance1(int timeout1);
    double distance2(int timeout2);
    double distance3(int timeout3);
    int getVibDisc1();
    int getVibDisc2();
    int getVibDisc3();

  private:
    void recordPulseLength1();
    void recordPulseLength2();
    void recordPulseLength3();

    //Defining wiringPi pins
    int trigger1 = 0;
    int echo1 = 2;
    int vibDisc1 = 3;

    int trigger2 = 23;
    int echo2 = 24;
    int vibDisc2 = 25;

    int trigger3 = 27;
    int echo3 = 28;
    int vibDisc3 = 29;

    volatile long startTimeUsec1 = 0;
    volatile long startTimeUsec2 = 0;
    volatile long startTimeUsec3 = 0;
    volatile long endTimeUsec1 = 0;
    volatile long endTimeUsec2 = 0;
    volatile long endTimeUsec3 = 0;
    double distanceMeters1 = 0;
    double distanceMeters2 = 0;
    double distanceMeters3 = 0;
    long travelTimeUsec1 = 0;
    long travelTimeUsec2 = 0;
    long travelTimeUsec3 = 0;
    long now1 = 0;
    long now2 = 0;
    long now3 = 0;
};

#endif
