#!/usr/bin/env bash

set -e

cd /Users/ethan/qmk_firmware
make lily58:ebai101:dfu
make lily58:ebai101:avrdude
