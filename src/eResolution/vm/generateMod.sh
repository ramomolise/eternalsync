#!/bin/bash

cd bin
g++ ./generator.cpp && ./a.out
mv autoStart.sh ..

rm cvtInfo.txt
rm monitorRes.txt
rm a.out

echo "Add autoStart.sh to Start Up | Mod Generation Complete"
read -p "Press any key to continue"
