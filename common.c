#include "common.h"

void putchar(char ch);

int checksign(int x)
{
        return ((x>0)-(x<0));
}

void printf(const char *fmt, ...) {
	va_list vargs;
	va_start(vargs, fmt);

	while(*fmt) {
		if(*fmt == '%') {
			fmt++; //This is for %
			switch(*fmt) {
				case 0:
					goto end;
				case '%': //print %
					putchar(*fmt);
					break;
				case 's': {//print a NULL terminated string
						const char *s = va_arg(vargs, const char *);
						while(*s) {
							putchar(*s);
							s++;
						}
						break;
					  }
				case 'd': {
						int value = va_arg(vargs, int);
						if (value < 0) {
							putchar('-');
							value = -value;
 						}
						int divisor = 1;
						while (value / divisor >= 10)
							divisor *= 10;

						while (divisor) {
							putchar('0' + value / divisor);
							value %= divisor;
							divisor /= 10;
						}
						break;
					  }
				case 'x': case'X': {//print an integer in hexadecimal
						int value = va_arg(vargs, int);
						for(int i=7; i>=0; i--) {
							int nibble = (value >> (i * 4)) & 0xf;
							putchar("0123456789abcdef"[nibble]);		
						}
					  }
			}
		} else {
			putchar(*fmt);
		}

		fmt++;
	} 

end:
	va_end(vargs);
}
