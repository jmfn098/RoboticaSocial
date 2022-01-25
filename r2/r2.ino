#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
#define SPTR_SIZE   20
char   *sPtr [SPTR_SIZE];

unsigned int pos0 = 172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180 = 565; // ancho de pulso en cuentas para la pocicion 180°


void setup() {
  
  Serial.begin(115200);
  servos.begin();
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms

}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
;  duty = map(angulo, 0, 180, pos0, pos180);
  servos.setPWM(n_servo, 0, duty);
}
void loop() {
  if (Serial.available() > 0) {
    
    String mensaje=Serial.readStringUntil('\n');
    
    mensaje.trim();
    Serial.println(mensaje);
    int N = separate (mensaje, sPtr, SPTR_SIZE);
    
//    setServo(0, 90);
//    setServo(1, 90);
//    setServo(2, 0);
//    setServo(3, 90);
    setServo(0,90 + atoi(sPtr[0]));
    setServo(1,90);
    setServo(2, 0 +  atoi(sPtr[1]));
    setServo(3,90 + atoi(sPtr[2]));
  }
}

int
separate (
    String str,
    char   **p,
    int    size )
{
    int  n;
    char s [100];

    strcpy (s, str.c_str ());

    *p++ = strtok (s, " ");
    for (n = 1; NULL != (*p++ = strtok (NULL, " ")); n++)
        if (size == n)
            break;

    return n;
}   
