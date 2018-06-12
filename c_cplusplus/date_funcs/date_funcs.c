#include <stdio.h>
#include <string.h>
#include <time.h>

char* julian_to_dateString(int julianDate)
{
        static char dateStr[32];
        time_t t;
        struct tm *ptm;
        int month_len[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        char month_str[12][12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        int leap = 0;
        int dayOfMonth = julianDate;
        int month, year;

        time(&t);
        ptm = localtime(&t);
        year = 1900 + ptm->tm_year;
        leap = ( (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)) );
        for (month=0; month<12; month++) {
                int mlen = month_len[month];
                if (leap && month)
                        mlen++;
                if (dayOfMonth <= mlen)
                        break;
                dayOfMonth -= mlen;
        }
        sprintf (dateStr,"%d/%d/%d",month+1,dayOfMonth+1,year);
        return dateStr;
}

main()
{
        time_t t;       /* Time since epoch in seconds */
        char datetimestr[64];
        struct tm *p_tm;
        struct tm vtm;
        int id = 0;

        time(&t);
        printf ("%d: time(time_t *t): Time since epoch in seconds: t = %d\n\n", ++id, t);

        printf ("%d: char *ctime (time_t *t) : String from Time in epoch = %s\n", ++id, ctime (&t));

        printf ("%d: struct tm *gmtime (time_t *t): UTC struct tm from Time in epoch\n", ++id);
        p_tm = gmtime(&t);
        printf ("(tm_mon/tm_mday/(1900+tm_year)=(%d/%d/%d),"
                        " tm_wday=%d, tm_yday(julianDay)=%d, tm_isdst(DstSetYesNo)=%d,"
                        " (tm_hour:tm_min:tm_sec)=(%d:%d:%d)\n\n",
                        p_tm->tm_mon, p_tm->tm_mday, (1900 + p_tm->tm_year),
                        p_tm->tm_wday, p_tm->tm_yday, p_tm->tm_isdst,
                        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);

        printf ("%d: struct tm *localtime(time_t *t): Localtime struct tm from Time in epoch\n", ++id);
        p_tm = localtime(&t);
        printf ("(tm_mon/tm_mday/(1900+tm_year)=(%d/%d/%d),"
                        " tm_wday=%d, tm_yday(julianDay)=%d, tm_isdst(DstSetYesNo)=%d,"
                        " (tm_hour:tm_min:tm_sec)=(%d:%d:%d)\n\n",
                        p_tm->tm_mon, p_tm->tm_mday, (1900 + p_tm->tm_year),
                        p_tm->tm_wday, p_tm->tm_yday, p_tm->tm_isdst,
                        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);

        printf ("%d: char *julian_to_dateString(%d) = %s\n\n", ++id, p_tm->tm_yday, julian_to_dateString(p_tm->tm_yday));

        printf ("%d: char *asctime(struct tm *ptm): String from struct tm from Time in epoch = %s\n", ++id, asctime(p_tm));

        printf ("--- Populate an empty struct tm with today's mm/dd/yy and DST ---\n");
        memset (&vtm,0,sizeof(struct tm));
        vtm.tm_year = p_tm->tm_year;
        vtm.tm_mday = p_tm->tm_mday;
        vtm.tm_mon = p_tm->tm_mon;
        vtm.tm_isdst = p_tm->tm_isdst;
        printf ("(tm_mon/tm_mday/(1900+tm_year)=(%d/%d/%d),"
                        " tm_wday=%d, tm_yday(julianDay)=%d, tm_isdst(DstSetYesNo)=%d,"
                        " (tm_hour:tm_min:tm_sec)=(%d:%d:%d)\n\n",
                        vtm.tm_mon, vtm.tm_mday, (1900 + vtm.tm_year),
                        vtm.tm_wday, vtm.tm_yday, vtm.tm_isdst,
                        vtm.tm_hour, vtm.tm_min, vtm.tm_sec);

        t = mktime(&vtm);
        printf ("%d: time_t mktime(struct tm *ptm): Populate struct tm (see above) and convert it to time_t = %d\n\n", ++id, t);

        printf ("%d: char *ctime (time_t *t) : String from Time above = %s\n", ++id, ctime (&t));

        printf ("%d: struct tm *gmtime (time_t *t): UTC struct tm from Time above\n", ++id);
        p_tm = gmtime(&t);
        printf ("(tm_mon/tm_mday/(1900+tm_year)=(%d/%d/%d),"
                        " tm_wday=%d, tm_yday(julianDay)=%d, tm_isdst(DstSetYesNo)=%d,"
                        " (tm_hour:tm_min:tm_sec)=(%d:%d:%d)\n\n",
                        p_tm->tm_mon, p_tm->tm_mday, (1900 + p_tm->tm_year),
                        p_tm->tm_wday, p_tm->tm_yday, p_tm->tm_isdst,
                        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);

        printf ("%d: struct tm *localtime(time_t *t): Localtime struct tm from Time above\n", ++id);
        p_tm = localtime(&t);
        printf ("(tm_mon/tm_mday/(1900+tm_year)=(%d/%d/%d),"
                        " tm_wday=%d, tm_yday(julianDay)=%d, tm_isdst(DstSetYesNo)=%d,"
                        " (tm_hour:tm_min:tm_sec)=(%d:%d:%d)\n\n",
                        p_tm->tm_mon, p_tm->tm_mday, (1900 + p_tm->tm_year),
                        p_tm->tm_wday, p_tm->tm_yday, p_tm->tm_isdst,
                        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);

        printf ("%d: char *asctime(struct tm *ptm): String from struct tm from Time above = %s\n", ++id, asctime(p_tm));

}

