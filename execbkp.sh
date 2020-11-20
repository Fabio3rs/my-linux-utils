#!/bin/bash

TARGET_SNAPSHOT_DIR="$(date +%s)"
echo $TARGET_SNAPSHOT_DIR
mkdir btbkp/$TARGET_SNAPSHOT_DIR
btrfs subvolume snapshot -r up/ btbkp/$TARGET_SNAPSHOT_DIR

