#! /bin/bash

workdir=${PWD}/..
output=${workdir}/output
tools=${workdir}/analysis
mkdir -p ${output}

cd ${workdir}
make clean
make OPT+=-DPERFORMANCE

function random_input {
    ${tools}/random.sh -m 100000 -n $(( 2*$1 )) | awk 'BEGIN{tmp=0;} { if (FNR%2 != 0) tmp = $1; else print int(tmp), $1/1000. }'
}

function ordered_input {
    ${tools}/random.sh -m 100000 -n $1 | awk ' { print FNR, $1/1000. }'
}

{
    for size in 100 500 1000 5000 10000 15000 20000 25000 30000
    do
	{
	    for ii in {1..10}
	    do
		random_input $size | ${workdir}/tree.x
	    done
	} | awk -v run="$size" -f ${tools}/avg_min_max.awk
    done
} > ${output}/test_unordered.dat

{
    for size in 100 500 1000 5000 10000 15000 20000 25000 30000
    do
	{
	    for ii in {1..10}
	    do
		ordered_input $size | ${workdir}/tree.x
	    done
	} | awk -v run="$size" -f ${tools}/avg_min_max.awk
    done
} > ${output}/test_ordered.dat

cd ${tools}
    
