cat file.txt | sed -n '10p'
sed -n '10p' file.txt
awk 'NR==10' file.txt