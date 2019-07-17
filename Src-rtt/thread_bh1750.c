#include <entry.h>
#include "stm32f4xx_hal.h"
#include "LCD.h"
#include "bh1750.h"

static float BH1750_lx;

rt_thread_t bh1750_thread = RT_NULL;

void bh1750_thread_entry(void* parameter)
{
  char light[16];
  while(1) {    
    if(BH1750_OK == BH1750_ReadLight(&BH1750_lx)) {
      sprintf(light, "Light: %.2fLX", BH1750_lx);
      LCD_Puts(0,0,light);
    }
    rt_thread_delay(10);
  }
}
