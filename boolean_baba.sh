#!/bin/sh
set -o errexit nounset pipefail xtrace

#Linear Congruential Generator
random() {
	SEED="$(( (1103515245 * ${SEED:-$(date +%s)} + 12345) % (1 << 31) ))"
	echo $SEED
}
EXIT() {
    echo poitu varren
    return 1
}
trap EXIT 0
SIGABRT() {
    echo SIGABRT
}
trap SIGABRT SIGABRT
SIGALRM() {
    echo SIGALRM
}
trap SIGALRM SIGALRM
SIGBUS() {
    echo SIGBUS
}
trap SIGBUS SIGBUS
SIGCHLD() {
    echo SIGCHLD
}
trap SIGCHLD SIGCHLD
SIGCONT() {
    echo SIGCONT
}
trap SIGCONT SIGCONT
SIGFPE() {
    echo SIGFPE
}
trap SIGFPE SIGFPE
SIGHUP() {
    echo SIGHUP
}
trap SIGHUP SIGHUP
SIGILL() {
    echo SIGILL
}
trap SIGILL SIGILL
SIGINT() {
    echo SIGINT
}
trap SIGINT SIGINT
SIGKILL() {
    echo SIGKILL
}
trap SIGKILL SIGKILL
SIGPIPE() {
    echo SIGPIPE
}
trap SIGPIPE SIGPIPE
SIGQUIT() {
    echo SIGQUIT
}
trap SIGQUIT SIGQUIT
SIGSEGV() {
    echo SIGSEGV
}
trap SIGSEGV SIGSEGV
SIGSTOP() {
    echo SIGSTOP
}
trap SIGSTOP SIGSTOP
SIGTERM() {
    echo SIGTERM
}
trap SIGTERM SIGTERM
SIGTSTP() {
    echo SIGTSTP
}
trap SIGTSTP SIGTSTP
SIGTTIN() {
    echo SIGTTIN
}
trap SIGTTIN SIGTTIN
SIGTTOU() {
    echo SIGTTOU
}
trap SIGTTOU SIGTTOU
SIGUSR1() {
    echo SIGUSR1
}
trap SIGUSR1 SIGUSR1
SIGUSR2() {
    echo SIGUSR2
}
trap SIGUSR2 SIGUSR2
SIGPROF() {
    echo SIGPROF
}
trap SIGPROF SIGPROF
SIGSYS() {
    echo SIGSYS
}
trap SIGSYS SIGSYS
SIGTRAP() {
    echo SIGTRAP
}
trap SIGTRAP SIGTRAP
SIGURG() {
    echo SIGURG
}
trap SIGURG SIGURG
SIGVTALRM() {
    echo SIGVTALRM
}
trap SIGVTALRM SIGVTALRM
SIGXCPU() {
    echo SIGXCPU
}
trap SIGXCPU SIGXCPU
SIGXFSZ() {
    echo SIGXFSZ
}
trap SIGXFSZ SIGXFSZ

echo "Baba($$): Un kelvigal ah kel.?"
trap "" 2
while true
do
    printf 'You: '
    read line
    sleep 0.5
    if [ $(($(random) % 2)) = 0 ]
    then echo 'Baba: Aamam.'
    else echo 'Baba: Illai.'
    fi
done
