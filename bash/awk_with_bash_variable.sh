# A simple example to show how you can use a bash variable within an awk script.
# Inspiration from: https://stackoverflow.com/questions/19075671/how-do-i-use-shell-variables-in-an-awk-script

# We will just look for a column header match in a file header, moving one column at a time
# The column header is expected in the 1st 10 lines in the file (hence the head -10 below)
in_file="$1"
i=1
found=0
chk_string="COL_009"
while [ $found -eq 0 -a $i -le 10 ]; do
  # The technique below $"'"$i"'" is a way to insert a bash variable in an awk variable assignment
  # ----------------------------------------------------------------------------------------------
  awk '{print $"'"$i"'"}' "$in_file" | head -10 | grep $chk_string > /dev/null 2> /dev/null
  if [ $? -eq 0 ]; then
    found=1
  else
    i=$(expr $i + 1)
  fi
done
if [ $found -eq 1 ]; then
  echo "Column match found in column number $i"
else
  echo "No Column match found"
fi
