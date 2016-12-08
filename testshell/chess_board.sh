echo "Enter the row"
read row
echo "Enter the column"
read column
for((i=0;i<row;i++))
do
	for((j=0;j<column;j++))
	do
		if [ `expr $(($i+$j)) % 2` -eq 0 ]; then
			echo -e -n "\033[47m  "
		else
			echo -e -n "\033[40m  "
	fi
	done
	echo -e -n "\033[0m"
	echo
done
echo -e -n "\033[0m"
echo

