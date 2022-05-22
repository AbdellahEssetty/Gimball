#include <ESP32Servo.h>
#include <cmath>
#include <Arduino.h>


// Linear interpolation (no easing)
float linear(float x);

// Quadratic easing; p^2
float easeInQuadratic(float x);
float easeOutQuadratic(float x);
float easeInOutQuadratic(float x);

// Cubic easing; p^3
float easeInCubic(float x);
float easeOutCubic(float x);
float easeInOutCubic(float x);

// Quartic easing; p^4
float easeInQuartic(float x);
float easeOutQuartic(float x);
float easeInOutQuartic(float x);

// Quintic easing; p^5
float easeInQuintic(float x);
float easeOutQuintic(float x);
float easeInOutQuintic(float x);



// Modeled after the line y = x
float linear(float x) {
  return x;
}

// Modeled after the parabola y = x^2
float easeInQuadratic(float x) {
  return pow(x, 2);
}

// Modeled after the parabola y = -x^2 + 2x
float easeOutQuadratic(float x) {
  return -(x * (x - 2));
}

// Modeled after the piecewise quadratic
// y = (1/2)((2x)^2)             ; [0, 0.5)
// y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1]
float easeInOutQuadratic(float x) {
  return (x < 0.5) ? (2 * pow(x, 2)) : ((-2 * pow(x, 2)) + (4 * x) - 1);
}

// Modeled after the cubic y = x^3
float easeInCubic(float x) {
  return pow(x, 3);
}

// Modeled after the cubic y = (x - 1)^3 + 1
float easeOutCubic(float x) {
  return pow(x - 1, 3) + 1;
}

// Modeled after the piecewise cubic
// y = (1/2)((2x)^3)       ; [0, 0.5)
// y = (1/2)((2x-2)^3 + 2) ; [0.5, 1]
float easeInOutCubic(float x) {
  return (x < 0.5) ? (4 * pow(x, 3)) : (0.5 * pow(((2 * x) - 2), 3) + 1);
}

// Modeled after the quartic x^4
float easeInQuartic(float x) {
  return pow(x, 4);
}

// Modeled after the quartic y = 1 - (x - 1)^4
float easeOutQuartic(float x) {
  return pow(x - 1, 3) * (1 - x) + 1;
}

// Modeled after the piecewise quartic
// y = (1/2)((2x)^4)        ; [0, 0.5)
// y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1]
float easeInOutQuartic(float x) {
  return (x < 0.5) ? (8 * pow(x, 4)) : (-8 * pow(x - 1, 4) + 1);
}

// Modeled after the quintic y = x^5
float easeInQuintic(float x) {
  return pow(x, 5);
}

// Modeled after the quintic y = (x - 1)^5 + 1
float easeOutQuintic(float x) {
  return pow(x - 1, 5) + 1;
}

// Modeled after the piecewise quintic
// y = (1/2)((2x)^5)       ; [0, 0.5)
// y = (1/2)((2x-2)^5 + 2) ; [0.5, 1]
float easeInOutQuintic(float x) {
  return (x < 0.5) ? (16 * pow(x, 5)) : (0.5 * pow((2 * x) - 2, 5) + 1);
}


void swap(float& lh, float& rh)
{
  float temp = lh;
  lh = rh;
  rh = temp;
}


void writeEasingAngle(Servo& servo, const int& angle)
{
  float start = map(servo.read(), 0, 180, 0.0, 1.8);
  float end = map(angle, 0.0, 180.0, 0.0, 1.8);

  if(start > end) 
    swap(start, end);


  for (float x = start; x < end; x += 0.005)
  {
    /* code */
    servo.writeMicroseconds(1000 + (int)(x * 1000));
  }
  
  
}