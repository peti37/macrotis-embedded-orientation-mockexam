/*
    * TASK SUMMARY:
    * You need to implement a system which simulates a railway level crossing.
    *
    * SPECIFICATION:
    * 1. The initial state of the system is OPEN, so it allows cars passing. In this state
    *    the LED_GREEN should be flashing with 0.5Hz, 50% duty cycle
    * 2. When the system gets a signal that a train is approaching the crossing (blue
    *    button click) it has to enter into SECURING state. In SECURING state the system
    *    has to close the barrier which this takes exactly 5 seconds. In this state the
    *    LED_GREEN should be flashing with 1Hz, 50% duty cycle. During this time the system
    *    should not react to any further signal (blue button click).
    * 3. Once the barrier is down the system enters into SECURED state. In this state the
    *    LED_GREEN is turned constantly off.
    * 4. When the system gets a signal that a train has left the crossing (blue button
    *    click) it switches to OPENING state: lifts the barrier which takes exactly 6
    *    seconds (it's a heavy barrier so it takes more time to lift). In this state the
    *    LED_GREEN is flashing with 1Hz, 50% duty cycle. During this time the system
    *    should not react to any further signal (blue button click). Once the barrier
    *    is up, the system get's back to it's initial, OPEN state (point 1.).
    *
    * NON FUNCTIONAL REQUIREMENTS:
    * 1. You cannot read the state of the blue button, use interrupts!
    * 2. You should use at least 1 timer peripheral
    * 3. Try to avoid the use of blocking waiting mechanisms (like HAL_Delay())
    * 4. Using PWM on LED_GREEN is possible, but not required. Note that you have no
    *    timer channel to LED_GREEN, so to drive it from PWM you should turn on the LED
    *    in every timer period end interrupt, and turn it off in every PWM pulse end
    *    interrupt.
    * 5. When you enter to any state, you should report this on USART1 peripheral. You
    *    can use BSP_COM_Init() to initialize this, and a serial monitor to read these
    *    reports. It should look something like this after reset and a train crossing:
    *
    *    Entered in OPEN state         // some time later a click comes
    *    Entered in SECURING state
    *    Entered in SECURED state      // some time later a click comes
    *    Entered in OPENING state
    *    Entered in OPEN state
    */
