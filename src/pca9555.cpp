#define BUILDING_NODE_EXTENSION
#define BOARD RASPBERRY_PI
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
  NODE_SET_PROTOTYPE_METHOD(tpl,"DigitalWrite",pca9555::DigitalWrite);
  NODE_SET_PROTOTYPE_METHOD(tpl,"DigitalRead",pca9555::DigitalWrite);
  NODE_SET_PROTOTYPE_METHOD(tpl,"ReadState",pca9555::DigitalWrite);
  NODE_SET_PROTOTYPE_METHOD(tpl,"SetAddress",pca9555::DigitalWrite);
  

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
  int pin  = args[0]->IntegerValue();
  int value  = args[1]->IntegerValue();
  int result = obj->pca9555_gnublin->digitalWrite(pin,value);
  return scope.Close(Number::New(result));
}

Handle<Value> pca9555::DigitalRead(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  int pin  = args[0]->IntegerValue();
  int result = obj->pca9555_gnublin->digitalRead(pin);
  return scope.Close(Number::New(result));
}

Handle<Value> pca9555::ReadState(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  int pin  = args[0]->IntegerValue();
  int result = obj->pca9555_gnublin->readState(pin);
  return scope.Close(Number::New(result));
}

void pca9555::SetAddress(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  int address  = args[0]->IntegerValue();
  obj->pca9555_gnublin->setAddress(address);
  return;
}

Handle<Value> pca9555::PinMode(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  int pin  = args[0]->IntegerValue();

  Local<String> v8mode = args[1]->ToString();
  String::Utf8Value umode(v8mode);
  const char* mode(*umode);
  
  int result = obj->pca9555_gnublin->pinMode(pin,mode);

  return scope.Close(Number::New(result));
  
}

Handle<Value> pca9555::PortMode(const Arguments& args){
  HandleScope scope;
  pca9555* obj = ObjectWrap::Unwrap<pca9555>(args.This());
  int port  = args[0]->IntegerValue();

  Local<String> v8mode = args[1]->ToString();
  String::Utf8Value umode(v8mode);
  const char* mode(*umode);
  
  int result = obj->pca9555_gnublin->portMode(port,mode);

  return scope.Close(Number::New(result));  
}

