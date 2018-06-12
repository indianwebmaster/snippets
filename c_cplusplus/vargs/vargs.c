#include <stdarg.h>
#include <stdio.h>

void dbgprintf (char *format, ...) {
        va_list ap;

        va_start(ap, format);
        vprintf (format, ap);
        va_end(ap);
}

main() {
        dbgprintf ("Hello %d\n", 1);
}
