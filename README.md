# NTP_clock

A DIY digital Network Time Protocol (NTP) clock and temperature display with adaptive brightness. Built with an Arduino TIAN and an MAX7221 LED display driver.

## Linux configuration

Requires a **/root/config.py** file containing a [Met Office API key](https://www.metoffice.gov.uk/services/data/datapoint/api):

```bash
MET_OFFICE_API_KEY = '<Your DataPoint API key>'
```

Reguires the following line in the **/etc/rc.local** file so that the script that regularly updates the temperature is executed once the system init is finished:

```bash
bash /root/temperature.sh
```
  



