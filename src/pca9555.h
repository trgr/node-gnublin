#ifndef GPIO_H
#define GPIO_H

#include <node.h>
#include "gnublin.h"
class pca9555 : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> exports);

 private:
  ~pca9555();

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Fail(const v8::Arguments& args);
  static v8::Handle<v8::Value> SetDeviceFile(const v8::Arguments& args);
  static v8::Handle<v8::Value> PinMode(const v8::Arguments& args);
  static v8::Handle<v8::Value> PortMode(const v8::Arguments& args);
  static v8::Handle<v8::Value> DigitalWrite(const v8::Arguments& args);
  static v8::Handle<v8::Value> DigitalRead(const v8::Arguments& args);
  static v8::Handle<v8::Value> SetAddress(const v8::Arguments& args);
  static v8::Handle<v8::Value> ReadState(const v8::Arguments& args);
  static v8::Handle<v8::Value> ReadPort(const v8::Arguments& args);
  static v8::Handle<v8::Value> WritePort(const v8::Arguments& args);
  static v8::Handle<v8::Value> GetErrorMessage(const v8::Arguments& args);
  
  static v8::Persistent<v8::Function> constructor;

  double value_;
  gnublin_module_pca9555* pca9555_gnublin;
};

#endif
