#!/bin/bash
while /bin/true; do
  if ["$(date +%S)" == "00"]; then
    python /root/temperature_uk.py &> temperature.txt
  fi
  #sleep 55m
done &
