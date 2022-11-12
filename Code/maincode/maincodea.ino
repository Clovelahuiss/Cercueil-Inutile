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

void loop() {
  // put your main code here, to run repeatedly:
  if (rand() % 9 == 0) {
    simpleClose();
  }
  else if (rand() % 9 == 1) {
    slow();
  }
  else if (rand() % 9 == 2) {
    motor();
  }
  else if (rand() % 9 == 3) {
    motorG();
  }
  else if (rand() % 9 == 4) {
    motorD();
  }
  else if (rand() % 9 == 5) {
    trollClose();
  }
  else if (rand() % 9 == 6) {
    sleep();
  }
  else if (rand() % 9 == 7) {
    sneak();
  }
  else if (rand() % 9 == 8) {
    matrix();
  }
}
void motor() {
  if (digitalRead(btn) == HIGH) {
    Serial.println("motor");


    //Moving door
    for (pos = 0; pos < 90; pos += 4)
    {
      doorServo.write(pos);
      delay(15);
    }

    // LED ON
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255,   0,   0);
      strip.show();
    }

    // play song
    player.volume(5);
    player.play(2);

    //Moving hand
    for (pos = 0; pos < 180; pos += 6)
    {
      fingerServo.write(pos);
      delay(15);
    }
    digitalWrite(motor1s1, LOW);
    digitalWrite(motor1s2, HIGH);
    digitalWrite(motor2s1, LOW);
    digitalWrite(motor2s2,HIGH) ;
    delay(2000);
    digitalWrite(motor1s1, LOW);
    digitalWrite(motor1s2, LOW);
    digitalWrite(motor2s1, LOW);
    digitalWrite(motor2s2, LOW);


    //hiding hand
    for (pos = 180; pos >= 0; pos -= 6)
    {
      fingerServo.write(pos);
      delay(15);
    }

    // LED OFF
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0,   0,   0);
      strip.show();
    }

    //hiding door
    for (pos = 90; pos >= 0; pos -= 4)
    {
      doorServo.write(pos);
      delay(15);
    }
  }}
  void motorD() {
  if (digitalRead(btn) == HIGH) {
    Serial.println("motor");


    //Moving door
    for (pos = 0; pos < 90; pos += 4)
    {
      doorServo.write(pos);
      delay(15);
    }

    // LED ON
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255,   0,   0);
      strip.show();
    }

    // play song
    player.volume(5);
    player.play(2);

    //Moving hand
    for (pos = 0; pos < 180; pos += 6)
    {
      fingerServo.write(pos);
      delay(15);
    }
    digitalWrite(motor1s1, LOW);
    digitalWrite(motor1s2, LOW);
    digitalWrite(motor2s1, LOW);
    digitalWrite(motor2s2,HIGH) ;
    delay(2000);
    digitalWrite(motor1s1, LOW);
    digitalWrite(motor1s2, LOW);
    digitalWrite(motor2s1, LOW);
    digitalWrite(motor2s2, LOW);


    //hiding hand
    for (pos = 180; pos >= 0; pos -= 6)
    {
      fingerServo.write(pos);
      delay(15);
    }

    // LED OFF
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0,   0,   0);
      strip.show();
    }

    //hiding door
    for (pos = 90; pos >= 0; pos -= 4)
    {
      doorServo.write(pos);
      delay(15);
    }
  }}
  void motorG() {
  if (digitalRead(btn) == HIGH) {
    Serial.println("motor");


    //Moving door
    for (pos = 0; pos < 90; pos += 4)
    {
      doorServo.write(pos);
      delay(15);
    }

    // LED ON
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255,   0,   0);
      strip.show();
    }

    // play song
    player.volume(5);
    player.play(2);

    //Moving hand
    for (pos = 0; pos < 180; pos += 6)
    {
      fingerServo.write(pos);
      delay(15);
    }
    digitalWrite(motor1s1, LOW);
    digitalWrite(motor1s2, HIGH);
    digitalWrite(motor2s1, LOW);
    digitalWrite(motor2s2,LOW) ;
    delay(2000);
    digitalWrite(motor1s1, LOW);
    digitalWrite(motor1s2, LOW);
    digitalWrite(motor2s1, LOW);
    digitalWrite(motor2s2, LOW);


    //hiding hand
    for (pos = 180; pos >= 0; pos -= 6)
    {
      fingerServo.write(pos);
      delay(15);
    }

    // LED OFF
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0,   0,   0);
      strip.show();
    }

    //hiding door
    for (pos = 90; pos >= 0; pos -= 4)
    {
      doorServo.write(pos);
      delay(15);
    }
  }}
  void simpleClose() {
    if (digitalRead(btn) == HIGH) {
      Serial.println("simpleclose");


      //Moving door
      for (pos = 0; pos < 90; pos += 4)
      {
        doorServo.write(pos);
        delay(15);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255,   0,   0);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 180; pos += 6)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding hand
      for (pos = 180; pos >= 0; pos -= 6)
      {
        fingerServo.write(pos);
        delay(15);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 90; pos >= 0; pos -= 4)
      {
        doorServo.write(pos);
        delay(15);
      }

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void simpleClose2() {
    if ((digitalRead(btn) == HIGH) & (Cond1 == 0)) {
      Serial.println("simpleclose2");

      //Moving door
      for (pos = 0; pos < 90; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }
      prevMillis = millis() ;
      Cond1 = 1 ;
    }

    if ((Cond1 == 1) & (millis() - prevMillis > 800)) {

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255,   255,   0);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 100; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }
      prevMillis = millis() ;
      Cond1 = 2 ;
    }

    if ((Cond1 == 2) & (millis() - prevMillis > 1000)) {
      for (pos = 100; pos < 129; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding hand
      for (pos = 129; pos >= 0; pos -= 5)
      {
        fingerServo.write(pos);
        delay(15);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 90; pos >= 0; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }
      Cond1 = 0 ;

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void slow() {

    if ((digitalRead(btn) == HIGH) & (Cond2 == 0)) {
      Serial.println("slow");

      //Moving door
      for (pos = 0; pos < 75; pos += 1)
      {
        doorServo.write(pos);
        delay(15);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255,   0,   255);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 129; pos += 1)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding hand
      for (pos = 129; pos >= 0; pos -= 1)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 75; pos >= 45; pos -= 1)
      {
        doorServo.write(pos);
        delay(15);
      }

      prevMillis = millis() ;
      Cond2 = 1;

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   0,   0);
        strip.show();
      }
    }

    if ((Cond2 == 1) & (millis() - prevMillis > 1000)) {

      //hiding door
      for (pos = 45; pos >= 0; pos -= 4)
      {
        doorServo.write(pos);
        delay(15);
      }

      prevMillis = millis() ;
      Cond2 = 0;

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void crazydoor() {
    if (digitalRead(btn) == HIGH) {
      Serial.println("Crazydoor");

      //Moving door
      for (pos = 0; pos < 45; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 45; pos >= 0; pos -= 5)
      {
        doorServo.write(pos);
        delay(15);
      }

      //Moving door
      for (pos = 0; pos < 30; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 30; pos >= 0; pos -= 15)
      {
        doorServo.write(pos);
        delay(15);
      }

      //Moving door
      for (pos = 0; pos < 45; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 45; pos >= 0; pos -= 5)
      {
        doorServo.write(pos);
        delay(15);
      }

      //Moving door
      for (pos = 0; pos < 75; pos += 8)
      {
        doorServo.write(pos);
        delay(15);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   255,   0);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 129; pos += 3)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding hand
      for (pos = 129; pos >= 0; pos -= 3)
      {
        fingerServo.write(pos);
        delay(15);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i,  0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 75; pos >= 0; pos -= 10)
      {
        doorServo.write(pos);
        delay(15);
      }

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void serious() {
    if ((digitalRead(btn) == HIGH) & (Cond3 == 0)) {
      Serial.println("serious");

      //Moving door
      for (pos = 0; pos < 75; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   255,   255);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 40; pos += 1)
      {
        fingerServo.write(pos);
        delay(15);
      }

      prevMillis = millis() ;
      Cond3 = 1;
    }

    if ((Cond3 == 1) & (millis() - prevMillis > 800)) {
      //hiding door
      for (pos = 75; pos >= 50; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 50; pos < 75; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 75; pos >= 50; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 50; pos < 75; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      prevMillis = millis() ;
      Cond3 = 2;
    }

    if ((Cond3 == 2) & (millis() - prevMillis > 1000)) {
      //Moving hand
      for (pos = 40; pos < 129; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding hand
      for (pos = 129; pos >= 0; pos -= 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i,  0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 75; pos >= 0; pos -= 1)
      {
        doorServo.write(pos);
        delay(15);
      }
      Cond3 = 0;

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void trollClose() {
    if ((digitalRead(btn) == HIGH) & (Cond4 == 0)) {
      Serial.println("troll");
      //Moving door
      for (pos = 0; pos < 75; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   0,   255);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 127; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding door
      for (pos = 75; pos >= 50; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      prevMillis = millis() ;
      Cond4 = 1;
    }

    if ((Cond4 == 1) & (millis() - prevMillis > 2000)) {
      //shaking door
      for (pos = 50; pos < 75; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }
      for (pos = 75; pos >= 50; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }
      for (pos = 50; pos < 75; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      prevMillis = millis() ;
      Cond4 = 2;
    }

    if ((Cond4 == 2) & (millis() - prevMillis > 500)) {
      //hiding hand
      for (pos = 127; pos >= 0; pos -= 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 75; pos >= 0; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }
      Cond4 = 0;

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void sleep() {
    if ((digitalRead(btn) == HIGH) & (Cond5 == 0)) {
      Serial.println("AAA");


      //Moving door
      for (pos = 0; pos < 70; pos += 1)
      {
        doorServo.write(pos);
        delay(30);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255,   0,   0);
        strip.show();
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 70; pos >= 0; pos -= 6)
      {
        doorServo.write(pos);
        delay(15);
      }

      prevMillis = millis() ;
      Cond5 = 1;
    }

    if ((Cond5 == 1) & (millis() - prevMillis > 2000)) {
      //Moving door
      for (pos = 0; pos < 90; pos += 2)
      {
        doorServo.write(pos);
        delay(30);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   255,   0);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 180; pos += 10)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding hand
      for (pos = 180; pos >= 0; pos -= 10)
      {
        fingerServo.write(pos);
        delay(15);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i,  0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 90; pos >= 0; pos -= 10)
      {
        doorServo.write(pos);
        delay(15);
      }
      Cond5 = 0;

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void sneak() {
    if ((digitalRead(btn) == HIGH) & (Cond6 == 0)) {
      Serial.println("sneak");

      //Moving door
      for (pos = 0; pos < 50; pos += 1)
      {
        doorServo.write(pos);
        delay(30);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255,   255,   0);
        strip.show();
      }

      prevMillis = millis() ;
      Cond6 = 1;
    }

    if ((Cond6 == 1) & (millis() - prevMillis > 2000)) {
      //Moving hand
      for (pos = 0; pos < 40; pos += 1)
      {
        fingerServo.write(pos);
        delay(30);
      }

      for (pos = 50; pos < 75; pos += 4)
      {
        doorServo.write(pos);
        delay(15);
      }

      for (pos = 40; pos < 90; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      //hiding hand
      for (pos = 90; pos >= 70; pos -= 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      for (pos = 70; pos < 90; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      for (pos = 90; pos >= 70; pos -= 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      for (pos = 70; pos < 129; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      for (pos = 129; pos >= 0; pos -= 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i,  0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 75; pos >= 0; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      Cond6 = 0;

      // play song
      player.volume(5);
      player.play(2);
    }
  }

  void matrix() {
    if ((digitalRead(btn) == HIGH) & (Cond7 == 0)) {
      Serial.println("matrix");

      //Moving door
      for (pos = 0; pos < 75; pos += 3)
      {
        doorServo.write(pos);
        delay(15);
      }

      // LED ON
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255,   0,   255);
        strip.show();
      }

      //Moving hand
      for (pos = 0; pos < 80; pos += 4)
      {
        fingerServo.write(pos);
        delay(15);
      }

      for (pos = 80; pos < 129; pos += 1)
      {
        fingerServo.write(pos);
        delay(30);
      }

      prevMillis = millis() ;
      Cond7 = 1;
    }

    if ((Cond7 == 1) & (millis() - prevMillis > 2000)) {

      for (pos = 129; pos >= 0; pos -= 4)
      {
        fingerServo.write(pos);
        delay(10);
      }

      // LED OFF
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,   0,   0);
        strip.show();
      }

      //hiding door
      for (pos = 75; pos >= 0; pos -= 3)
      {
        doorServo.write(pos);
        delay(15);
      }
      Cond7 = 0;

      // play song
      player.volume(5);
      player.play(2);
    }
  }
