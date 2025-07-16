#!/bin/bash

pfx="../../"
in_filename="$1"
out_filename="$2"
vol="$3"

count=0
while read -r note sil dur; do
    ${pfx}mmup_sine `${pfx}mmup_n2f $note` $dur | ${pfx}mmup_vol $vol | ${pfx}mmup_ssilence $sil > $count.mmup
    (( count++ ))
done < "$in_filename"

mm=""
for ((i=0; i<$count; i++))
do
  mm="${mm} ${i}.mmup"
done

echo "mixing $mm"

${pfx}mmup_mix ${mm} > "$out_filename"
rm -f ${mm}

