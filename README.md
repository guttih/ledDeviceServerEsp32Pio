# ledDeviceServerEsp32Pio
An application running on esp32 which controls a addressable light strip using
the [fastLed] library.  Supported strips are WS2811, WS2801 and  APA102.

A new program can be uploaded over the air (OTA) and controlled using [VoffCon].

## Pins
__GPIO16__ is connected to DI or Data on the strip and if the strip has
a clock pin then __GPIO17__ is connected to thi CL or Clock pin.

Some older projects use the GPIO13 and GPIO14 pins, but these pins ADC2 which
are used by the Wifi library and should not be used with wifi. 

## Development

For information intended for development of this project can be found in the
[development.adoc](docs/development.adoc) document.

[fastLed]: https://fastled.io/
[VoffCon]: http://voffcon.com/