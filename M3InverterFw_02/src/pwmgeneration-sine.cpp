#include "F28x_Project.h"

#include "pwmgeneration.h"
#include "sci.h"

void PwmGeneration::PwmInit()
{
    EALLOW;
    // Assumes ePWM clock is already enabled
    EPwm1Regs.ETSEL.bit.SOCAEN    = 0;    // Disable SOC on A group
EPwm1Regs.ETSEL.bit.SOCAEN    = 0;    // Disable SOC on A group
    EPwm1Regs.ETSEL.bit.SOCASEL    = 4;   // Select SOC on up-count
EPwm1Regs.ETSEL.bit.SOCBSEL    = 4;   // Select SOC on up-count

    EPwm1Regs.ETPS.bit.SOCAPRD = 1;       // Generate pulse on 1st event
EPwm1Regs.ETPS.bit.SOCAPRD = 1;       // Generate pulse on 1st event

    EPwm1Regs.CMPA.bit.CMPA = 0x0800;     // Set compare A value to 2048 counts
    EPwm1Regs.CMPB.bit.CMPB = 0x0A00;     // Set compare B value to 3072 counts
    EPwm1Regs.TBPRD = 0x1000;             // Set period to 4096 counts
    EPwm1Regs.TBCTL.bit.CTRMODE = 3;      // freeze counter

    EPwm1Regs.CMPCTL.bit.SHDWAMODE=0;       // CMPA working in shadow mode.
    EPwm1Regs.CMPCTL.bit.SHDWBMODE=0;       // CMPB working in shadow mode.
    EPwm1Regs.CMPCTL.bit.LOADAMODE=0;       // CMPA new value loaded on CNT=0;
    EPwm1Regs.CMPCTL.bit.LOADBMODE=0;       // CMPB new value loaded on CNT=0;

    EPwm1Regs.AQCTLA.bit.CAU = 1;       // Output A cleared when TBCTR = CMPA while Up-Counting;
    EPwm1Regs.AQCTLA.bit.CAD = 2;       // Output A set     when TBCTR = CMPA while Down-Counting;
    EPwm1Regs.AQCTLB.bit.CBU = 1;       // Output B cleared when TBCTR = CMPB while Up-Counting;
    EPwm1Regs.AQCTLB.bit.CBD = 2;       // Output B set     when TBCTR = CMPA while Down-Counting;

    EPwm1Regs.ETSEL.bit.SOCAEN = 1;  //enable SOCA
 EPwm1Regs.ETSEL.bit.SOCBEN = 1;  //enable SOCA

 EPwm1Regs.TBCTL.bit.CTRMODE = 2; //unfreeze, and enter up-down count mode


    EDIS;

    // Direct PWM waveform to GPIO.
    GPIO_SetupPinMux(0, GPIO_MUX_CPU1, 1);  // ePWM1A, @GPIO0
    GPIO_SetupPinOptions(0, GPIO_OUTPUT, GPIO_PULLUP);

    GPIO_SetupPinMux(1, GPIO_MUX_CPU1, 1);  // ePwM1B, @GPIO1
    GPIO_SetupPinOptions(1, GPIO_OUTPUT, GPIO_PULLUP);
}


void PwmGeneration::Run()
{
    //start ePWM
    //
    int star = (int) '*';
    scia_xmit( star );
}


void PwmGeneration::PwmStart()
{
    //start ePWM
    //

}


void PwmGeneration::PwmStop()
{
    //stop ePWM
    //
    EPwm1Regs.ETSEL.bit.SOCAEN = 0;  //disable SOCA
    EPwm1Regs.TBCTL.bit.CTRMODE = 3; //freeze counter

}


