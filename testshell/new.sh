echo "Check character program:"
echo "Enter a letter or digit"
read char_in
case $char_in in
[a-z]|[A-Z]) echo "You entered a letter";;
[0-9]) echo "You entered a digit";;
*) echo "You ditn't  enter a digit or a letter";;
esac

