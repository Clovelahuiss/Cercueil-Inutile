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