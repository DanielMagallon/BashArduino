#! /usr/bin/env bash

minicom -O timestamp=extended -S ./script.minicom -C /tmp/reset-log.txt -D /dev/ttyACM0
