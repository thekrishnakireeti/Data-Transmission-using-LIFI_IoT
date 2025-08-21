# Data-Transmission-using-LIFI_IoT
Li-Fi communication system using Arduino UNO, LED, and LDR. Data is transmitted as binary by rapidly switching the LED ON/OFF and decoded by the receiver. Provides high-speed, secure, interference-free communication ideal for sensitive environments.
Li-Fi Communication using Arduino
📌 Overview
Li-Fi (Light Fidelity) is an emerging wireless communication technology that uses visible light instead of radio waves to transmit data. This project demonstrates a simple Li-Fi system using Arduino UNO, LED, and LDR module to achieve secure and high-speed data transfer.
The transmitter encodes binary data by rapidly switching an LED ON (1) and OFF (0). The receiver, equipped with an LDR sensor, detects these light variations and decodes them back into the original message.
Unlike Wi-Fi, Li-Fi signals cannot pass through walls, making communication secure, interference-free, and ideal for sensitive environments.
⚡ Features
High-speed data transmission using visible light
Secure communication (light signals stay within a physical space)
Immune to electromagnetic interference (safe in hospitals and aircraft)
Low-cost prototype using simple Arduino components
🛠️ Hardware Requirements
Arduino UNO (x2) – Transmitter & Receiver
LED (High-intensity, preferably white)
LDR (Light Dependent Resistor) module
Resistors and breadboard
Jumper wires & USB cable
🔧 Working Principle
Transmitter Section
Arduino UNO controls an LED.
Data is converted into binary and transmitted as ON/OFF light pulses.
Receiver Section
LDR sensor detects changes in light intensity.
Arduino UNO decodes the received binary signals.
The message is reconstructed and displayed.
🚀 Applications
Hospitals & medical equipment rooms (no EMI issues)
Aircraft communication systems
Nuclear plants & secure facilities
Indoor wireless data transfer projects
⚙️ Setup & Usage
Connect the LED to Arduino UNO (transmitter).
Connect LDR module to another Arduino UNO (receiver).
Upload transmitter and receiver codes via Arduino IDE.
Run the system → Enter a message → Observe decoded output on the receiver serial monitor.

📂 Repository Structure
/LiFi-Arduino
│── transmitter_code/      # Arduino code for LED transmission
│── receiver_code/         # Arduino code for LDR decoding
│── circuit_diagram.png    # Connection schematic
│── README.md              # Project documentation
🔒 Security Advantage
Since Li-Fi signals cannot penetrate walls, the communication is confined to a physical space, making it naturally more secure compared to Wi-Fi.
📖 Conclusion
This project showcases the fundamental working of Li-Fi technology using Arduino, LED, and LDR. It serves as a low-cost prototype to explore how visible light can be harnessed for high-speed, secure, and interference-free wireless communication.
