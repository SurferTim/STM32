#include <USBComposite.h>

USBHID HID;
HIDJoystick Joystick(HID);
int joy_x;
int out_x;
int old_x = 0;
int joy_y;
int out_y;
int old_y = 0;
int slide_c;
int out_slide_c;
int old_slide_c = 0;
int slide_r;
int out_slide_r;
int old_slide_r = 0;
int slide_l;
int out_slide_l;
int old_slide_l = 0;
int rot_x;
int out_rot_x;
int old_rot_x = 0;
int rot_y;
int out_rot_y;
int old_rot_y = 0;

bool pin0 = false;
bool old_pin0 = false;

int spin = 0;
int delay_time = 6;

void setup() {
  pinMode(PA6,INPUT_ANALOG);
  pinMode(PB6,INPUT_PULLUP);
  
  HID.begin(HID_JOYSTICK);
  while (!USBComposite);
}

void loop() {
  joy_x = analogRead(PA6);
  out_x = joy_x & 0xffe0;
  out_x = out_x >> 2;

  if(out_x != old_x)
  {
    Joystick.X(out_x);
    old_x = out_x;
  }

  delay(delay_time);
  
  joy_y = analogRead(PA6);
  out_y = joy_y & 0xffe0;
  out_y = out_y >> 2;

  if(out_y != old_y)
  {
    Joystick.Y(out_y);
    old_y = out_y;
  }

  delay(delay_time);

  slide_c = analogRead(PA6);
  out_slide_c = slide_c & 0xffe0;
  out_slide_c = out_slide_c >> 2;
  
  if(out_slide_c != old_slide_c)
  {
    Joystick.slider(out_slide_c);
    old_slide_c = out_slide_c;
  }

  delay(delay_time);

  slide_r = analogRead(PA6);
  out_slide_r = slide_r & 0xffe0;
  out_slide_r = out_slide_r >> 2;
  
  if(out_slide_r != old_slide_r)
  {
    Joystick.sliderRight(out_slide_r);
    old_slide_r = out_slide_r;
  }

  delay(delay_time);

  slide_l = analogRead(PA6);
  out_slide_l = slide_l & 0xffe0;
  out_slide_l = out_slide_l >> 2;
  
  if(out_slide_l != old_slide_l)
  {
    Joystick.sliderLeft(out_slide_l);
    old_slide_l = out_slide_l;
  }

  delay(delay_time);

  rot_x = analogRead(PA6);
  out_rot_x = rot_x & 0xffe0;
  out_rot_x = out_rot_x >> 2;
  
  if(out_rot_x != old_rot_x)
  {
    Joystick.Xrotate(out_rot_x);
    old_rot_x = out_rot_x;
  }

  delay(delay_time);

  rot_y = analogRead(PA6);
  out_rot_y = rot_y & 0xffe0;
  out_rot_y = out_rot_y >> 2;
  
  if(out_rot_y != old_rot_y)
  {
    Joystick.Yrotate(out_rot_y);
    old_rot_y = out_rot_y;
  }

  delay(delay_time);
  
//  Joystick.hat(spin);  

  pin0 = digitalRead(PB6);
  if(pin0 != old_pin0)
  {
    Joystick.button(1,pin0);
    old_pin0 = pin0;
  }

}
