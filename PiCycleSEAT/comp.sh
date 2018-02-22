#!/bin/bash
g++ PiCycleSEAT.cpp -o run -lwiringPi libSonar.cpp
./run