#include "F28x_Project.h"



extern "C" void pwm_timer_isr(void);
#ifndef PWMGENERATION_H
#define PWMGENERATION_H


class PwmGeneration
{
   public:
      static void Run();
      static void PwmStart();
      static void PwmStop();
      static void PwmInit();    // Private??

   private:
      static void EnableOutput();
      static void DisableOutput();
};

#endif // PWMGENERATION_H
