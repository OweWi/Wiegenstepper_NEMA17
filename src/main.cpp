/**
 * Modified from Teemu Mäntykallio
 * New Version from Owe Wisch
 * Takes the demo project from the TMCStepper library
 * and uses a 2280 Stepper to move the baby ;-).
 * To be continued:
 * (Variable stepsize, either by rotary encoder or random)
 */

#include <Arduino.h>
#include <TMCStepper.h>

#define EN_PIN           7 // Enable
#define DIR_PIN          8 // Direction
#define STEP_PIN         9 // Step
// #define CS_PIN           42 // Chip select
// #define SW_MOSI          66 // Software Master Out Slave In (MOSI)
// #define SW_MISO          44 // Software Master In Slave Out (MISO)
// #define SW_SCK           64 // Software Slave Clock (SCK)
// #define SW_RX            63 // TMC2208/TMC2224 SoftwareSerial receive pin
// #define SW_TX            40 // TMC2208/TMC2224 SoftwareSerial transmit pin
#define SERIAL_PORT Serial // TMC2208/TMC2224 HardwareSerial port
// #define DRIVER_ADDRESS 0b00 // TMC2209 Driver address according to MS1 and MS2
#define NUM_STEPS  2500

#define R_SENSE 0.11f // Match to your driver
                      // SilentStepStick series use 0.11
                      // UltiMachine Einsy and Archim2 boards use 0.2
                      // Panucatt BSD2660 uses 0.1
                      // Watterott TMC5160 uses 0.075


TMC2208Stepper driver(&SERIAL_PORT, R_SENSE); // Hardware Serial

void setup() {
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);      // Enable driver in hardware

                                  // Enable one according to setup
//SPI.begin();                    // SPI drivers
  SERIAL_PORT.begin(115200);      // HW UART drivers
//driver.beginSerial(115200);     // SW UART drivers

  driver.begin();                 //  SPI: Init CS pins and possible SW SPI pins
                                  // UART: Init SW UART (if selected) with default 115200 baudrate
  driver.toff(5);                 // Enables driver in software
  driver.rms_current(600);        // Set motor RMS current
  driver.microsteps(16);          // Set microsteps to 1/16th

  driver.pwm_autoscale(true);     // Needed for stealthChop
}

bool shaft = false;

void loop() {
  // Run NUM_STEPS steps and switch direction in software
  for (uint16_t i = NUM_STEPS; i>0; i--) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(160);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(160);
  }
  shaft = !shaft; // toggle variable
  driver.shaft(shaft);
}
