total=0
for file in `ls`
do
    if test -f $file
    then
        if [ "${file##*.}" = "cpp" ] || [ "${file##*.}" = "h" ];
        then
            
            count=$(sed -n '$=' $file)
            echo "$file has $count"
            let total=total+count
        fi
    fi
done
echo $total