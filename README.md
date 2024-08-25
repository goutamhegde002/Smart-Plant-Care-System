# Smart Plant Care System

## Description
Build a system to monitor soil moisture, light levels, and temperature for plants and automate watering and light adjustment. The system uses sensors to gather environmental data and actuators to control watering and lighting based on sensor readings.

## Project Structure

```
smart-plant-care-system/
├── src/
│   ├── plant_care_system.ino
├── web/
│   ├── index.html
│   ├── styles.css
│   ├── script.js
└── README.md
```


## Components
- **Microcontroller**: ESP8266 or similar with Wi-Fi capability
- **Sensors**: DHT22 (Temperature and Humidity), Analog Soil Moisture Sensor, Analog Light Sensor
- **Actuators**: Relay Module for Water Pump, Relay Module for LED Grow Lights
- **Web Server**: Hosted on the microcontroller

## How to Use

### 1. Microcontroller Setup
1. Open `plant_care_system.ino` in the Arduino IDE.
2. Replace `your_SSID` and `your_PASSWORD` with your Wi-Fi credentials.
3. Upload the code to your microcontroller.

### 2. Web Dashboard
1. Upload `index.html`, `styles.css`, and `script.js` to your web server.
2. Update the `fetchPlantData` URL in `script.js` to point to your microcontroller's IP address.

### 3. Accessing the Dashboard
1. Open a web browser and navigate to the URL where your web dashboard is hosted.
2. View and control the plant care system remotely.

## Deployment
1. Ensure your microcontroller is connected to Wi-Fi.
2. Deploy the web dashboard files to a web server or host it locally on the microcontroller.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements.

## Notes
- Ensure the sensors and actuators are correctly wired to the microcontroller.
- Adjust sensor thresholds and actuator settings based on your specific plant care needs.
