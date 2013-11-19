#! /bin/bash

# Quick and dirty "deploy" script

set -e

mnt.sh sd1
cp kernel.img /mnt/sd1
umnt.sh sd1
