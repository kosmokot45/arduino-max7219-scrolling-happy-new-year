#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "5bite_rus.h"

#define HARDWARE_TYPE MD_MAX72XX::ICSTATION_HW
#define MAX_DEVICES 1 // количество модулей
#define CS_PIN 5      // CS SPI

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

uint8_t smile[] = {
    8, // Ширина символа
    B00111100,
    B01000010,
    B10010101,
    B10100001,
    B10100001,
    B10010101,
    B01000010,
    B00111100};

void setup()
{
    P.begin();
    P.setFont(_5bite_rus);
    P.addChar('H', smile);
    P.displayText("С новым годом!!! H", PA_CENTER, 120, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}
void loop()
{
    if (P.displayAnimate())
    {
        P.displayReset();
    }
}