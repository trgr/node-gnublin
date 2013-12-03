node-gnublin
============

Bindings for the gnublin api http://en.gnublin.org/index.php/API

Supporting so far only pca9555 on raspberry-pi

Usage
====

`
var gnublin = require("./gnublin");
var pca9555 = new gnublin.pca9555();

/* Then do stuff to your relay like:*/

pca9555.PinMode(1,"out");
pca9555.DigitalWrite(1,1);
pca9555.SetAddress(0x21);

`

So far the library supports:
`int PinMode(int pin,int value)`
`int DigitalWrite(int pin, int value)`
`int DigitalRead(int pin)`
`int ReadState(int pin)`
`void SetAddress(int address)`

npm package in the works.