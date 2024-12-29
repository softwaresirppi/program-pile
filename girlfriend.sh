#!/bin/sh
echo 'Girlfriend: say sorry :('
while
    printf 'You: '; read reply
    sleep 0.5
    printf 'Girlfriend: '
    case $reply in
        sorry) echo 'huh? couldnt hear you -_-';;
        SORRY) echo 'why you screaming?! you no longer love me.';;
        [sS][Oo][Rr][Rr][Yy]) echo 'is this a joke to you? break up.';;
        SORRY!) echo 'Okay... manichten.'; false;;
        *) shuf -n1 <<- done
Hmm
Haan
Ahaan
Mm
Ok
Okay
K
done
;;
    esac
do :
done
