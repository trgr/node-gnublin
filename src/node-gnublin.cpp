#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "pca9555.h"

using namespace v8;

Handle<Value> CreateObject(const Arguments& args) {
  HandleScope scope;
  
  Local<Object> obj = Object::New();
  obj->Set(String::NewSymbol("INPUT"), String::New("in"));
  
  return scope.Close(obj);
}

void InitAll(Handle<Object> exports) {
  pca9555::Init(exports);
  
  /* Expos some properties matching constants found in gnublin.cpp
     for convenience
   */
  exports->Set(String::NewSymbol("INPUT"), String::New(INPUT));
  exports->Set(String::NewSymbol("OUTPUT"),String::New(OUTPUT));
  exports->Set(String::NewSymbol("HIGH"),  Number::New(HIGH));
  exports->Set(String::NewSymbol("LOW"),   Number::New(LOW));
}

NODE_MODULE(gnublin, InitAll)
