# NTP_clock

A DIY digital Network Time Protocol (NTP) clock and temperature display with adaptive brightness. Built with an Arduino TIAN and an MAX7221 LED display driver.

## Cloning this repository

This project contains a submodule. Run the following commands to download the submodule to a cloned repository:

```posh
git submodule init 
git submodule update
```

## Linux configuration

### Network Time Protocol (NTP)

Install a different version of Network Time Protocol (NTP) daemon and run it (might need -g and/or -n options):

```bash
opkg install ntpd
ntpd time.google.com
```

### Time zone

Set the time zone through Arduino Luci interface (**not** Arduino Configuration Wizard):

```
Applications > Arduino > Arduino Luci > System > System > Timezone
```

Confirm that the time zone environment variable is set correctly:

```bash
cat /etc/TZ
```

### Temperature

Requires a **/root/config.py** file containing a [Met Office API key](https://www.metoffice.gov.uk/services/data/datapoint/api):

```bash
MET_OFFICE_API_KEY = '<Your DataPoint API key>'
```

Reguires the following line in the **/etc/rc.local** file so that the script that regularly updates the temperature is executed once the system init is finished:

```bash
bash /root/temperature.sh
```

### Shell connectors

Enable the Ciao shell connector by editing the following file:

```
/usr/lib/python2.7/ciao/conf/shell.ciao.json.conf
```

  



