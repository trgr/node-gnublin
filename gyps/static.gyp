{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cpp", "myobject.cpp"],
      "dependencies" : ["gnublin_gpio"],
      "
      },
    {
        "target_name": "gnublin_gpio",
        "source" : [ "gnublin.cpp"],
	"type" : "static_library"
    }

    ]
}