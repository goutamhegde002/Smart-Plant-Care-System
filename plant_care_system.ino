#include <Wire.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace these with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Initialize DHT sensor
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Define sensor and actuator pins
#define SOIL_MOISTURE_PIN A0
#define LIGHT_SENSOR_PIN A1
#define WATER_PUMP_PIN D1
#define LED_LIGHT_PIN D2

// Initialize Wi-Fi and web server
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  dht.begin();
  
  pinMode(WATER_PUMP_PIN, OUTPUT);
  pinMode(LED_LIGHT_PIN, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to Wi-Fi");

  // Start web server
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
  int lightLevel = analogRead(LIGHT_SENSOR_PIN);
  
  String html = "<html><body>";
  html += "<h1>Smart Plant Care System</h1>";
  html += "<p>Temperature: " + String(temperature) + " &deg;C</p>";
  html += "<p>Humidity: " + String(humidity) + " %</p>";
  html += "<p>Soil Moisture: " + String(soilMoisture) + "</p>";
  html += "<p>Light Level: " + String(lightLevel) + "</p>";
  
  // Control water pump and light based on sensor readings
  if (soilMoisture < 300) {
    digitalWrite(WATER_PUMP_PIN, HIGH);
    html += "<p>Water Pump: ON</p>";
  } else {
    digitalWrite(WATER_PUMP_PIN, LOW);
    html += "<p>Water Pump: OFF</p>";
  }

  if (lightLevel < 500) {
    digitalWrite(LED_LIGHT_PIN, HIGH);
    html += "<p>LED Light: ON</p>";
  } else {
    digitalWrite(LED_LIGHT_PIN, LOW);
    html += "<p>LED Light: OFF</p>";
  }

  html += "</body></html>";

  server.send(200, "text/html", html);
}
