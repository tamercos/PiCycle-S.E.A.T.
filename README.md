# PiCycle S.E.A.T.
The PiCycle S.E.A.T. (Situational and Environmental Awareness Technology) aims to combine ultrasonic sensors with a Raspberry Pi utilising haptic feedback with the objective of increasing road safety for cyclists.

HC-SR04 ultrasonic sensors placed under the seat of the bicycle facing backwards will detect the approach of foreign objects and alert the cyclist via small vibration motors situated within the rider's helmet.

![Alt Text](https://media.giphy.com/media/4ZaTwU3GVlwwAR3EJX/giphy.gif)

## Parts used
- 3x HC-SR04 ultrasonic sensors
- 3D printed parts found under the "PiCycleSEAT 3D Print" folder
- 5x M2.5 x 8mm screws for the housing lid
- 4x M2.5 x 6mm screws for Raspberry Pi

## Circuitry used
TBC

## Run programme
`g++ PiCycleSEAT.cpp -o run -lwiringPi libSonar.cpp`

Then `./run`
