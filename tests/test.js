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

	test.throws(function(){
	    this.pca9555.PinMode()
	},Error);
	test.done();
    },
    digitalWrite : function(test){
	test.throws(function(){
	    this.pca9555.DigitalWrite();
	},Error);
	test.throws(function(){
	    this.pca9555.DigitalWrite("a","b")
	},Error)
	test.done()
    },
    
    digitalRead : function(test){
	test.throws(function(){
	    this.pca9555.DigitalRead()
	},Error)
	test.throws(function(){
	    this.pca9555.DigitalRead("a")
	},Error);
	test.done()
	
    }

    
};


