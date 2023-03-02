#include <stdlib.h>
#include <assert.h>
#include "AT91SAM7S256.h"
#include "pit.h"
#include "aic.h"
#include "display.h"
#include "sound.h"


#if USE_SOUND_INTERUPTS == 1 
	void (*sound)(ULONG *, UBYTE, UBYTE, UWORD, unsigned int) = SoundAsync;
#else 
	void (*sound)(ULONG *, UBYTE, UBYTE, UWORD, unsigned int) = SoundSync;
#endif

#if PIT_USE_INTERUPTS
UBYTE hh=0;
UBYTE mm=0;
UBYTE ss=0;
ULONG count=0;
ULONG count2=0;

void pit_handler(void){
if(count == 3){
   count2++;
   count=0;
   if(ss < 60){ 
   	ss++;
   }else{
   	ss = 0;
   	if(mm < 60){
   		mm++;
   	}else{
   		mm = 0;
   		if(hh < 24){
   			hh++;
   		}else{
   			hh = 0;
   		}
   	}
   }
   printtime(hh, mm, ss);
   }else{
   count++;
   }
   PITAckInterrupt();
}

int main(void)
{

DisplayInit();
DisplayOn(1);
PITEnable();
PITInterruptEnable(1000000, pit_handler);
SoundInit();
ULONG pattern[] = {0xFF00FF00};

  while ( 1 ) {
    
    if (count2 == 10) {
      sound(pattern, sizeof(pattern)/sizeof(ULONG), 100, 10, 20);
      count2=0;
    }
  }
	
  PITDisable();
  //
  // cleanup here
  //

return 0;
}
#else
int main(void)
{
UBYTE hh=0;
UBYTE mm=0;
UBYTE ss=0;
  
DisplayInit();
DisplayOn(1);
PITEnable();

while(1)
{
   spindelayms(1000);
   if(ss < 60){ 
   	ss++;
   }else{
   	ss = 0;
   	if(mm < 60){
   		mm++;
   	}else{
   		mm = 0;
   		if(hh < 24){
   			hh++;
   		}else{
   			hh = 0;
   		}
   	}
   }
   printtime(hh, mm, ss);
}

return 0;
}
#endif
