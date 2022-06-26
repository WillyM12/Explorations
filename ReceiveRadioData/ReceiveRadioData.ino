#include <VirtualWire.h>
void setup()
{
  vw_setup(5000);
  vw_rx_start();
   
    Serial.begin(115200);
}

void loop()
{
  uint8_t long_buf = 33;
  uint8_t mem_tampon[long_buf];

  if (vw_get_message(mem_tampon, &long_buf))
  {
    int i;
    Serial.print("Reçu : ");

    for (i = 0; i < long_buf; i++)
    {
      Serial.write(mem_tampon[i]);
    }
    Serial.println();
  } 
}
