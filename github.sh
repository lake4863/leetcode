#!/usr/bin/env bash

NUM=${1?Error: no leetcode question number given!}
COMMIT=${2:-$(date)}

# add copy paste feature later
<<COMMENT
    touch lc_${NUM}.cpp

COMMENT

git config pull.revase false #merge (the default strategy)
#git pull
git add lc_$NUM.cpp
git commit -m "$COMMIT"
git push
