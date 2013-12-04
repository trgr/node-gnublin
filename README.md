node-gnublin
============

Bindings for the gnublin api http://en.gnublin.org/index.php/API

Supporting so far only pca9555 on raspberry-pi

Usage
====

```
var gnublin = require("gnublin");
var pca9555 = new gnublin.pca9555();

/* Then do stuff to your relay like:*/

pca9555.PinMode(1,"out");
pca9555.DigitalWrite(1,1);
pca9555.SetAddress(0x21);

var byte = pca9555.ReadPort(0).toString(16);

```

So far the library supports:

`int PinMode(int pin,string mode)`

`int PortMode(int port, string mode)`

`int DigitalWrite(int pin, int value)`

`int DigitalRead(int pin)`

`int ReadState(int pin)`

`int ReadPort(int port)`

`void SetDeviceFile(string file)`

`void SetAddress(int address)`

`bool Fail()`

`string GetErrorMessage()`

Modes are either `"in" or "out"` 

npm package in the works.