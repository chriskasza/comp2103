#!/bin/bash

# directory of assignment currently working on
wd=a08

# a name for the session
SESSION=comp2103

# start session
tmux -2 new-session -d -s $SESSION

# change to assignment directory and list files
tmux send-keys "cd $wd" C-m
tmux send-keys "ls -la" C-m

# create new pane to right of original (pane 0)
tmux split-window -h
tmux send-keys "cd $wd" C-m
tmux send-keys "ls -la" C-m

# create new pane below pane 1
tmux split-window -v
# change to the examples directory and list files
tmux send-keys "cd c-programs" C-m
tmux send-keys "ls" C-m

# change focus to pane 0
tmux select-pane -t 0

# Attach to session
tmux -2 attach-session -t $SESSION
