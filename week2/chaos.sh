#!/bin/sh

rm -f foo.txt
#echo "Press [CTRL+C] to stop.."

#while :
#do
  ./simple_writer "foo.txt" "Life is good" & PIDW1=$!
  ./simple_writer "foo.txt" "muhaha" yes & PIDW2=$!
  ./simple_writer "foo.txt" "oh no, not again!" yes & PIDW3=$!
  ./simple_reader "foo.txt" & PIDR1=$!

  wait $PIDW1
  wait $PIDW2
  wait $PIDW3
  wait $PIDR1

#  sleep 2
#  echo "\n\nnext try\n\n"
#done