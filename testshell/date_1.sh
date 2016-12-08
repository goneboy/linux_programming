#set -x
d="`date +'%d'`"
d="`bc <<< \"$d % 2\"`"
if [ $d -eq 0 ];then
	echo $(date +'%yy/%m/%d %T')
else
	echo $(date +'%Y-%m-%d %T')
fi
