#!/bin/bash
python /root/temperature_uk.py 352409 > /root/temperature.txt
while true
do
  if [ "$(date +%M)" = "00" ]; then
    python /root/temperature_uk.py 352409 > /root/temperature.txt
    sleep 55m # update only once per hour
  fi
done &