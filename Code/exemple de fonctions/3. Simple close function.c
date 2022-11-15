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