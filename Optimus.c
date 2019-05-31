/*
 * Project name:
     Optimus - Obstacle detecting line following robot (using mikroC on PIC16F877A)
 * Copyright:
     (c) techsayura.blogspot.com, 2017.
*/

void Arm_put();
void scn();
void rdy_to_put();
void finl();

//***Line following***//
void run()
{
      if(PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==0 && PORTB.F3==1 && PORTB.F4==1){
      PORTC=0x28;
      }
      else if(PORTB.F0==1 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==1){
      PORTC=0x28;
      }
      else if(PORTB.F0==0 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==0){
      PORTC=0x28;
      }
      else if(PORTB.F0==1 && PORTB.F1==0 && PORTB.F2==1 && PORTB.F3==1 && PORTB.F4==1){
      PORTC=0x08;
      }
      else if(PORTB.F0==0 && PORTB.F1==1 && PORTB.F2==1 && PORTB.F3==1 && PORTB.F4==1){
      PORTC=0x64;
      }
      else if(PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==1 && PORTB.F3==0 && PORTB.F4==1){
      PORTC=0x64;
      }
      else if(PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==1 && PORTB.F3==1 && PORTB.F4==0){
      PORTC=0x65;
      }
      else if(PORTB.F0==1 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==1 && PORTB.F4==1){
      PORTC=0x08;
      }
      else if(PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==1){
      PORTC=0x64;
      }
      else if(PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==0){
      PORTC=0x65;
      }
      else if(PORTB.F0==0 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==1 && PORTB.F4==1){
      PORTC=0x1E;
      }
      else if(PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==1 && PORTB.F3==0 && PORTB.F4==0){
      PORTC=0x65;
      }
      else if(PORTB.F0==0 && PORTB.F1==0 && PORTB.F2==1 && PORTB.F3==1 && PORTB.F4==1){
      PORTC=0x1E;
      }
      else if(PORTB.F0==0 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==1){
      PORTC=0x1E;
      }
      else if(PORTB.F0==1 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==0){
      PORTC=0x65;
      }
      else{
      PORTC=0;
      }
}

//***Detecting goal***//
{
 while(1)
 {
  if (PORTB.F0==0 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==0)
  {
     PORTC=0;
     Sound_Play(880, 500);             // Play sound at 880Hz for 1 second
     PORTE.F1=0;
     Delay_ms(100);
     PORTE.F1=1;
     Sound_Play(880, 500);             // Play sound at 880Hz for 1 second
     Delay_ms(1000);
     
     PORTC=0x28;
     Delay_ms(300);
     PORTC=0x65;
     Delay_ms(600);
     PORTC=0;
     rdy_to_put();break;
 }
 else
 {
  run();
 }
 Delay_ms(2);
 }
}

//***Ready and drop the box****//
void rdy_to_put()
{

while(1)
{
        if(PORTB.F0==1 && PORTB.F4==1)
        {
          PORTC=0;
          break;
        }
        else
        {
         PORTC=0x65;
        }
}
Delay_ms(500);


while(1)
{
        if
        (PORTB.F0==0 && PORTB.F1==0 && PORTB.F2==0 && PORTB.F3==0 && PORTB.F4==0)
        {
         PORTC=0;
         Sound_Play(880, 1000);             // Play sound at 880Hz for 1 second
         Arm_put();
         Delay_ms(500);
         finl();
         break;
        }
        else
        {
         run();
        }
}
PORTC=0;

}
void finl()
{
PORTC=0;
while(1)
{
 PORTE.F1=1;
 Delay_ms(150);
 PORTE.F1=0;
 Delay_ms(2000);
 PORTC=0;
}
}


//*** Arm Handling ***//
void reset_arm()
{
  unsigned int i;
  for(i=0;i<50;i++)
  {
    PORTA.F2 = 1;
    Delay_us(800);    // pulse of 800us
    PORTA.F2 = 0;
    Delay_us(19200);
  }
  Delay_ms(200);
  for(i=0;i<50;i++)
  {
    PORTA.F3 = 1;
    Delay_us(1500);   // pulse of 1500us
    PORTA.F3 = 0;
    Delay_us(18500);
  }
}

