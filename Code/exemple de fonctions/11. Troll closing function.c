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