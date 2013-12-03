var assert = require("assert");
var gnublin = require("../build/Release/gnublin");

module.exports = {
    setUp : function(cb){
	this.pca9555 = new gnublin.pca9555()
	cb()
    },
    tearDown : function(cb){
	cb();
    },
    
    pinMode : function(test){
	test.equals(this.pca9555.PinMode(1,"out"),1);
	test.equals(this.pca9555.PinMode(2,"in"),1);
	test.equals(this.pca9555.PinMode(3,"out"),1);
	test.equals(this.pca9555.PinMode(4,"foo"),-1);
	test.done()
    },
    digitalWrite: function(test){
	test.equals(this.pca9555.DigitalWrite(1,1),1);
	test.equals(this.pca9555.DigitalWrite(2,1),-1);
	test.equals(this.pca9555.DigitalWrite(3,0),1);
	test.equals(this.pca9555.DigitalWrite(4,-1),1);
	test.done();
    },
    readState : function(test){
	test.equals(this.pca9555.ReadState(1),1);
	test.equals(this.pca9555.ReadState(2),-1);
	test.equals(this.pca9555.ReadState(3),0);
	test.equals(this.pca9555.ReadState(4),-1);
	test.done();
    }

};


