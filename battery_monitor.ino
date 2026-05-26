const int LED_PIN = 13;
unsigned long previousTime = 0;
const unsigned long interval = 200;

enum SystemState 
{
  ENGINE_OFF,
  NORMAL_CHARGING,
  OVERVOLTAGE_FAULT
};

SystemState currentState = ENGINE_OFF;

void setup() 
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("AUTOMOTIVE BATTERY MONITOR SYSTEM INITIALIZED.");
}

void loop() 
{
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) 
  {
    previousTime = currentTime;

    int rawADC = analogRead(A0);
    float voltage = (rawADC / 1023.0) * 16.0;

    if (voltage > 15.0)
      currentState = OVERVOLTAGE_FAULT;
    else if (voltage >= 13.5)
      currentState = NORMAL_CHARGING;
    else
      currentState = ENGINE_OFF;

    digitalWrite(LED_PIN, currentState == OVERVOLTAGE_FAULT ? HIGH : LOW);

    Serial.print("Battery Voltage V : ");
    Serial.print(voltage);
    Serial.print(" , System State ID : ");
    Serial.println(currentState);
  }
}
