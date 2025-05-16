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
