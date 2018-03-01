# PiCycle S.E.A.T.
The PiCycle S.E.A.T. (Situational and Environmental Awareness Technology) aims to combine ultrasonic sensors with haptic feedback for cyclists with the objective of increasing road safety.

HC-SR04 ultrasonic sensors placed under the seat of the bicycle facing backwards will detect the approach of foreign objects and alert the cyclist via small vibration motors situated within the rider's helmet.

## Run programme
`g++ PiCycleSEAT.cpp -o run -lwiringPi libSonar.cpp`

Then `./run`
