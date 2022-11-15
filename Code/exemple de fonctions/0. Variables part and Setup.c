#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <HCSR04.h>
#include <stdio.h>
#include <stdlib.h>

#define PIXEL_PIN    12  // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 144  // Number of NeoPixels


// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;
int motor1s1 = 4;
int motor1s2 = 5;
int motor2s1 = 6;
int motor2s2 = 7;
int btn = 13;
int pos = 0;
long unsigned prevMillis = 0;
Servo doorServo;
Servo fingerServo;

int Cond1 = 0;
int Cond2 = 0;
int Cond3 = 0;
int Cond4 = 0;
int Cond5 = 0;
int Cond6 = 0;
int Cond7 = 0;


Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  // Init USB serial port for debugging
  Serial.begin(9600);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
  randomSeed(analogRead(0));
  pinMode (btn, INPUT);
  fingerServo.attach(9);
  fingerServo.write(0);
  doorServo.attach(10);
  doorServo.write(0);
  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");

  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}