void Arm_get()
{
  unsigned int i;
  for(i=0;i<50;i++)
  {
    PORTA.F2 = 1;
    Delay_us(1500);   // pulse of 1500us
    PORTA.F2 = 0;
    Delay_us(18500);
  }
  Delay_ms(200);
    for(i=0;i<50;i++)
  {
    PORTA.F3 = 1;
    Delay_us(800);    // pulse of 800us
    PORTA.F3 = 0;
    Delay_us(19200);
  }
  Delay_ms(200);
    for(i=0;i<50;i++)
  {
    PORTA.F2 = 1;
    Delay_us(800);    // pulse of 800us
    PORTA.F2 = 0;
    Delay_us(19200);
  }
}

void Arm_put()
{
 unsigned int i;
 for(i=0;i<50;i++)
  {
    PORTA.F3 = 1;
    Delay_us(1500);   // pulse of 1500us
    PORTA.F3 = 0;
    Delay_us(18500);
  }
}

//***Detecting obstacles***//
void scn()
{
int a;
  while(1)
{

TMR1H = 0; //Sets the Initial Value of Timer
TMR1L = 0; //Sets the Initial Value of Timer
PORTA.F0 = 1; //TRIGGER HIGH
Delay_us(10); //10uS Delay//
PORTA.F0 = 0; //TRIGGER LOW
while(!PORTA.F1); //Waiting for Echo
T1CON.F0 = 1; //Timer Starts
while(PORTA.F1); //Waiting for Echo goes LOW
T1CON.F0 = 0; //Timer Stops
a = (TMR1L | (TMR1H<<8)); //Reads Timer Value
a = a/58.82; //Converts Time to Distance
a = a + 1; //Distance Calibration

if(a>=2 && a<=11) //Check whether the result is valid or not (approx >2 and <11)
{
     PORTC=0;
     PORTE.F1=1;
     Sound_Play(880, 500);             // Play sound at 880Hz for 1 second
     PORTE.F1=0;
     Delay_ms(100);
     PORTE.F1=1;
     Sound_Play(880, 500);             // Play sound at 880Hz for 1 second
     PORTE.F1=0;
     arm_get();
     sch_cbn();break;

}
else
{
 run();
}
Delay_ms(100); 
}
}

void main() {


     ADCON1 =0x06 ; 				// Changes PORT to digital
     CMCON = 0x07 ; 				// Disable analog comparators

     TRISA=0x02;       				// Initialize PORTA
     TRISB=0xFF;       				// PORTB as input
     TRISD=0xFF;       				// PORTD as input
     TRISC=0x00;       				// PORTC as output
     TRISE=0x00;       				// PORTE as output
     T1CON = 0x10; 					//Initialize Timer Module

     PORTE=0;
	 
	 //****Initializing PWM module****//
	 PWM1_Init(2000);              	// Initialize PWM1 module at 5KHz
     PWM2_Init(2000);              	// Initialize PWM2 module at 5KHz
     PWM1_Start();                	// start PWM1
     PWM2_Start();               	// start PWM2
     PWM1_Set_Duty(180);        	// Set current duty for PWM1
     PWM2_Set_Duty(180);       		// Set current duty for PWM2
	 
     PORTC=0;
	 
     PORTE.F1=1;
     Sound_Init(&PORTE,0);
     Sound_Play(880, 250);          // Play sound at 880Hz for 1 second
     Delay_ms(200);
     Sound_Play(880, 250);          // Play sound at 880Hz for 1 second
     PORTE.F1=0;

     reset_arm();
	 
	 //****Waiting for button****//
     while(1)
     {
		if(PORTD.F2=1)
			{
				Sound_Play(760, 1000);             // Play sound at 880Hz for 1 second
				Delay_ms(500);
				Follow_line();
			break;
			}
     }

}