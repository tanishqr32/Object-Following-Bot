# 🛰️ Object-Following Bot

> **Real-time YOLO-powered rover that locks onto a target and never lets go**  
> Python + OpenCV + PyTorch on an **RTX GPU**, talking over **PySerial** to an **Arduino Mega** that drives twin DC motors through a **20 A Rhino H-bridge**. Built for autonomous tracking, navigation and pure robotics fun. :contentReference[oaicite:0]{index=0}

<p align="center">
  <img src="Media/bot.jpeg" width="680" alt="demo gif"/>
</p>

[![Build YOLO model](https://img.shields.io/badge/YOLOv8-custom--trained-ff69b4?logo=yolov5&logoColor=white)](#model-training)  
[![Made with OpenCV](https://img.shields.io/badge/OpenCV-4.x-blue?logo=opencv)](#software-stack)  
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

---

## Table of Contents

1. [Features](#features)
2. [Bill of Materials](#bill-of-materials)
3. [Software Stack](#software-stack)
4. [Quick Start](#quick-start)
5. [How It Works](#how-it-works)
6. [Model Training](#model-training)
7. [Troubleshooting](#troubleshooting)
8. [Roadmap](#roadmap)
9. [Credits](#credits)
10. [License](#license)

---

## Features

- **Real-time detection & tracking** — up to 30 FPS on RTX 4050 using a custom-trained YOLOv8/v10 model. :contentReference[oaicite:1]{index=1}
- **Autonomous motion** — Arduino firmware translates vision commands (`A B C D f S`) into differential motor speeds for smooth 360° omni-wheel movement. :contentReference[oaicite:2]{index=2}
- **GPU/CPU fallback** — automatically runs on CUDA if available, else falls back to CPU.
- **Obstacle awareness** — HC-SR04 ultrasonic sensor prevents collisions in tight spaces. :contentReference[oaicite:3]{index=3}
- **Modular codebase** — Python scripts for vision & control, Arduino sketch for low-level actuation.
- **Plug-and-play training pipeline** — re-train on your own objects with Roboflow + Google Colab in a few clicks.

---

## Bill of Materials

| Qty                       | Component                         | Purpose                                           |
| ------------------------- | --------------------------------- | ------------------------------------------------- |
| 1                         | **Arduino Mega 2560**             | high-I/O microcontroller brain for motion control |
| 1                         | **Rhino MDD20A** dual 20 A driver | bidirectional DC-motor H-bridge                   |
| 4                         | Omni-wheels                       | holonomic motion                                  |
| 1                         | HC-SR04 ultrasonic sensor         | front obstacle distance                           |
| 1                         | 12 V Li-Po (≥2 Ah)                | power reservoir                                   |
| 1                         | Buck converter (LM2596)           | 12 V → 5 V logic rail                             |
| 1                         | Lenovo FHD USB webcam             | live video stream                                 |
| —                         | Laptop w/ **RTX 4050 GPU**        | on-board compute                                  |
| Pin headers, GCB, jumpers | wiring                            |

_(Full data-sheet style specs live in `/docs/MakerNova_Object_Following_Bot.pdf`)_

---

## Software Stack

| Layer            | Tech                                                     |
| ---------------- | -------------------------------------------------------- |
| **Vision**       | Python 3.10, `ultralytics` (YOLO v8/10), OpenCV 4, NumPy |
| **Acceleration** | PyTorch 2 + CUDA 12                                      |
| **Serial I/O**   | `pyserial`                                               |
| **Annotation**   | `supervision` library                                    |
| **Firmware**     | Arduino IDE 2.x (C++)                                    |

Install everything in one line:

```bash
pip install -r requirements.txt  # Linux / Windows
# or
conda env create -f environment.yml
```
