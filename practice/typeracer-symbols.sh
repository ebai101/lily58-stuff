#!/usr/bin/env bash

./symbols.py > symbols.txt
typeracer -r "$(cat symbols.txt)"
