#! /bin/bash
info=`echo aaa`    
echo "info: "${info} 
OLD_IFS="$IFS" 
IFS=" " 
for files in  'ls \#*'
do 
    filename=($files)
    IFS="$OLD_IFS"
done
for x in ${filename[@]}
do
a=$( expr $x : '.*\([0-9]\{3\}\).*' )
#echo "$x"
#|sed 's/.*\([0-9]\{3\}\).*/\1/'`
mkdir Codeforces_Round_#$a
done
for x in ${filename[@]}
do
a=$( expr $x : '.*\([0-9]\{3\}\).*' )
#echo $x|sed 's/.*\([0-9]\{3\}\).*/\1/'
mv $x Codeforces_Round_#$a/
done
