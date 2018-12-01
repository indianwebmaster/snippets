#!/bin/bash
while [ 1 ]; do
	rc=""
	ping -c 2 www.comcast.net > /dev/null 2>&1
	if [ $? -eq 0 ]; then
		rc="Passed"
	else
		rc="Failed"
	fi
	echo "$rc `date`" >> /var/tmp/pingtest_out.txt
	sleep 2
done
