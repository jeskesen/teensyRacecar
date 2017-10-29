#include "Arduino.h"
#include <TeensyRacecar.h>

#include <PulsePosition.h>

PulsePositionInput rcIn;

#include <Servo.h>
Servo steering, throttle;
float yaw, surge, enable;

void setup(){
  Serial.begin(115200);
  rcIn.begin(CPPM_PIN);

  throttle.attach(THROTTLE_ESC_PIN, 1000, 2000);
  throttle.writeMicroseconds(DEFAULT_PULSE_WIDTH);

  steering.attach(STEERING_SERVO_PIN, 1000, 2000);
  steering.writeMicroseconds(DEFAULT_PULSE_WIDTH);

}

void loop()
{
  yaw=surge=enable=0.0;
  if(getRCInput(yaw, surge, enable) && (enable > DEFAULT_PULSE_WIDTH + 200))
  {
	steering.writeMicroseconds((int)yaw);
	throttle.writeMicroseconds((int)surge);

    Serial.print(yaw);
    Serial.print("  ");
    Serial.print(surge);
    Serial.println();
  }
}

bool getRCInput(float& yaw, float& surge, float& enable)
{
  if(rcIn.available() == 6)
  {
    yaw = rcIn.read(1); //(rcIn.read(1)-pulseCenter) / 2;
    surge = rcIn.read(2); //(rcIn.read(2)-pulseCenter) / 2;
    enable = rcIn.read(5); // > pulseCenter + 200;
    return true;
  }

  return false;

}
