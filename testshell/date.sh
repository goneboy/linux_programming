set -x
my_date=$((`date +'%d'`))
is_check=`expr $my_date % 2`
if [ $is_check -eq 0 ]; then
	echo "true"
else
	echo "false"
fi

