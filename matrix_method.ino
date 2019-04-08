#include <BasicLinearAlgebra.h>

// Pin Definitions //
#define IRPIN_L 11
#define IRPIN_R 10

// Constants //
#define L 80  // baseline in mm
#define RADIUS  20 // radius of the wheels
#define GEAR_RATIO  75.81 // Motor gear ratio


// Global Variables //
float phi = (RADIUS * deg2rad(90 / GEAR_RATIO));

Matrix<4,4> right_wheel = {
   cos(phi),  -sin(phi),  0,  0,
   sin(phi),  cos(phi), 0,  L / 2,
   0, 0,  1,  0,
   0, 0,  0,  1};

Matrix<4,4> right_translate = {
  1,  0,  0,  0,
  0,  1,  0,  -L,
  0,  0,  1,  0,
  0,  0,  0,  1};

Matrix<4,4> left_wheel = {
   cos(-phi),  -sin(-phi),  0,  0,
   sin(-phi),  cos(-phi), 0,  -L / 2,
   0, 0,  1,  0,
   0, 0,  0,  1};

Matrix<4,4> left_translate = {
  1,  0,  0,  0,
  0,  1,  0,  L,
  0,  0,  1,  0,
  0,  0,  0,  1};

Matrix<4,4> right_transform = right_wheel * right_translate;
Matrix<4,4> left_transform = left_wheel * left_translate;

void setup() {
  Serial.begin(9600);
  pinMode(IRPIN_L, INPUT);
  pinMode(IRPIN_R, INPUT);
  attachInterrupt(digitalPinToInterrupt(IRPIN_L), ISR_L, RISING);
  attachInterrupt(digitalPinToInterrupt(IRPIN_R), ISR_R, RISING);
}

void loop()
{
  // do nothing, wait for interrupts
}

void ISR_L()
{
  
}

void ISR_R()
{
  
}