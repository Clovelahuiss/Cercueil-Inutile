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