#define BUILDING_NODE_EXTENSION
#define BOARD RASPBERRY_PI
#include <sstream>
#include <node.h>
#include "pca9555.h"

using namespace v8;

Persistent<Function> pca9555::constructor;

pca9555::~pca9555() {
}

void pca9555::Init(Handle<Object> exports) {
  // constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);

  tpl->SetClassName(String::NewSymbol("pca9555"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  
  NODE_SET_PROTOTYPE_METHOD(tpl,"PinMode",pca9555::PinMode);
  NODE_SET_PROTOTYPE_METHOD(tpl,"PortMode",pca9555::PortMode);
  NODE_SET_PROTOTYPE_METHOD(tpl,"DigitalWrite",pca9555::DigitalWrite);
  NODE_SET_PROTOTYPE_METHOD(tpl,"DigitalRead",pca9555::DigitalRead);
  NODE_SET_PROTOTYPE_METHOD(tpl,"ReadState",pca9555::ReadState);
  NODE_SET_PROTOTYPE_METHOD(tpl,"SetAddress",pca9555::SetAddress);

  NODE_SET_PROTOTYPE_METHOD(tpl,"Fail",pca9555::Fail);
  NODE_SET_PROTOTYPE_METHOD(tpl,"GetErrorMessage",pca9555::GetErrorMessage);
  NODE_SET_PROTOTYPE_METHOD(tpl,"ReadPort",pca9555::ReadPort);
  NODE_SET_PROTOTYPE_METHOD(tpl,"WritePort",pca9555::WritePort);
  NODE_SET_PROTOTYPE_METHOD(tpl,"SetDeviceFile",pca9555::SetDeviceFile);
  

  constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("pca9555"), constructor);
}

Handle<Value> pca9555::New(const Arguments& args) {
  HandleScope scope;

  pca9555* obj = new pca9555();
  obj->pca9555_gnublin = new gnublin_module_pca9555();
  obj->Wrap(args.This());
  
  return args.This();
    
}
Handle<Value> pca9555::DigitalWrite(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());

  if(args.Length() != 2){
    ThrowException(Exception::Error(String::New("DigitalWrite expects 2 arguments")));
    return scope.Close(Undefined());
  }
		   
  if(!args[0]->IsInt32() || !args[1]->IsInt32()){
    ThrowException(Exception::TypeError(String::New("pin and value must be number")));
    return scope.Close(Undefined());
  }

  int pin  = args[0]->Int32Value();
  int value  = args[1]->Int32Value();
  int result = obj->pca9555_gnublin->digitalWrite(pin,value);
  return scope.Close(Number::New(result));
}

Handle<Value> pca9555::GetErrorMessage(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  const char* result = obj->pca9555_gnublin->getErrorMessage();
  return scope.Close(String::New(result));
}


Handle<Value> pca9555::Fail(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  bool result = obj->pca9555_gnublin->fail();
  return scope.Close(Boolean::New(result));
}

Handle<Value> pca9555::DigitalRead(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  
  if(args.Length() != 1){
    ThrowException(Exception::Error(String::New("DigitalRead expects 1 argument")));
    return scope.Close(Undefined());
  }
  
  if(!args[0]->IsInt32()){
    ThrowException(Exception::TypeError(String::New("DigitalRead expects first argument to be of type integer")));
    return scope.Close(Undefined());
  }

  int pin  = args[0]->Int32Value();
  int result = obj->pca9555_gnublin->digitalRead(pin);
  return scope.Close(Number::New(result));
}

Handle<Value> pca9555::ReadState(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  int pin  = args[0]->Int32Value();
  int result = obj->pca9555_gnublin->readState(pin);
  return scope.Close(Number::New(result));
}

Handle<Value> pca9555::WritePort(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  
  
  int port = args[0]->Int32Value();
  unsigned char value = args[0]->Int32Value();
  
  int result = obj->pca9555_gnublin->writePort(port,value);
  return scope.Close(Number::New(result));
}


Handle<Value> pca9555::ReadPort(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  if(args.Length() != 1){
    ThrowException(Exception::Error(String::New("ReadPort expects 1 argument")));
    return scope.Close(Undefined());
  }
    
  if(!args[0]->IsInt32()){
    ThrowException(Exception::TypeError(String::New("ReadPort expects first argument to be of type integer")));
    return scope.Close(Undefined());
  }

  int port  = args[0]->Int32Value();
  
  /* very hacky*/
  unsigned char uresult = obj->pca9555_gnublin->readPort(port);
  int result = uresult;
  return scope.Close(Number::New(result));
}

 Handle<Value> pca9555::SetAddress(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());

  if(args.Length() != 1){
    ThrowException(Exception::Error(String::New("SetAddress expects 1 argument")));
    return scope.Close(Undefined());
  }
  
  
  int address  = args[0]->Int32Value();
  obj->pca9555_gnublin->setAddress(address);
  return scope.Close(Undefined());
}

Handle<Value> pca9555::PinMode(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  
  if(args.Length() != 2){
    ThrowException(Exception::TypeError(String::New("PinMode expects 2 arguments")));
    return scope.Close(Undefined());
  }

  if(!args[0]->IsInt32() || !args[1]->IsString()){
    ThrowException(Exception::TypeError(String::New("PinMode expects first argument to be integer and second to be a string")));
    return scope.Close(Undefined());
  }
  
  int pin  = args[0]->Int32Value();

  Local<String> v8mode = args[1]->ToString();
  String::Utf8Value umode(v8mode);
  const char* mode(*umode);
  
  int result = obj->pca9555_gnublin->pinMode(pin,mode);

  return scope.Close(Number::New(result));
}

Handle<Value> pca9555::PortMode(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());

  if(args.Length() != 2){
    ThrowException(Exception::Error(String::New("PortMode expects 2 arguments")));
    return scope.Close(Undefined());
  }
    
  if(!args[0]->IsInt32() || !args[1]->IsString()){
    ThrowException(Exception::TypeError(String::New("PortMode expects first argument to be integer and second to be a string")));
    return scope.Close(Undefined());
  }
  
  int port  = args[0]->Int32Value();

  Local<String> v8mode = args[1]->ToString();
  String::Utf8Value umode(v8mode);
  const char* mode(*umode);
  
  int result = obj->pca9555_gnublin->portMode(port,mode);

  return scope.Close(Number::New(result));
}

Handle<Value> pca9555::SetDeviceFile(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  if(args.Length() != 1){
    ThrowException(Exception::Error(String::New("SetDeviceFile expects 2 arguments")));
    return scope.Close(Undefined());
  }
    
  if(!args[0]->IsString()){
    ThrowException(Exception::TypeError(String::New("SetDeviceFile expects first argument to be a string")));
    return scope.Close(Undefined());
  }
  
  Local<String> v8file = args[0]->ToString();
  String::Utf8Value ufile(v8file);
  const char* file(*ufile);
  
  obj->pca9555_gnublin->setDevicefile(file);

  return scope.Close(Undefined()); 
}

