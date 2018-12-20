#!/bin/bash -xv
fileArray=( "$@" )
fileArrayLength=${#fileArray[*]}
fileExists(){
	mkdir keys
	for (( i=0; i<${fileArrayLength}-1; i++ ));
	do
		cat "${fileArray[$i]}" >> "${fileArray[-1]}"
  		mv "${fileArray[$i]}" ~/PST/Assignment3/program-3-fall18-Erv16/keys/ 
	done	
}
for i in "${fileArray[@]}";
do 
	echo "$i"
	if [ ! -e $i ];
	then
		echo "File does not exist"
		exit
	else
		check=1
	fi
done
if [ "$check" = 1 ];
then
	fileExists "${fileArray[@]}"
fi




