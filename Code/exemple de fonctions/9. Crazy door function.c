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