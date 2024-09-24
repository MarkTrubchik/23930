#include <stdio.h>
#include <time.h>
#include <stdlib.h>

extern char *tzname[];

int main() {
    putenv("TZ=America/Los_Angeles");
    time_t now;
    (void)time(&now);
    printf("%s", ctime(&now));
    const struct tm *sp = localtime(&now);
    printf("%d/%d/%02d %d:%02d %s\n",
        sp->tm_mon + 1, sp->tm_mday,
        sp->tm_year - 100, sp->tm_hour,
        sp->tm_min, tzname[sp->tm_isdst]);
    exit (0);
}
