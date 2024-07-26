// function for getting the moist percentage value:
int getMoistVal(uint8_t powerPin, uint8_t valuePin, int measureCounter) {

  // used for keeping time
  unsigned long startTime = 0;
  unsigned long measureInterval = 50;

  int count = 0;
  int newVal = 0;

  int moistAbsolute = 0;
  int moistRelative = 0;
  int moistSum = 0;

  // measure multiple times depending on counter
  while (count < measureCounter) {
    
    if (millis() - startTime >= measureInterval) { 
      startTime = millis();
      digitalWrite(powerPin, HIGH);
      delay(10);
      newVal = analogRead(valuePin);
      digitalWrite(powerPin, LOW);
      moistSum += newVal;
      count++;
 
    }
  }

  // calculate the average of the measurments, and convert into 0-100% scale
  moistAbsolute = moistSum / measureCounter;
  moistRelative = map(moistAbsolute, 0, 1024, 0, 100);
  moistRelative = 100 - moistRelative;

  return moistRelative;
}


