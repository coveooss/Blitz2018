#!/bin/bash

if hash python3 2>/dev/null; then
    ./blitz2k18 -f 2 -d "30 30" "python3 MyBot.py" "python3 RandomBot.py"
else
    echo "Python3 is required to run"
fi
