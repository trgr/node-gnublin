#!/bin/sh
alias node-gyp="node-gyp --python=/usr/bin/python2"
node-gyp clean && node-gyp configure && node-gyp build
