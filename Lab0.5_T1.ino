// the number of the LED pin
const int ledPin = 5;  // 5 corresponds to GPIO5
const int vrPin = 36;   // 36 corresponds to GPIO36
// setting PWM properties
const int freq = 5000;
const int resolution = 8;
 
void setup(){
  //This function is used to setup LEDC pin with given frequency and resolution. 
  //LEDC channel will be selected automatically.
  //bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);
  //pin select LEDC pin.
  //freq select frequency of pwm.
  //resolution select resolution for LEDC channel. Range is 1-14 bits (1-20 bits for ESP32).
  //The LEDC channel will be selected automatically

  ledcAttach(ledPin, freq, resolution);
  Serial.begin(115200);  
  // set GPIO36 as input
  pinMode(vrPin, INPUT);

}
 
void loop(){

  //bool ledcWrite(uint8_t pin, uint32_t duty);

  // read the voltage level at GPIO36
  int vr_value = analogRead(vrPin);
  // convert  vr_value (range from 0 to 4095) into dutyCycle (range from 0 to 255).
  int dutyCycle = map(vr_value, 0, 4095, 0, 255);
  Serial.println(dutyCycle);
  
  ledcWrite(ledPin, dutyCycle);

  delay(100);

}