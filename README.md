# ESP8266 Full Reset Tool

This is a simple project that resets ESP8266 boards to a clean state using a minimal Arduino sketch or a precompiled `.bin` file.

## Files Included

- `reset.ino`: Arduino source code
- `reset.bin`: Precompiled firmware to flash directly

---

## How to Flash

### Option 1: Flash from PC (Windows/Linux/Mac)

#### Requirements:
- USB to Serial adapter (e.g., FTDI, CH340)
- Micro-USB cable
- [ESP8266 Flash Download Tool](https://www.espressif.com/en/support/download/other-tools) or [esptool.py](https://github.com/espressif/esptool)
- Drivers for your USB adapter (if needed)

#### Steps:
1. Connect ESP8266 in **flash mode**:
   - Hold GPIO0 to GND and press RESET.
2. Open **ESP8266 Flash Download Tool**.
3. Select `reset.bin`, map to `0x00000`.
4. Choose COM port and set baud rate (e.g., 115200).
5. Click **Start**.
