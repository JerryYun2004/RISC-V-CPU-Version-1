#!/usr/bin/env python3
"""Convert a raw little-endian RV32 binary into one 32-bit word per line hex.

Usage:
  python3 tools/bin_to_hex.py input.bin output.hex
"""
from __future__ import annotations

import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) != 3:
        print("Usage: python3 tools/bin_to_hex.py input.bin output.hex", file=sys.stderr)
        return 2

    in_path = Path(sys.argv[1])
    out_path = Path(sys.argv[2])

    data = in_path.read_bytes()
    if len(data) % 4 != 0:
        data += b"\x00" * (4 - (len(data) % 4))

    lines = []
    for i in range(0, len(data), 4):
        word = int.from_bytes(data[i:i + 4], byteorder="little", signed=False)
        lines.append(f"{word:08x}")

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text("\n".join(lines) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
