echo -e "Enter a digit or a letter"	
read char_in	#read the character in

case $char_in in
[a-z]|[A-Z]) echo "You entered a letter";;
[0-9]) echo "You entered a digit";;
*) echo "You didn't enter a digit or a letter";;
esac


