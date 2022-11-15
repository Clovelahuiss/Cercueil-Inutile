void loop() {
  // put your main code here, to run repeatedly:
  if (rand() % 9 == 0) {
    simpleClose();
  }
  else if (rand() % 9 == 1) {
    slow();
  }
  else if (rand() % 9 == 2) {
    motor();
  }
  else if (rand() % 9 == 3) {
    motorG();
  }
  else if (rand() % 9 == 4) {
    motorD();
  }
  else if (rand() % 9 == 5) {
    trollClose();
  }
  else if (rand() % 9 == 6) {
    sleep();
  }
  else if (rand() % 9 == 7) {
    sneak();
  }
  else if (rand() % 9 == 8) {
    matrix();
  }
}