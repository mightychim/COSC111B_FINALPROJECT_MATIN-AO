#define PHOTORESISTOR_PIN A0
#define GREEN_LED 11
#define YELLOW_LED 12
#define RED_LED 13

// Default thresholds
const int DEFAULT_LOW = 40;
const int DEFAULT_HIGH = 70;

// Current editable thresholds
int LOW_THRESHOLD = DEFAULT_LOW;
int HIGH_THRESHOLD = DEFAULT_HIGH;

String currentMode = "Manual";  // Default mode

// Helper function to check if a string is fully numeric
bool isNumeric(String str) {
  if (str.length() == 0) return false;
  for (int numScan = 0; numScan < str.length(); numScan++) {
    if (!isDigit(str[numScan])) return false;
  }
  return true;
}

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.println("System Ready.");
  Serial.println("Use 'MODE AUTO' or 'MODE MANUAL' to change mode.");
  Serial.println("In MANUAL mode, use 'SET LOW <value>' or 'SET HIGH <value>' to adjust thresholds.");
  Serial.println();
}

void loop() {
  // --- Check for serial input commands ---
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    input.toUpperCase();

    if (input == "MODE AUTO") {
      currentMode = "Automatic";
      LOW_THRESHOLD = DEFAULT_LOW;   // revert to defaults
      HIGH_THRESHOLD = DEFAULT_HIGH;
      Serial.println("Switched to AUTOMATIC mode.");
      Serial.println("Thresholds reverted to default (LOW = 40, HIGH = 70).");
    } 
    else if (input == "MODE MANUAL") {
      currentMode = "Manual";
      Serial.println("Switched to MANUAL mode.");
    } 
    else if (currentMode == "Manual" && input.startsWith("SET LOW ")) {
      String valueStr = input.substring(8);
      valueStr.trim();
      if (isNumeric(valueStr)) {
        int newLow = valueStr.toInt();
        if (newLow >= 0 && newLow < HIGH_THRESHOLD) {
          LOW_THRESHOLD = newLow;
          Serial.print("LOW threshold set to ");
          Serial.println(LOW_THRESHOLD);
        } else {
          Serial.println("Error: Wrong command");
        }
      } else {
        Serial.println("Error: Wrong command");
      }
    } 
    else if (currentMode == "Manual" && input.startsWith("SET HIGH ")) {
      String valueStr = input.substring(9);
      valueStr.trim();
      if (isNumeric(valueStr)) {
        int newHigh = valueStr.toInt();
        if (newHigh > LOW_THRESHOLD && newHigh <= 100) {
          HIGH_THRESHOLD = newHigh;
          Serial.print("HIGH threshold set to ");
          Serial.println(HIGH_THRESHOLD);
        } else {
          Serial.println("Error: Wrong command");
        }
      } else {
        Serial.println("Error: Wrong command");
      }
    } 
    else {
      Serial.println("Error: Wrong command");
    }
    Serial.println();
  }

  int sensorValue = analogRead(PHOTORESISTOR_PIN);

  // Convert reading (0–1023) to integer percentage (0–100)
  int brightnessPercent = map(sensorValue, 0, 1023, 0, 100);

  // Turn off all LEDs first
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  String activeLED = "";
  String environment = "";

  // LED logic
  if (brightnessPercent <= LOW_THRESHOLD) {
    digitalWrite(GREEN_LED, HIGH);
    activeLED = "Green";
  } 
  else if (brightnessPercent >= HIGH_THRESHOLD) {
    digitalWrite(RED_LED, HIGH);
    activeLED = "Red";
  } 
  else {
    digitalWrite(YELLOW_LED, HIGH);
    activeLED = "Yellow";
  }

  // Environment only appears in Automatic mode
  if (currentMode == "Automatic") {
    if (brightnessPercent <= 40) {
      environment = "Cloudy";
    } else {
      environment = "Clear";
    }
  }

  // --- SERIAL OUTPUT ---
  Serial.print("Light Intensity: ");
  Serial.print(brightnessPercent);
  Serial.println("%");

  Serial.print("Current Mode: ");
  Serial.println(currentMode);

  Serial.print("Active LED: ");
  Serial.println(activeLED);

  if (currentMode == "Automatic") {
    Serial.print("Environment: ");
    Serial.println(environment);
  }

  Serial.println(); // blank line for readability
  delay(1500);
}
