# 📡 simple_rf24_transmitter

A **simple 6-channel transmitter** built using the **nRF24L01** module and **ESP32**, ideal for remote control applications like robotics or RC vehicles.

> 🔗 Inspired by a fantastic [Arduino forum post](https://forum.arduino.cc/t/simple-nrf24l01-2-4ghz-transceiver-demo/405123/37) that outlines the basics of nRF24L01 communication.

---

## 🚀 Features

- ✅ Uses the **nRF24L01 2.4GHz transceiver**
- ✅ Based on the **ESP32** development board
- ✅ Equipped with:
  - 🎮 2 x Joysticks (4 analog channels)
  - 🔘 2 x Push Buttons (2 digital channels)
- ✅ Easily expandable to **more channels**
- ✅ Lightweight and easy to modify

---

## 🛠️ Hardware Setup

| Component       | Quantity |
|----------------|----------|
| ESP32           | 1        |
| nRF24L01 Module | 1        |
| Joysticks       | 2        |
| Push Buttons    | 2        |
| Breadboard + Wires | As needed |

The transmitter sends data via the nRF24L01 module, combining joystick and button values into a single data packet.

---

## 📦 Data Structure

Make sure your data packet is **less than 32 bytes**, the maximum size supported by the nRF24L01.

```cpp
struct dt {
  int j1;
  int j2;
  int j3;
  int j4;
  bool b1;
  bool b2;
};
```

⚠️ Important: If you expand the number of channels, ensure the struct still fits within 32 bytes.


---

## 🔌 Pin Configuration

### 📡 nRF24L01 to ESP32 Connections

The nRF24L01 module communicates with the ESP32 using the SPI protocol. Below is the recommended wiring:

| nRF24L01 Pin | ESP32 Pin | Description             |
| ------------ | --------- | ----------------------- |
| VCC          | 3.3V      | Power supply (3.3V)     |
| GND          | GND       | Ground                  |
| CE           | D15        | Chip Enable             |
| CSN (CS)     | D2       | Chip Select Not         |
| SCK          | D18       | SPI Clock               |
| MOSI         | D23       | SPI Master Out Slave In |
| MISO         | D19       | SPI Master In Slave Out |

> ⚠️ **Note:** Ensure that the nRF24L01 module is powered with 3.3V. Supplying 5V can damage the module. Additionally, it's advisable to place a 10µF capacitor between the VCC and GND pins close to the module to stabilize the power supply.

### 🎮 Joystick Connections

Each joystick provides two analog outputs corresponding to the X and Y axes. Connect them to the ESP32's analog-capable GPIO pins:

| Joystick Axis | ESP32 Pin | Description  |
| ------------- | --------- | ------------ |
| Left X (j1)   | (D13)  | Analog input |
| Left Y (j2)   | (D12)  | Analog input |
| Right X (j3)  | (D14)  | Analog input |
| Right Y (j4)  | (D27)  | Analog input |

### 🔘 Push Button Connections

Connect the push buttons to digital GPIO pins with internal pull-up resistors enabled in the code:

| Button | ESP32 Pin | Description   |
| ------ | --------- | ------------- |
| b1     | D26       | Digital input |
| b2     | D25       | Digital input |

> 🛠️ **Note:** When configuring the buttons in your code, set the pin mode to `INPUT_PULLUP` to use the ESP32's internal pull-up resistors. This setup assumes that the other side of the button is connected to GND.

