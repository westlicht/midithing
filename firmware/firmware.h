#ifndef __FIRMWARE_H__
#define __FIRMWARE_H__

//#define PRINTDEBUG 1// if defined, send debug info to the serial interface
//#define USETIMER  // if defined, use timer functions
#define CALIBRATION 1
#define STARTSTOPCONT // if defined, handle start/stop/continue

#include <Bounce2.h> // Button debouncer
#include <EEPROM.h>
#include <MIDI.h> // MIDI library
#include <Wire.h> //  I2C Comm
#include <mcp4728.h> // MCP4728 library
#include <avr/eeprom.h>

// Input / output definitions
// DAC Ports
#define PITCHCV 0
#define VELOC 1
#define MODUL 2
#define BEND 3
// In/Out pins
#define PINGATE 2
#define PINGATE2 3
#define PINGATE3 4
#define PINGATE4 5
#define PINCLOCK 6
#define PINLEARN 7
#define PINLED2 9
#define PINSTARTSTOP 10
#define PINLED 13

// Learn Mode
#define NORMALMODE 0
#define ENTERLEARN 1
#define ENTERCAL 2

// MIDI Modes
enum MIDImodes {
  MIDIMODE_INVALID = 0,
  MONOMIDI = 1,
  DUALMIDI,
  QUADMIDI,
  PERCTRIG,
  PERCGATE,
  POLYFIRST,
  POLYLAST,
  POLYHIGH,
  POLYLOW,
  MIDIMODE_LAST
};

//
#define TRIGPERCUSSION 60 // Width of trigger for percussions
#define TRIGCLOCK 60 // Width of trigger for Clock
#define TRIGSTART 60// Width of trigger for Start/Continue

//////////////////////////////////////////////
// Function declaration
// DAC
void  sendvaltoDAC(unsigned int port, unsigned int val);
//MIDI Handles
void HandleNoteOn(byte channel, byte pitch, byte velocity);
void HandleNoteOff(byte channel, byte pitch, byte velocity);
void HandlePitchBend(byte channel, int bend);
void HandleControlChange(byte channel, byte number, byte value);
#ifdef STARTSTOPCONT
void HandleStart(void);
void HandleContinue(void);
void HandleStop(void);
#endif
void HandleClock(void);

// Timer functions
#ifdef USETIMER
void SetupTimer(unsigned int compTimer1);
#endif

#endif // __FIRMWARE_H__

