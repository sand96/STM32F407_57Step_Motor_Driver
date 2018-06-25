The microcontroller here is STM32f407. 
And the motor driver is DM45. Only four signal is needed.

For the uniform accelerated motion, the DMA changes the TIM2 regularly. And the DMA_IT is used to changed the value that will be written into the TIM2_ARR. 

For user, most of the information can be defined in the struct Motor, including the GPIO pin, the final and initial period. Some redundant paramter has been kept for localized utility. The information of position hasn't been used. Pay attention, some information in the TIM2_PWMDMA_Config() function should be changed by hand. This information can be found in the datatsheet.