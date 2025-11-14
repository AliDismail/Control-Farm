# Ctrl+Farm

## Introduction
Modern farming is under increasing pressure with the need for precision and effectiveness in planting operations.  
This project proposes the design of an automated farming robot suitable for seeding and watering vegetables like carrots, tomatoes, and other small-seed crops.  

The robot:
- Moves effectively over even and rugged terrain  
- Communicates stably with the user  
- Ensures optimal field maintenance  
- Enhances productivity, reduces labor needs, and produces uniform, high-yield planting output  

---

## Equipment
- MG90S servo motor  
- TB6600 Stepper Motor Driver  
- NI myRio-1900  
- NEMA 17 Stepper Motor  
- DC motor  
- SG90 Tower Pro servo motor  
- Arduino Kit Remote Control  
- IR Receiver Module  
- Water Valve  

---

## Design Summary
![Figure 1: Real Demonstration](images/Picture1.png)

![Figure 2: Theoretical Concept](images/Picture2.png)
Our project is an open-field and greenhouse multi-process farm robot automating:
- Plant spacing  
- Furrowing  
- Seeding  
- Watering  

**Operation loop:**
1. Robot powers on and awaits user input.  
2. Moves forward a pre-determined length.  
3. Drill lowers to create a furrow.  
4. Switches to seeding mode → seed released.  
5. Switches to watering mode → water flows into furrow.  
6. Returns to drilling mode for next cycle.  
7. Repeats until stop switch is activated.  
8. Detects falls using accelerometer → triggers alarm buzzer.  

---

## System Details

### Design
![Figure 3: Bottom View](images/Picture3.png)
![Figure 4: Top View](images/Picture4.png)
![Figure 5: Back View](images/Picture5.png)
![Figure 6: Side View](images/Picture6.png)
- Built using **wood, carbon steel, and PLA+**.  
- Wood: lightweight platform.  
- Carbon steel: bogie, rocker, MyRio box, motor mounts (laser cut, drilled, welded).  
- PLA+: 3D printed gears for strength and rapid prototyping.  
- Elevated platform and leg structure → effective navigation in rough terrain.  

**Switching mechanism :** 
 ![Figure 7: Switching Mechanism](images/Picture7.png)
- Controlled rotation coordinates motion among linked elements.  
- Torque transmission and angular velocity optimized for smooth switching.  
- Ensures consistent motion control in harsh conditions.  

---

### Circuit
**Connections:**
- **DC Motor 1–4** via Motor Driver  
  - ENA: A/PWM0 | pin 27  
  - ENB: B/PWM0 | pin 27  
  - IN1: A/DIO0 | pin 11  
  - IN2: A/DIO1 | pin 13  
  - IN3: A/DIO2 | pin 15  
  - IN4: A/DIO3 | pin 17  

- **Servo 1 (Mode Switcher):** A/PWM1 | pin 29  
- **Servo 2 (Seed Opener):** A/PWM2 | pin 31  

- **Stepper 1:** pins 11–17  
- **Stepper 2:** pins 19–25  

- **Buzzer:** A/DIO4 | pin 19  
- **Water valve**  
- **Small DC motor for drill**  
- **Remote Control System**  

---

### Code (State Machine)
The robot is controlled by a **state machine**:
 ![Figure 8: State Machine Diagram](images/Picture8.png)
 ![Figure 9: Program Interface](images/Picture9.png)
- **Turn ON:** boots for 3s → IDLE  
![Figure 10: Turn On State](images/Picture10.png)
- **IDLE:** waits for user input (remote start button) 
![Figure 11: IDLE State](images/Picture11.png)
- **Start Farming:** waits 2s → Drive  
![Figure 12: Start Farming State](images/Picture12.png)
- **Drive:** DC motors run 2s → Drilling  
![Figure 13: Drive State](images/Picture13.png)
- **Drilling:** Stepper lowers drill 3s → raises drill 3s → Seeding  
![Figure 14: Drilling-Down State](images/Picture14.png)
![Figure 15: Drilling-Up State](images/Picture15.png) 
- **Seeding:**  
  - Servo1 rotates 60° → seeding mode  
  - Stepper2 lowers tunnel 2s  
  - Servo2 opens seed valve 1s → closes 1s  
  - Stepper2 raises tunnel 2s → Watering  
![Figure 16: Seeding-Switch State](images/Picture16.png) 
![Figure 17: Seeding-Down State](images/Picture17.png)
![Figure 18: Seeding State](images/Picture18.png)  
![Figure 19: Seeding-Up State](images/Picture19.png)  
- **Watering:** Servo1 rotates 60° → watering mode → valve opens 2s → Filling 
![Figure 20: Watering State](images/Picture20.png)   
- **Filling:** Servo1 rotates -120° → drilling mode → DC motors run 2s → loop  
- **Stop:** user presses stop button → system off  
![Figure 21: Stop State](images/Picture21.png)   
- **Fell Off:** accelerometer detects fall → buzzer 5s → returns to IDLE 
![Figure 22: Fell Off State](images/Picture22.png)    

---

## Design Evaluation
Strengths:
- Executes all requested tasks  
- Robust state machine and switching mechanism  

Limitations:
- High power usage (two NEMA 17 + five DC motors)  
- Partial soil furrowing → seed protection issues  
- Time constraints → excluded water valve, remote control, functional drill head 

---

## Lessons Learned

### 1. Supplier Reliability
- Delays slowed progress → forced material substitutions  
- Future improvements:  
  - Double-check suppliers before orders  
  - Maintain communication and request updates  
  - Have backup suppliers/materials  

### 2. Time Management Across Majors
- Diverse student schedules complicated coordination  
- Solutions:  
  - Shared project schedule  
  - Clear milestones and deadlines  
  - Collaboration tools (calendars, task lists)  
  - Open communication for adjustments  

### Knowledge Beyond Class
- Importance of planning, supplier communication, and multidisciplinary teamwork  
- Gained project management, problem-solving, and flexibility skills  

---

## Conclusion
The farm robot automates seeding, watering, and filling with precision for small-seed crops (tomatoes, carrots).  
It navigates variable terrain, increases farming output, and minimizes labor.  
By integrating automation into farming, crop management becomes simpler, more effective, and environmentally friendly.

