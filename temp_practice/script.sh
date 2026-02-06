#!/bin/bash

# -------------------------------
# Check input argument
# -------------------------------
if [ $# -ne 1 ]; then
    echo "Usage: ./script.sh <number_of_commits>"
    exit 1
fi

COMMITS=$1

# -------------------------------
# Random C++ filename
# -------------------------------
CPP_FILE="auto_generated.cpp"

# -------------------------------
# Function to generate random C++ code
# -------------------------------
generate_cpp_code() {
cat <<EOF
#include <iostream>
using namespace std;

// Auto-generated code
// Random seed: $RANDOM

int randomFunction$RANDOM() {
    int x = $((RANDOM % 100));
    int y = $((RANDOM % 100));
    return x + y;
}

int main() {
    cout << "Random output: " << randomFunction$RANDOM() << endl;
    return 0;
}
EOF
}

# -------------------------------
# Main loop
# -------------------------------
for ((i=1; i<=COMMITS; i++)); do
    echo "Commit $i / $COMMITS"

    # Overwrite the cpp file with random content
    generate_cpp_code > "$CPP_FILE"

    # Optional small delay to avoid identical timestamps
    sleep 1

    # Git add, commit, and push
    git add .
    git commit --allow-empty-message -m ""
    git push

done

echo "Done: $COMMITS commits and pushes completed."
