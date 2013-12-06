var assert = require("assert");
var gnublin = require("../build/Release/gnublin");
/* Limited testing can be done when we're not guaranteed that a relay is connected when user is installing so the tests for good output is limited to ranges including -1 (failiure as when no board is connected) */
function InRange(v,a,b){
    if(v>=a && b>=v)
	return true
    return false
}

function Either(v,a,b){
    if(v==a || v==b)
	return true
    
    return false
}

module.exports = {
    setUp : function(cb){
	this.pca9555 = new gnublin.pca9555()
	
	cb()
    },
    tearDown : function(cb){
	cb();
    },
    pinMode : function(test){
	/* Loose .this context when checking exceptions*/
	var p = this.pca9555
	
	test.throws(function(){
	    p.PinMode()
	},Error,"PinMode does not throw an exception when passed no arguments")
	
	test.throws(function(){
	    p.PinMode(1)
	},Error,"PinMode does not throw an exception when passed exactly one argument");

	test.throws(function(){
	    p.PinMode(1,1)
	},Error,"PinMode does not throw an exception when second argument is not a string");
	test.throws(function(){
	    p.PinMode("a","in")
	},Error,"PinMode does not throw an exception when first argument is not a number");
	
	
	test.ok(typeof p.PinMode(0,"in") == "number","PinMode does return a number")
	test.ok(Either(p.PinMode(0,"in"),-1,1),"PinMode does not return either -1 or 1")
	test.done();
    },
    digitalWrite : function(test){
	var p = this.pca9555
	test.throws(function(){
	    p.DigitalWrite();
	},Error,"DigitalWrite does not throw an exception when passed no arguments")
	
	test.throws(function(){
	    p.DigitalWrite(1)
	},Error,"DigitalWrite does not throw an exception when passed exactly one argument")
	
	test.throws(function(){
	    p.DigitalWrite("a","b")
	},Error,"DigitalWrite does not throw an exception when passed non-numerical arguments")
	
	test.ok(typeof p.DigitalWrite(1,1) == "number","DigitalWrite does not return number");
	test.ok(Either(p.DigitalWrite(1,1),-1,1),"DigitalWrite does not return either -1 or 1")
	test.done()
    },
    
    digitalRead : function(test){
	var p = this.pca9555
	test.throws(function(){
	    p.DigitalRead()
	},Error,"DigitalRead does not throw an exception when passed no arguments")
	test.throws(function(){
	    p.pca9555.DigitalRead("a")
	},Error,"DigitalRead does not throw an exception when passed a non-numerical argument");
	test.ok(InRange(p.DigitalRead(0),-1,1),"DigitalRead does not return a value in the range -1 1")
	test.done()
	
    },
    portMode : function(test){
	var p = this.pca9555
	test.throws(function(){
	    p.PortMode()
	},Error,"PortMode does not throw an exception when passed no arguments")
	test.throws(function(){
	    p.PortMode(1,1)
	},Error,"PortMode does not throw an exception when second argument is not a string")
	test.throws(function(){
	    p.PortMode("a","in")
	},Error,"PortMode does not throw an exception when first argument is not a number")
	test.ok(typeof p.PortMode(0,"in") == "number","PortMode does not return a number")
	test.ok(Either(p.PortMode(0,"in"),-1,1),"PortMode does not return -1 or 1")
	test.done()
	
    }
        
};


