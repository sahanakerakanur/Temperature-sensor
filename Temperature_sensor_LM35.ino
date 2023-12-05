// Define the analog pin to which LM35 is connected
const int pin_lm35 = A0;

// Define the onboard LED pin
const int pin_led = 13;

void setup() {
pinMode(pin_led, OUTPUT);                                                                        // Set LED pin as OUTPUT
Serial.begin(9600);                                                                                       // Optional for debugging
}

void loop() {
float temperatureCelsius=ReadTemperatureFromLM35();
 // Output temperature value to Serial Monitor (optional)
  Serial.print("Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.println(" °C");

// Check the temperature conditions and control the LED and according to that Blink LED every 250       milliseconds or Blink LED every 500 milliseconds
  int blink_interval = (temperatureCelsius < 30.0) ? 250 : 500;
  BlinkOnboardLED(blink_interval);
}

float ReadTemperatureFromLM35() {
  int sensor_value = analogRead(pin_lm35);
  return (sensor_value * 5.0 / 1023) * 100;
}

void BlinkOnboardLED(int interval) {
  digitalWrite(pin_led, HIGH);
  delay(interval);
  digitalWrite(pin_led, LOW);
  delay(interval);
}
