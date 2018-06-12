#!/usr/bin/env bash

date_today=`date +"%m-%d-%Y"`
printf "\t\tdate_today =\t%s\n" $date_today

date_yesterday=`date -d "1 day ago" +"%m-%d-%Y"`
printf "\tdate_yesterday =\t%s\n" $date_yesterday

date_tomorrow=`date -d "1 day" +"%m-%d-%Y"`
printf "\t\tdate_tomorrow =\t%s\n" $date_tomorrow

date_10_days_from_01May2018=`date -d "05/01/2018 + 10 days" +"%m-%d-%Y"`
printf "date_10_days_from_01May2018 =\t%s\n" $date_10_days_from_01May2018

date_1_year_from_today=`date -d "1 year" +"%m-%d-%Y"`
printf "date_1_year_from_today =\t%s\n" $date_1_year_from_today

thismonth=`date +%m`
nextmonth=`expr $thismonth + 1`
useyear=`date +%Y`
if [ $nextmonth -eq 13 ]; then
        nextmonth=`expr $nextmonth - 12`
        useyear=`$expr $useyear + 1`
fi
date_last_day_of_this_month=`date -d "$nextmonth/1/$useyear 1 day ago" +"%m-%d-%Y"`
printf "date_last_day_of_this_month =\t%s\n" $date_last_day_of_this_month

thismonth=`date +%m`
twomonths=`expr $thismonth + 2`
useyear=`date +%Y`
if [ $twomonths -ge 13 ]; then
        twomonths=`expr $twomonths - 12`
        useyear=`$expr $useyear + 1`
fi
date_last_day_of_next_month=`date -d "$twomonths/1/$useyear 1 day ago" +"%m-%d-%Y"`
printf "date_last_day_of_next_month =\t%s\n" $date_last_day_of_next_month

thismonth=`date +%m`
useyear=`date +%Y`
date_last_day_of_prev_month=`date -d "$thismonth/1/$useyear 1 day ago" +"%m-%d-%Y"`
printf "date_last_day_of_prev_month =\t%s\n" $date_last_day_of_prev_month

