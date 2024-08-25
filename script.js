function fetchPlantData() {
    fetch('http://your_esp_ip_address/')
    .then(response => response.text())
    .then(data => {
        document.querySelector('#temperature').innerText = data.match(/Temperature: (\d+.\d+)/)[1] + " &deg;C";
        document.querySelector('#humidity').innerText = data.match(/Humidity: (\d+.\d+)/)[1] + " %";
        document.querySelector('#soil-moisture').innerText = data.match(/Soil Moisture: (\d+)/)[1];
        document.querySelector('#light-level').innerText = data.match(/Light Level: (\d+)/)[1];
        document.querySelector('#water-pump').innerText = data.match(/Water Pump: (ON|OFF)/)[1];
        document.querySelector('#led-light').innerText = data.match(/LED Light: (ON|OFF)/)[1];
    });
}

// Update plant data every 10 seconds
setInterval(fetchPlantData, 10000);
fetchPlantData(); // Fetch data immediately on load
