#define buzzerpin 5
const int threshold = 30;

float floatMap(float x,float in_min,float in_max,float out_min,float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  pinMode(buzzerpin,OUTPUT);
  Serial.begin(9600);
  delay(2000);
  digitalWrite(buzzerpin,LOW);
}

void loop() {
  int analog_value = analogRead(4);
  float voltage = floatMap(analog_value,0,4095,0,3.8);
  Serial.print("Analog: "); 
  Serial.print(analog_value); 
  Serial.print(", Voltage: "); 
  Serial.println(voltage);
  delay(1000);
  if(voltage < threshold){
    for (float i=0; i<(voltage*10); i++){
      digitalWrite(buzzerpin,HIGH);
      delay(voltage*100);
      digitalWrite(buzzerpin,LOW);
      delay(voltage*500);
    } 
  }
}
