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