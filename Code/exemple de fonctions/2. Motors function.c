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