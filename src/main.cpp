#include <mbed.h>
#include <C12832.h>

C12832 lcd( D11, D13, D12, D7, D10 );
static int n=0;

void display(void)
{
	lcd.locate(0,0);
	lcd.printf("Button pressed %2d times", ++n);
}

void reset(void)
{
   n=0;
   lcd.locate(0,0);
   lcd.printf("Button reset count = %2d", n);
}

int main(void)
{
	InterruptIn sw(SW2);
        InterruptIn sw3(SW3);
	EventQueue  q;

	sw.fall( q.event(display) );
        sw3.fall( q.event(reset));

	q.dispatch();
}

