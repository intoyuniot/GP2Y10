#include <gp2y10.h>

GP2Y10 pm25 = GP2Y10(A0,D0);

uint16_t pm25Val; // ug^m3

void setup()
{
    pm25.begin();
    Serial.begin(115200);
    delay(500);
}


void loop()
{
    pm25Val = pm25.CalculatedConcentration();
    Serial.print(pm25Val);
    Serial.print("\r\n");
    delay(1000);
}
