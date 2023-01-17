# Temperature sensor module

## Description

This project based on ESP8266 and a Dallas DS18B20 is a low energy sensor
for get one or multiple temperatures and send or listen on a wifi network.

Mesures can be sent to a remote web server or listen in a specific port.
A low-energy can make mesures and sent only few times by day for avoid wifi
power consumation.

You can set configuration on this code, on a local web server, or on a remote
webserver that return json config (updated at each mesures update)

Please see remote webserver at **TODO:** for maange remote settings and remote
mesurements.

## Settings

The esp8266 use deepsleep only when listen is disabled.
You must specify some settings like:

- Interval for mesurements
- Interval for upload mesurements to remote server
- Interval for update settings

The listen-http mode activate a webserver with a local page (basic authentification) with:

- Current mesurements
- Last mesurements (history limited by memory)
- Page for manage settings

The listen-tcp mode activate a webserver with tcp server for get values. This feature is compatible with Zabbix agent (See zabbix section).
