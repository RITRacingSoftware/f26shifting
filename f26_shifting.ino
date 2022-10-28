
// Define Pinout
#define UPSHIFT_PADDLE_PIN 8
//#define DOWNSHIFT_BUTTON_PIN 2
#define DOWNSHIFT_PADDLE_PIN 12
#define UPSHIFT_SOLENOID_SIG 4 //Should be correct pin
#define DOWNSHIFT_SOLENOID_SIG 7 //Should be correct pin    

// How long a paddle has to be pressed to register and shift
#define BUTTON_HOLD_TIME_MS 10

// How long to hold the solenoid signal low for
#define SOLENOID_SIGNAL_TIME_MS 10

bool upshift_paddle_still_pressed = false;
//bool downshift_button_still_pressed = false;
bool downshift_paddle_still_pressed = false;

int upshift_paddle_pressed_time = 0;
int downshift_paddle_pressed_time = 0;

void setup() {
  pinMode(UPSHIFT_PADDLE_PIN, INPUT_PULLUP);
//  pinMode(DOWNSHIFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(DOWNSHIFT_PADDLE_PIN, INPUT_PULLUP);

  pinMode(UPSHIFT_SOLENOID_SIG, OUTPUT);
  pinMode(DOWNSHIFT_SOLENOID_SIG, OUTPUT);

  digitalWrite(UPSHIFT_SOLENOID_SIG, HIGH);
  digitalWrite(DOWNSHIFT_SOLENOID_SIG, HIGH);
  
}

// Perform an updshift
void upshift(void)
{
  digitalWrite(UPSHIFT_SOLENOID_SIG, LOW);
  delay(SOLENOID_SIGNAL_TIME_MS);
  digitalWrite(UPSHIFT_SOLENOID_SIG, HIGH);
}

// Perform a downshift
void downshift(void)
{
  digitalWrite(DOWNSHIFT_SOLENOID_SIG, LOW);
  delay(SOLENOID_SIGNAL_TIME_MS);
  digitalWrite(DOWNSHIFT_SOLENOID_SIG, HIGH);
}

void loop() {

  // Upshift if paddle is presed and hasn't shifted already for the press
  if((!upshift_paddle_still_pressed) && (digitalRead(UPSHIFT_PADDLE_PIN) == LOW))
  {
    // Only shift if the paddle is held for BUTTON_HOLD_TIME_MS milliseconds
    delay(BUTTON_HOLD_TIME_MS);
    if(digitalRead(UPSHIFT_PADDLE_PIN) == LOW)
    {
      upshift();
      upshift_paddle_still_pressed = true;
    }
  }
  else if(digitalRead(UPSHIFT_PADDLE_PIN) == HIGH)
  {
    upshift_paddle_still_pressed = false;
  }

  // Downshift if button is presed and hasn't shifted already for the press
//  if((!downshift_button_still_pressed) && (digitalRead(DOWNSHIFT_BUTTON_PIN) == LOW))
//  {
//    downshift();
//    downshift_button_still_pressed = true;
//  }
//  else if(digitalRead(DOWNSHIFT_BUTTON_PIN) == HIGH)
//  {
//    downshift_button_still_pressed = false;
//  }

  // Downshift if paddle is presed and hasn't shifted already for the press
  if((!upshift_paddle_still_pressed) && (digitalRead(DOWNSHIFT_PADDLE_PIN) == LOW))
  {
    // Only shift if the paddle is held for BUTTON_HOLD_TIME_MS milliseconds
    delay(BUTTON_HOLD_TIME_MS);
    if(digitalRead(DOWNSHIFT_PADDLE_PIN) == LOW)
    {
      downshift();
      downshift_paddle_still_pressed = true;
    }
  }
  else if(digitalRead(DOWNSHIFT_PADDLE_PIN) == HIGH)
  {
    downshift_paddle_still_pressed = false;
  }
  
}
