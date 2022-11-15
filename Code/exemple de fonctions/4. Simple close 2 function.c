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