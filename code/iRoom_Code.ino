#include <DHT.h>
#include <FirebaseESP32.h>
#include <WiFi.h>

#define FIREBASE_HOST "longcar-ae205-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "owIZwzmStVUgvBFRpoqLr1UpoUJDoWvO5hi4VORM"

#define WIFI_SSID "SEACAS2023-ITI" 
#define WIFI_PASSWORD "h@ckath0n" 

#define DHTPIN 8    
#define s1 3
#define s2 4
#define light 5
#define DHTTYPE DHT22  

DHT dht(DHTPIN, DHTTYPE);
FirebaseData fbdo;


int state;
int MAX=100;
int count=0;
int temperature, humidity;

void setup() {
  
  Serial.begin(9600);
  delay(1000);
  
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(light, OUTPUT);
  
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to wifi ... ");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  turnOnOff();
  // Serial.print("Temperature: ");
  // Serial.print(temperature);
  // Serial.print("*C  ");
  // Serial.print("Humidity: ");
  // Serial.print(humidity);
  // Serial.println("%  ");
  // Firebase.setInt(fbdo,"temp", temperature);
  // Firebase.setInt(fbdo,"hum", humidity);
  delay(1000);
}

void turnOnOff(){
  //in
  if((state == 0) && (digitalRead(s1)==LOW)){
    state = 1;
  }
  else if((state == 1) && (digitalRead(s2)== LOW)){
    count = count + 1;
    //totalpeople = totalpeople + 1;
    state = 3;
  }

  //out
  else if((state == 0) && (digitalRead(s2)==LOW)){
    state = 2;
  }
  else if((state == 2) && (digitalRead(s1)==LOW)){
    count = count - 1;
    state = 3;
  }
  else if((state == 3) && (digitalRead(s1)==HIGH) && (digitalRead(s2)==HIGH)){
    state = 0;
  }
  if(count == 0){
    digitalWrite(light, LOW);
  }else if(people > 0){
    digitalWrite(light, HIGH);
  }

}

void turnOnOff2(){
  Serial.println("binary cavalue of s1 is ");
  Serial.print(digitalRead(s1));
   if(digitalRead(s1)==LOW){
    if(digitalRead(s1)==HIGH){
      if(digitalRead(s2)==LOW){
        Serial.println("binary cavalue of s2 is ");
        Serial.print(digitalRead(s2));

        count = count + 1;
        Serial.println("Comin");
        // while(digitalRead(s1)==HIGH);
      }
    }
  }

  if(digitalRead(s2)==LOW){
    while(digitalRead(s2)==HIGH){
      if(digitalRead(s1)==LOW){
        count--;
        Serial.println("Comin");
        if(count < 0) count = 0;
        while(digitalRead(s2)==HIGH);
      }
    }
  }
 // Serial.println(count);
  Firebase.setInt(fbdo, "people", count);
  if(count>0){
    digitalWrite(light,HIGH);
  }
  else 
  digitalWrite(light,LOW);
}



