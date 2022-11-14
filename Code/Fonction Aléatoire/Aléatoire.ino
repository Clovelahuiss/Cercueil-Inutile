
void setup() {



randomSeed(analogRead(0));



void loop() {


if (rand() % 5 == 0) {
fonction1();
}
else if (rand() % 5== 1) {
fonction2();
}
else if (rand() % 5 == 2) {
fonction3();
}
else if (rand() % 5 == 3) {
fonction4();
}
else if (rand() % 5 == 4) {
fonction5();
}
}

