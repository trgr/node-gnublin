var assert = require("assert");
var gnublin = require("../build/Release/gnublin");
var gpio = new gnublin.pca9555();

assert.equal(gpio.PinMode(1,"out"),1,"SetPin 1 out fail")
assert.equal(gpio.PinMode(4,"out"),-1,"SetPin 4 out success") //Should fail according to gnublin.cpp
assert.equal(gpio.DigitalWrite(1,1),1,"Could not set high");



