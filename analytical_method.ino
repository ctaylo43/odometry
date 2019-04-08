// Pin Definitions //
#define IRPIN_L 11
#define IRPIN_R 10

// Constants //
#define L 80  // baseline in mm
#define RADIUS  20 // radius of the wheels
#define GEAR_RATIO  75.81 // Motor gear ratio


// Global Variables //
float global_phi = 0, phi = (RADIUS * deg2rad(90 / GEAR_RATIO));
float delta_x = (L / 2) * sin(phi);
float global_x = 0, d_prime_x;
float delta_y = (L / 2) * (1 - cos(phi));
float global_y = 0, d_prime_y;


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
  g_phi += phi;
  d_prime_x = (delta_x * cos(phi)) + (delta_y * sin(phi));
  d_prime_y = (delta_x * sin(phi)) + (delta_y * cos(phi));
  global_x += d_prime_x;
  global_y += d_prime_y;
  Serial(global_x);
  Serial(global_y);
}

void ISR_R()
{
  g_phi -= phi;
  d_prime_x = (delta_x * cos(phi)) + (delta_y * sin(phi));
  d_prime_y = (delta_x * sin(phi)) + (delta_y * cos(phi));
  global_x += d_prime_x;
  global_y += d_prime_y;
  Serial(global_x);
  Serial(global_y);
}
