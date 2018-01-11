#!/bin/bash

javac MyBot.java
javac RandomBot.java
./blitz2k18 -f 2 -d "30 30" "java MyBot" "java RandomBot"
