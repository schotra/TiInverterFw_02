#include "pwmgeneration.h"
#include "sci.h"



__interrupt void pwm_timer_isr(void)
{
   //int start = timer_get_counter(PWM_TIMER);
   /* Clear interrupt pending flag */
   //timer_clear_flag(PWM_TIMER, TIM_SR_UIF);


   PwmGeneration::Run();

   //int time = timer_get_counter(PWM_TIMER) - start;

   //if (TIM_CR1(PWM_TIMER) & TIM_CR1_DIR_DOWN)
   //   time = (2 << pwmdigits) - timer_get_counter(PWM_TIMER) - start;

   //execTicks = ABS(time);

    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;

    //
    // Acknowledge this __interrupt to receive more __interrupts from group 1
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

}

/**
* Enable timer PWM output
*/
void PwmGeneration::EnableOutput()
{
}

/**
* Disable timer PWM output
*/
void PwmGeneration::DisableOutput()
{
}


