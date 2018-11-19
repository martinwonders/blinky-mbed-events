#include <mbed.h>
#include <C12832.h>

C12832 lcd( D11, D13, D12, D7, D10 );

void display(void)
{
	static int n=0;
	lcd.locate(0,0);
	lcd.printf("Button pressed %2d times", ++n);
}

int main(void)
{
	InterruptIn sw(SW2);
	EventQueue  q;

	sw.fall( q.event(display) );

	q.dispatch();
}

