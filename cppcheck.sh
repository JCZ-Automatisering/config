#!/bin/sh

CPPCHECK=${CPPCHECK:-cppcheck}

echo
echo "Running cppcheck version:"
${CPPCHECK} --version
echo

TMP=$(mktemp)
echo "${CPPCHECK} \\" > ${TMP}
cat >> ${TMP} << "EOF"
    --std=c++11 \
    --xml \
    --inline-suppr \
    --quiet \
    --force \
    -j $(nproc) \
    --enable=all \
    --suppress=missingIncludeSystem \
    --suppress=useStlAlgorithm \
    -I src \
    src/
EOF

cat ${TMP}
chmod +x ${TMP}
/bin/bash ${TMP} 2> build/cppcheck.xml
R=$?
rm ${TMP}
exit ${R}
