#!/usr/bin/env python3
"""Convert a little-endian RISC-V binary into readmemh 32-bit word hex.

Input .bin bytes from objcopy are little-endian instruction/data bytes.
The simple Verilator memory model expects one 32-bit instruction/data word per
line, written in normal 8-hex-digit order, e.g. bytes 93 00 50 00 become
00500093.
"""

from __future__ import annotations

import argparse
from pathlib import Path


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("input_bin", type=Path)
    parser.add_argument("output_hex", type=Path)
    args = parser.parse_args()

    data = args.input_bin.read_bytes()
    if len(data) % 4 != 0:
        data += b"\x00" * (4 - (len(data) % 4))

    args.output_hex.parent.mkdir(parents=True, exist_ok=True)
    with args.output_hex.open("w", encoding="utf-8") as f:
        for i in range(0, len(data), 4):
            word = int.from_bytes(data[i : i + 4], byteorder="little", signed=False)
            f.write(f"{word:08x}\n")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
