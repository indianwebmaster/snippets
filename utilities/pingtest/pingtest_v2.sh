#!/bin/bash
outfile=/var/tmp/pingtest.out
passcount=0
failcount=0
state="passing"
last_state=$state

fail_start_time="`date`"
fail_end_time="`date`"

echo "Start time - `date`" >> $outfile
while [ 1 ]; do
	ping -c 2 www.comcast.net > /dev/null 2>&1
	if [ $? -eq 0 ]; then
		passcount=`expr $passcount + 1`
		state="passing"
	else
		failcount=`expr $failcount + 1`
		state="failing"
	fi

	if [ "$state" = "passing" ]; then
		if [ "$last_state" = "failing" ]; then
			# Means we are switching from failing to passing
			fail_end_time="`date`"
			str="fail from $fail_start_time to $fail_end_time, $failcount * 2 secs"
			echo $str >> $outfile
			xmessage -center -timeout 1 "$str"
		fi
	else
		if [ "$last_state" = "passing" ]; then
			# Means we are switching from passing to failing
			fail_start_time="`date`"
			echo "Pass from `date`, last passcount = $passcount" >> $outfile
		fi
	fi
	last_state=$state
	sleep 2
done
echo "Finish time - `date`" >> $outfile
