#!/bin/bash

mcs -t:library -out:Blitz2k18Helper.dll Blitz2k18Helper.cs
mcs -reference:Blitz2k18Helper.dll -out:MyBot.o MyBot.cs
mcs -reference:Blitz2k18Helper.dll -out:RandomBot.o RandomBot.cs 
./blitz2k18 -f 2 -d "30 30" "./MyBot.o" "./RandomBot.o"
