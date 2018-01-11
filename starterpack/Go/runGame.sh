#!/bin/bash

export GOPATH="$(pwd)"

./blitz2k18 -f 2 -d "30 30" "go run MyBot.go" "go run RandomBot.go"
