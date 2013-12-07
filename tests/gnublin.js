var assert = require("assert");
var gnublin = require("../build/Release/gnublin");
module.exports = {
    memberVariables : function(test){
	test.equals(gnublin.INPUT,"in")
	test.equals(gnublin.OUTPUT,"out")
	test.equals(gnublin.HIGH,1)
	test.equals(gnublin.LOW,0)
	test.done()
	
    }
        
};


