MMUP_PREFIX = ../..

sound.ogg: sound.wav
	-rm sound.ogg
	ffmpeg -i sound.wav  -acodec libvorbis sound.ogg

sound.wav: sound.pcm
	-rm sound.wav
	ffmpeg -f s16le -ar 44.1k -ac 2 -i sound.pcm sound.wav

sound.pcm: sine100 sine120_p sine160_p chord_p
	$(MMUP_PREFIX)/mmup_mix sine100 sine120_p sine160_p chord_p | $(MMUP_PREFIX)/mmup_pcm > sound.pcm

sine100:
	$(MMUP_PREFIX)/mmup_sine 100 1.4 | $(MMUP_PREFIX)/mmup_vol 0.3 > sine100

sine120:
	$(MMUP_PREFIX)/mmup_sine 120 1.4 | $(MMUP_PREFIX)/mmup_vol 0.3 > sine120

sine160:
	$(MMUP_PREFIX)/mmup_sine 160 1.4 | $(MMUP_PREFIX)/mmup_vol 0.3 > sine160


sine120_p: sine120
	cat sine120 | $(MMUP_PREFIX)/mmup_ssilence 1.3 > sine120_p

sine160_p: sine160
	cat sine160 | $(MMUP_PREFIX)/mmup_ssilence 2.6 > sine160_p


chord: sine200 sine240 sine320
	$(MMUP_PREFIX)/mmup_mix sine200 sine240 sine320 > chord

chord_p: chord
	cat chord | $(MMUP_PREFIX)/mmup_ssilence 4.0 > chord_p


sine200:
	$(MMUP_PREFIX)/mmup_sine 200 1.4 | $(MMUP_PREFIX)/mmup_vol 0.3 > sine200

sine240:
	$(MMUP_PREFIX)/mmup_sine 240 1.4 | $(MMUP_PREFIX)/mmup_vol 0.3 > sine240

sine320:
	$(MMUP_PREFIX)/sine 320 1.4 | $(MMUP_PREFIX)/mmup_vol 0.3 > sine320

clean:
	-rm sound.ogg sound.wav sound.pcm sine100 sine120 sine160 sine120_p sine160_p chord chord_p sine200 sine240 sine320
	
