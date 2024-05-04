#define PIN_PWM_A D1 // Pin untuk sinyal PWM MOSFET 1A dan 2B (1 dan 4)
#define PIN_PWM_B D2 // Pin untuk sinyal PWM MOSFET 1B dan 2A (2 dan 3)

#define PERIOD_MICROSECONDS 20000 // Periode gelombang sinusoidal dalam mikrodetik (1 detik = 1000000 mikrodetik)

void setup() {
  pinMode(PIN_PWM_A, OUTPUT);
  pinMode(PIN_PWM_B, OUTPUT);
}

void loop() {
  unsigned long startTime = micros(); // Waktu mulai siklus gelombang

  for (int i = 0; i < 360; i++) {
    float sinValue = sin(2 * PI * i / 360.0); // Hitung nilai gelombang sinusoidal
    int pwmValue;
if (i < 180) {
  pwmValue = map(sinValue, 0, 1, 0, 255); // Map nilai dari 0-1 ke 0-255 untuk PWM_A
  analogWrite(PIN_PWM_A, pwmValue);
  analogWrite(PIN_PWM_B, 0); // Matikan PWM_B saat PWM_A aktif
} else {
  pwmValue = map(sinValue, 0, -1, 0, 255); // Map nilai dari 0-(-1) ke 0-255 untuk PWM_B
  analogWrite(PIN_PWM_A, 0); // Matikan PWM_A saat PWM_B aktif
  analogWrite(PIN_PWM_B, pwmValue);
}


    // Tunggu hingga waktu yang tepat untuk mempertahankan frekuensi gelombang
    while (micros() - startTime < (i + 1) * PERIOD_MICROSECONDS / 360) {
      // Tunggu
    }
  }
}
