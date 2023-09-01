# StopWatch

This is a **Practice** StopWatch project implementation using the ATmega32 microcontroller. 

It incorporates concepts such as interrupts, timers, and utilizes hardware peripherals like the LM016 LCD and push buttons.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [License](#license)

## Introduction

This StopWatch project is designed to showcase the use of interrupts and timers on the ATmega32 microcontroller. The unique aspect of this project is that I've written the drivers from scratch, including those for the LCD, digital I/O (DIO), timer, and interrupt. The project achieves an impressive accuracy of 1 micro-second and offers three main functionalities: start/resume, stop, and reset.

## Features

- **Start/Resume**: Begin timing intervals with the press of a button.
- **Stop**: Pause the stopwatch to record elapsed time.
- **Reset**: Reset the stopwatch to zero for a new timing session.
- **LCD Display**: Utilizes an LM016 LCD to provide a clear and user-friendly interface.
- **Interrupts**: Utilizes interrupts for responsive and accurate timing.
- **Custom Drivers**: All necessary drivers have been developed from scratch for this project.
- **High Accuracy**: Achieves an accuracy of 1 micro-second for precise timing.

## Hardware Components

To replicate this project, you will need the following hardware components:

- ATmega32 Microcontroller
- LM016 LCD Display
- Push Buttons (for start, stop, and reset functions)
- Appropriate resistors, capacitors, and wiring for circuit connections


