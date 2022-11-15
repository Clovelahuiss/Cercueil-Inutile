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
