#!/bin/bash

# Recycle deleted files
find /bkp/up -name '*.file_deleted' -exec /bkp/mvtorecycle.sh {} \;

# BTRFS read-only snapshot
./execbkp.sh




