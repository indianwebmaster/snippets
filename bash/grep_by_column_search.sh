# Say you have to search a file, with rows of columns separated by space or tabs, looking for a specific value in a specific column
# Now, if it was the first or 2nd column, you could just use grep with some Regex pattern. But, if yu want to search - say the 15th column
#   this can get tricky.
# Solution - don't just use grep - use "awk regex search"

cat filename | awk '$15 ~ /searchString/'

cat filename | awk '$15 ~ /24.[0-9][0-9]/'  # Search for all lines with 15 columns with 24.00 to 24.99

cat filename | awk '$15 ~ /[A-Z].. [0-9]/'  # Search for all lines with 15th column starting with a capital char + 2 chars + space + num
