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
    int pwmValue = map(sinValue, -1, 1, 0, 255); // Konversi ke nilai PWM (0-255)

    // Atur output PWM ke MOSFET menggunakan pendekatan bipolar
    analogWrite(PIN_PWM_A, pwmValue);
    analogWrite(PIN_PWM_B, 255 - pwmValue); // Gunakan nilai 255 - pwmValue untuk membalik sinyal

    // Tunggu hingga waktu yang tepat untuk mempertahankan frekuensi gelombang
    while (micros() - startTime < (i + 1) * PERIOD_MICROSECONDS / 360) {
      // Tunggu
    }
  }
}
