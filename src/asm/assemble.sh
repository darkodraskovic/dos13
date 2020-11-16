source_files=("test" "hello" "hello2")

for val in ${source_files[@]}; do
    make ${val}.o
    echo $val
done
