#!/bin/bash

pfx="../../"

./mkbar.sh 1-1.bar 1-1-bar.mmup 0.7
./mkbar.sh 1-2.bar 1-2-bar.mmup 0.7
./mkbar.sh 1-3.bar 1-3-bar.mmup 0.7
./mkbar.sh 1-4.bar 1-4-bar.mmup 0.7

./mkbar.sh 2-3.bar 2-3-bar.mmup 0.2
./mkbar.sh 2-4.bar 2-4-bar.mmup 0.2

./mkbar.sh 3-1.bar 3-1-bar.mmup 0.1
./mkbar.sh 3-1.bar 3-2-bar.mmup 0.1
./mkbar.sh 3-3.bar 3-3-bar.mmup 0.1
./mkbar.sh 3-4.bar 3-4-bar.mmup 0.05

cat 1-2-bar.mmup | ../../mmup_ssilence 2.4 > 1-2-bar-p.mmup
cat 1-3-bar.mmup | ../../mmup_ssilence 4.8 > 1-3-bar-p.mmup
cat 1-4-bar.mmup | ../../mmup_ssilence 7.2 > 1-4-bar-p.mmup

cat 2-3-bar.mmup | ../../mmup_ssilence 4.8 > 2-3-bar-p.mmup
cat 2-4-bar.mmup | ../../mmup_ssilence 7.2 > 2-4-bar-p.mmup

cat 3-2-bar.mmup | ../../mmup_ssilence 2.4 > 3-2-bar-p.mmup
cat 3-3-bar.mmup | ../../mmup_ssilence 4.8 > 3-3-bar-p.mmup
cat 3-4-bar.mmup | ../../mmup_ssilence 7.2 > 3-4-bar-p.mmup

${pfx}mmup_mix 1-1-bar.mmup 3-1-bar.mmup 1-2-bar-p.mmup 3-2-bar-p.mmup 1-3-bar-p.mmup 2-3-bar-p.mmup 3-3-bar-p.mmup 2-4-bar-p.mmup 1-4-bar-p.mmup 3-4-bar-p.mmup | ${pfx}mmup_pcm > sound.pcm

rm -f sound.wav
ffmpeg -f s16le -ar 44.1k -ac 2 -i sound.pcm sound.wav

rm -f sound.ogg
ffmpeg -i sound.wav  -acodec libvorbis sound.ogg
