// Define constants for the number of piezos and the pins they are connected to
const int NUM_PIEZOS = 4;
const int PIEZO_PINS[NUM_PIEZOS] = {A0, A1, A2, A3};

// Initialize variables to keep track of the count for each piezo
int piezoCounts[NUM_PIEZOS] = {0, 0, 0, 0};

void setup() {
  // Set up the serial communication for debugging output
  Serial.begin(9600);

  // Set up each piezo as an input
  for (int i = 0; i < NUM_PIEZOS; i++) {
    pinMode(PIEZO_PINS[i], INPUT);
  }
}

void loop() {
  // Check each piezo to see if it has been pressed
  for (int i = 0; i < NUM_PIEZOS; i++) {
    if (analogRead(PIEZO_PINS[i]) > 500) { // Check if the analog value is above a threshold
      // Increment the count for this piezo
      piezoCounts[i]++;

      // Print the count for this piezo
      //Serial.print("Player ");
      //Serial.print(i+1);
      //Serial.print(" count: ");
      //Serial.println(piezoCounts[i]);
      Serial.write(1);
      Serial.flush();
    }
  }

  // Wait a short time to debounce the piezos
  delay(50);
}
