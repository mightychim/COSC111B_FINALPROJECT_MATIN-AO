#define THERMISTOR_PIN A0
#define PHOTORESISTOR_PIN A2
#define LED_PIN 12      
#define BUZZER_PIN 11   

const float TEMP_THRESHOLD = 45.0; // Celsius


int LIGHT_THRESHOLD; 
const float BRIGHTNESS_SAFETY_FACTOR = 1.5; 
const float THERMISTOR_NOMINAL = 10000.0;
const float B_COEFFICIENT = 3950.0;
const float TEMP_NOMINAL_K = 298.15; // 25C + 273.15
const float SERIES_RESISTOR = 10000.0;


float readTemperature();
int readBrightness();
void setAlarm(float temperature, int brightness); 

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

 
  int ambient_reading = analogRead(PHOTORESISTOR_PIN); 
  
  //Threshold = Ambient * Safety Factor
  LIGHT_THRESHOLD = ambient_reading * BRIGHTNESS_SAFETY_FACTOR;


  Serial.println("--- System Initialized ---");
  Serial.print("Ambient Brightness Set To: ");
  Serial.println(ambient_reading); 
  Serial.print("Dynamic Light Threshold Set To: ");
  Serial.println(LIGHT_THRESHOLD); 
  Serial.println("--------------------------");
}

void loop() {
  float temperature = readTemperature();
  int brightness = readBrightness();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Brightness: ");
  Serial.println(brightness);

  setAlarm(temperature, brightness);

  delay(500); 
}

float readTemperature() {
  int analogValue = analogRead(THERMISTOR_PIN);
  float voltage = analogValue * (5.0 / 1023.0);
  float resistance = (5.0 - voltage) * SERIES_RESISTOR / voltage; 
  
  float temperature = 1 / (log(resistance / THERMISTOR_NOMINAL) / B_COEFFICIENT + 1 / TEMP_NOMINAL_K) - 273.15;
  return temperature;
}

int readBrightness() {
  return analogRead(PHOTORESISTOR_PIN);
}

void setAlarm(float temperature, int brightness) {
  // check both temp and brightness
  bool fireDetected = (temperature >= TEMP_THRESHOLD) && (brightness >= LIGHT_THRESHOLD); 
  
  if (fireDetected) {
   
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 3000); 
    
    delay(100); 
    
    digitalWrite(LED_PIN, LOW);
    
    delay(100); 
    
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN); 
  }
}