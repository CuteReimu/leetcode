# Read from the file file.txt and print its transposed content to stdout.
awk '{for(i=1;i<=NF;i++)a[NR,i]=$i}END{for(j=1;j<=NF;j++)for(k=1;k<=NR;k++) printf k==NR?a[k,j] RS:a[k,j] FS}' file.txt
