#!/usr/bin/env bash

cd /home/andrey/works/runos0.5/build
echo "******************************	CMAKE START		******************************"
cmake ..
echo "******************************	CMAKE COMPLETE	******************************"
echo "******************************	PREFIX START	******************************"
make prefix
echo "******************************	PREFIX COMPLETE	******************************"
echo "******************************	ALL START	******************************"
make
echo "******************************	ALL COMPLETE	******************************"
cd /home/andrey/works/runos0.5/