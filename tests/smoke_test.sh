#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror \
  "$ROOT/src/main.cpp" -o "$TMP/grade-calculator"
printf '9\n8\n7\n10\n8\n9\n8\n7\n18\n20\n35\n' |
  (cd "$TMP" && ./grade-calculator) > "$TMP/output.txt"
grep -q 'Weighted percentage: 85.50%' "$TMP/output.txt"
grep -q 'Letter grade: A' "$TMP/output.txt"
echo 'PASS: weighted grade calculator smoke test'
