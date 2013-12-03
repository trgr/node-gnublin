#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "pca9555.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  pca9555::Init(exports);
}

NODE_MODULE(gnublin, InitAll)
