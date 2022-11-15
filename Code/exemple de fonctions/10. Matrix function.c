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