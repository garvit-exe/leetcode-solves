# Read from the file file.txt and output the tenth line to stdout.
if [ $(wc -l < file.txt) -ge 10 ]; then
    head -n 10 file.txt | tail -n 1
fi
