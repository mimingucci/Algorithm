#!/usr/bin/env python3
import sys
import re
from pathlib import Path

# Tracks which headers we’ve already expanded
seen = set()

def expand(path: Path) -> str:
    path = path.resolve()
    if path in seen:
        return ""               # skip duplicates
    seen.add(path)

    code = []
    for line in path.read_text().splitlines():
        # skip header-guard pragmas
        if line.strip() == "#pragma once":
            continue
            
        m = re.match(r'\s*#include\s+"(.+\.hpp)"', line)
        if m:
            # found a user header; inline it
            header = (path.parent / m.group(1)).resolve()
            code.append(f"// BEGIN {m.group(1)}")
            code.append(expand(header))
            code.append(f"// END   {m.group(1)}")
        else:
            code.append(line)
    return "\n".join(code)

def main():
    if len(sys.argv) != 3:
        print("Usage: flatten.py <input.cpp> <output.cpp>", file=sys.stderr)
        sys.exit(1)

    inp = Path(sys.argv[1])
    out = Path(sys.argv[2])

    merged = expand(inp)
    out.write_text(merged)
    print(f"Written flattened file to {out}")

if __name__ == "__main__":
    main()
