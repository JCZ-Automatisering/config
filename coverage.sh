#!/bin/sh

DEFAULTS="--exclude-unreachable-branches --exclude-throw-branches --gcov-ignore-parse-errors"
EXCLUDES="-e \"test*\" -e \"/tmp*\" -e \"build*\""

eval gcovr -k ${DEFAULTS} --branches ${EXCLUDES} --xml-pretty -r . -o build/coverage.xml > /dev/null &
G_PID=$!
eval gcovr -k ${DEFAULTS} --branches ${EXCLUDES} -r . --html --html-details -o build/gcovr-report.html
RESULT=$?
wait ${G_PID}

find . -name "*.gcov" | xargs rm -f

exit ${RESULT}

