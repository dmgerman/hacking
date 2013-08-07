#!/bin/bash

install -D -m644 "10-apple-aluminium.rules" "/etc/udev/rules.d/10-apple-aluminium.rules"
install -D -m644 "apple_aluminium.keyfuzz" "/etc/keyfuzz/apple_aluminium.keyfuzz"
install -D -m755 "fix-apple-keyboard" "/usr/bin/fix-apple-keyboard"
install -D -m644 "hid_apple.conf" "/etc/modprobe.d/hid_apple.conf"
